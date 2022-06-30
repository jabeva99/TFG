import matplotlib.pyplot as plt
import numpy as np
import matplotlib.animation as animation
from itertools import islice
from matplotlib.colors import ListedColormap, LinearSegmentedColormap

num_lines = sum(1 for line in open('plot_matriz_2D.txt'))
M=[]
m = [20 for i in range(int(num_lines/20))]


n=m


with open('plot_matriz_2D.txt') as file:
    for row_count in m:
        rows = islice(file, row_count) # read `row_count` lines from the file
        rows = [row.split() for row in rows] # split every line in the file on whitespace
        rows = [[int(cell) for cell in row] for row in rows] # convert to int
        M.append(rows) # add to `M`
print(len(M))

matriz=M[1]
def update(i):
    matriz=M[i]
    matrice.set_array(matriz)

fig, ax = plt.subplots()
matrice = ax.matshow(matriz, cmap=plt.cm.Spectral_r, interpolation='none', vmin=0, vmax=13)
plt.xticks(np.arange(-0.5, 49.5, step=1))  # Set label locations.
plt.yticks(np.arange(-0.5, 49.5, step=1))  # Set label locations.
plt.grid()
for tick in ax.xaxis.get_major_ticks():
    tick.tick1line.set_visible(False)
    tick.tick2line.set_visible(False)
    tick.label1.set_visible(False)
    tick.label2.set_visible(False)
for tick in ax.yaxis.get_major_ticks():
    tick.tick1line.set_visible(False)
    tick.tick2line.set_visible(False)
    tick.label1.set_visible(False)
    tick.label2.set_visible(False)

ani = animation.FuncAnimation(fig, update, frames=int(100000), interval=1)
#f = r"/home/helico/Documents/Física/4º de Física/TFG/Segunda parte/animation.gif"
#writergif = animation.PillowWriter(fps=60)
#ani.save(f, writer=writergif)
fvid = r"/home/helico/Documents/Física/4º de Física/TFG/Segunda parte/animation.mp4"
writervideo = animation.FFMpegWriter(fps=60)
ani.save(fvid, writer=writervideo)

plt.show()
# a 2D array with linearly increasing values on the diagonal


