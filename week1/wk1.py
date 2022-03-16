import matplotlib.pyplot as plt
from matplotlib import rcParams
import numpy as np


a = []

    
    

        
data = np.loadtxt("text.txt")


plt.grid(True)
plt.hist(data, bins = 100)



plt.show()

