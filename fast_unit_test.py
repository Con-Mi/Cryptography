# Fermat primality test

import numpy as np

n = 1105
my_list_witnesses = []
my_list_liars = []
"""
for i in range(2, n-1):
	if i**(n-1) % n == 1:
		my_list_liars.append(i)
	else:
		my_list_witnesses.append(i)

if len(my_list_witnesses) != 0:
	print "Smallest Fermat witness of compositeness:"
	print np.min(my_list_witnesses) 
	print "Smallest Fermat Liars: "
	print np.min(my_list_liars)
else:
	print("n = %d is a Prime number") %n
"""
b = 1
c = 1100
answer = 0
idx = 0

for i in range(0, n-1):
	answer = (b*c)%n
	b = answer	
	idx += 1
	print b, idx

print "\n"
print "Final answer of modular exponentiation"
print answer 


	
