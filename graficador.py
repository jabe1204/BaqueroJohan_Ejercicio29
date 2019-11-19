import numpy as np
import matplotlib.pylab as plt


data = np.loadtxt("datos.dat")

y = data[:,0]
x1 = data[:,1]
x2 = data[:,2]
x3 = data[:,3]
x4 = data[:,4]
x5 = data[:,5]
x6 = data[:,6]
x7 = data[:,7]

plt.plot(x1,y)
plt.plot(x2,y)
plt.plot(x3,y)
plt.plot(x4,y)
plt.plot(x5,y)
plt.plot(x6,y)
plt.plot(x7,y)

plt.savefig("difusion.png")

