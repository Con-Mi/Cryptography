#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

unsigned int toInt(char c);
void getKey(std::vector<unsigned char> *first_block, std::vector<unsigned char> *encrypted, std::vector<unsigned char> *key);
std::vector<unsigned char> xor12(std::vector<unsigned char> a, std::vector<unsigned char> b);

/**
 * Recover the encrypted message, knowing the first block of plain text. The
 * encrypted text is of the form IV | C0 | C1 | ... where each block is 12 bytes
 * long.
 **/
std::string recoverMessage(std::vector<unsigned char> first_block, std::vector<unsigned char> encrypted) {
	std::cout << "recoverMessage() \n";
	std::vector<unsigned char> result;
	// Find key
	std::vector<unsigned char> key;
	std::vector<unsigned char> c1;
	for (int i = 12; i < 24; i++)
		c1.push_back(encrypted[i]);
	std::cout << "C1 stored \n";
	key = xor12(first_block, encrypted);
	key = xor12(key, c1);
	std::cout << "Key found \n";
	int nbrOfBlocks = encrypted.size()/12;
	std::vector<unsigned char> prevC = encrypted;
	std::vector<unsigned char> currentC;
	std::cout << "Big loop start \n";
	for (int i = 1; i < nbrOfBlocks; i++) {
		// Compute the current C
		for (int j = 0; j < 12; j++) 
			currentC[j] = encrypted[i * 12 + j];
		std::cout << "Currenct c computed \n";
		std::vector<unsigned char> M = xor12(prevC, currentC);
		M = xor12(M, key);
		std::cout << "M done \n";
		// Add plain text
		for (int k = 0; k < 12; k++)
			result.push_back(M[k]);
		// Update prevC
		std::cout << "Message stored \n";
		prevC = currentC;
		std::cout << "Old c overrided \n";
	}

  // Work on the arrays (vectors) of bytes (unsigned chars).
  // In the end, construct a string as follows:
  std::string result_str(result.begin(), result.end());
  return result_str;
}

// Helper for parsing.
unsigned int toInt(char c) {
  if (c >= '0' && c <= '9') return      c - '0';
  if (c >= 'A' && c <= 'F') return 10 + c - 'A';
  if (c >= 'a' && c <= 'f') return 10 + c - 'a';
  return -1;
}
  
int main() {
  std::ifstream infile("input.txt");
  std::string line;
  
  std::getline(infile, line);
  
  std::cout<<line<<std::endl;
  std::vector<unsigned char> first_block(line.begin(), line.end());
  
  std::getline(infile, line);
  const char * input = line.c_str();
  const size_t numdigits = std::strlen(input) / 2;
  std::vector<unsigned char> encrypted;
  for (size_t i = 0; i != numdigits; ++i)
    encrypted.push_back(16 * toInt(input[2*i]) + toInt(input[2*i+1]));
  
  std::string message = recoverMessage(first_block, encrypted);
  std::cout << "Recovered message: " << message << std::endl;
  
  return 0;
}

std::vector<unsigned char> xor12(std::vector<unsigned char> a, std::vector<unsigned char> b) {
	std::vector<unsigned char> c;
	for (int i = 0; i < 12; i++) {
		unsigned char tmp = a[i] ^ b[i];
		c.push_back(tmp);
	}
	return c;
}