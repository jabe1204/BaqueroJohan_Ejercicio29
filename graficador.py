import numpy as np
import matplotlib.pylab as plt


data = np.loadtxt("datos.dat")

plt.figure(figsize=(12,4))

plt.subplot(1,3,1)
plt.imshow(data)

plt.subplot(1,3,2)
for i in range(30):
	plt.plot(data[:,0],data[:,i+1])
	
plt.savefig("difusion.png")

