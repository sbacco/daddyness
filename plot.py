#!/usr/bin/env python3

import matplotlib.pylab as plt
import numpy as np

x=np.linspace(0,20,2000)
f=np.log(9*(x+1))/np.log(2) + np.log(9*(x+1)/2)/np.log(10)
# First time N crosses f(N)
c = next(val for i, val in enumerate(x) if f[i] < x[i])

plt.plot(x,x,label='$N$')
plt.plot(x,f,label='$f(N)$')
plt.axvline(x = c,linestyle=':', label='$N=$'+str(c))
plt.xlabel('$N$')
plt.legend()
plt.show()

