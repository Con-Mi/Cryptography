# Calculating factorial with stirling approximation 

import numpy as np
import math

H = 4096.0
n = 100.0
prob = 1.0
tmpr_val = H - (n - 1)

for i in range(int(n)):

	prob *= tmpr_val/H
	tmpr_val += 1.0
	print tmpr_val
	
print 1-prob


