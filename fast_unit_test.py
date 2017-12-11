# Fermat primality test

import numpy as np
import math

H = 4096.0
n = 100.0

#print math.factorial(H)
prob = 1 - math.exp(-(n*(n)) / (2*H))

print "Calculated answer"
print prob

print "Real answer is"
print  0.547481

print n**2
