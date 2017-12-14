#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

unsigned int toInt(char c);
void getKey(std::vector<unsigned char> *first_block, std::vector<unsigned char> *encrypted, std::vector<unsigned char> *key);

/**
 * Recover the encrypted message, knowing the first block of plain text. The
 * encrypted text is of the form IV | C0 | C1 | ... where each block is 12 bytes
 * long.
 **/
std::string recoverMessage(
    std::vector<unsigned char> first_block,
    std::vector<unsigned char> encrypted) {

	std::vector<unsigned char> result;
	unsigned int a = toInt('a');
	// Find key
	//std::vector<unsigned char> key;
	/*bool notDone = true;
	int tmpCounter = 0;
	unsigned char IV;
	unsigned char key;
	unsigned char C1;
	while (notDone) {
		IV = (unsigned char)tmpCounter;
		key = encrypted[0] ^ (first_block[0] ^ IV);
		C1 = key ^ (first_block[0] ^ IV);
		if (C1 == encrypted[0])
			notDone = false;
		tmpCounter++;
	}
	std::cout << C1 << std:: endl;
	//for (int i = 0; i < encrypted.size(); i++) {
	//unsignedchar a = 'h';
	//	result.push_back(a);
	//}
	result.push_back(key);
	result.push_back(C1);
	*/
	std::cout << a << std::endl;
	result.push_back('s');
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

std::vector<unsigned char> xor12(std::vector<unsigned char> *a, std::vector<unsigned char> *b) {
	std::vector<unsigned char> c;
	c.push_back('h');
	return c;
}