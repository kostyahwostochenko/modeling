import matplotlib.pyplot as plt
from matplotlib import rcParams
import numpy as np

data = np.loadtxt("average_small.txt")
a = np.linspace(0, 20, 1000)

b = np.zeros(1000)

i = 0

while i < 1000:
    b[i] = data[i//50]
    i += 1
    


#fig = plt.figure()
#ax = fig.add_subplot(111)
#ax.set_xlabel(r'Время')
#ax.set_ylabel(r'Средняя энергия тяжёлых')
#plt.grid(True)
#plt.plot(a,b)
#plt.show()

t = np.loadtxt("output_data.txt")
plt.grid(True)
plt.hist(t, bins = 70)
plt.show()
