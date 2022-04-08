import matplotlib.pyplot as plt
from matplotlib import rcParams
import numpy as np
import pygame


      
data = np.loadtxt("text.txt")

a =[]
b = []
c = []
v1 = []
v2 = []
dt = 0.001

time  = []
coord = []
velocity = []

for i in range(len(data[:, 0])-1):
    t = data[:, 0][i]
    while t < data[:, 0][i+1]:
        time.append(t)
        t = t + dt


for i in range(len(data[:, 0])-1):
    v = data[:, 2][i]
    x = data[:, 1][i]
    t = data[:, 0][i]
    t_new = 0
    while t < data[:, 0][i+1]:
        a.append(t)
        b.append(x + v*t_new)
        t_new = t_new + dt
        t = t + dt


for i in range(len(data[:, 0])-1):
    v = data[:, 4][i]
    x = data[:, 3][i]
    t = data[:, 0][i]
    t_new = 0
    while t < data[:, 0][i+1]:
        c.append(x + v*t_new)
        t_new = t_new + dt
        t = t + dt

for i in range(len(data[:, 0])-1):
    v = data[:, 4][i]
    t = data[:, 0][i]
    while t < data[:, 0][i+1]:
        v1.append(v)
        t = t + dt

plt.grid(True)

#plt.plot(data[:, 0], data[:, 1], '.-')
#plt.plot(data[:, 0], data[:, 2], '.-')
#plt.plot(data[:, 0], data[:, 3], '.-')

#plt.plot(a, b, '.-', markersize = 1)
#plt.plot(a, c, '.-', markersize = 1)
plt.plot(time, v1, '.-', markersize = 1)

#plt.plot(data[:, 0], data[:, 3], '.-')
#plt.plot(data[:, 0], data[:, 4], '.-')
#plt.plot(data[:, 0], data[:, 6], '.-')



plt.show()