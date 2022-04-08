import matplotlib.pyplot as plt
import numpy as np
import pygame


is_running = True

fps = 60
delay_ms = 1000 // fps
height = 800
width = 1400
y = height // 2

black = (0, 0, 0)
green = (0, 255, 0)
yellow = (255, 255, 0)

params = np.loadtxt("text1.txt")

n = int(params[0])
radius = float(params[1])
length = float(params[2])
scale = width / length

r = int(radius * scale)
right_border_x = int(length * scale)

left_border_up = (0, 0)
right_border_up = (right_border_x, 0)
left_border_down = (0, height)
right_border_down = (right_border_x, height)



data = np.loadtxt("text.txt")
time = []
dt = 0.01

        
a = []


for i in range(len(data[:, 0])-1):
    t = data[:, 0][i]
    while t < data[:, 0][i+1]:
        time.append(t)
        t = t + dt
        
k = 1
while k < len(data[0,:])-1:
    b = []
    for i in range(len(data[:, 0])-1):
        v = data[:, k+1][i]
        x = data[:, k][i]
        t = data[:, 0][i]
        t_new = 0
        while t < data[:, 0][i+1]:
            b.append(x + v*t_new)
            t_new = t_new + dt
            t = t + dt
    k = k + 2
    a.append(b)


size = [width, height]
screen = pygame.display.set_mode(size)


#for i in range(len(a)):
#    plt.plot(time, a[i])
#plt.show()


for frame_number in range(len(time)):
    
    if is_running:
        pygame.draw.line(screen, green, left_border_up, left_border_down)
        pygame.draw.line(screen, green, right_border_up, right_border_down)
    
        for i in range(len(a)):
            x = int(a[i][frame_number] * scale)
            center = (x, y)

            if i < n:
                color = yellow
            else:
                color = green
            pygame.draw.circle(screen, color, center, r)
        pygame.display.update()
        screen.fill(black)
        pygame.time.delay(delay_ms)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                is_running = False
                pygame.quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    is_running = False
                    pygame.quit()
pygame.quit()