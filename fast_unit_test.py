# Fermat primality test

import numpy as np

n = 17
my_list_witnesses = []
my_list_liars = []

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
	print("n = %d is a Prime") %n
