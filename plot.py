#!/usr/bin/env python3

from matplotlib import pyplot as plt
import numpy as np

RANGE = 16
PRECISION = 2 # decimal places

x=np.linspace(0,RANGE,RANGE*10**PRECISION)
f=np.log(9*(x+1))/np.log(2) + np.log(9*(x+1)/2)/np.log(10)
# First time N crosses f(N)
c = next(val for i, val in enumerate(x) if f[i] < x[i])

plt.plot(x,x,label='$N$')
plt.plot(x,f,label='$f(N)$')
plt.axvline(x = c,linestyle=':', label=f'$N={c:.{PRECISION+1}}$')
plt.xlabel('$N$')
plt.legend()
plt.show()

