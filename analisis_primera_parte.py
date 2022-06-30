import numpy as np
import random
from matplotlib import pyplot as plt
import pandas as pd
import math
from matplotlib.ticker import StrMethodFormatter
import statistics as st

dataL = pd.read_csv('plot_Tiempos_Langevin_N10.txt', sep="	", header=None)
tiemposL=[]
for n in range(len(dataL)):
    tiemposL.append(dataL[1][n])



array=np.array(tiemposL)








plt.title('Histograma Langevin')
plt.ylabel('Repeticiones de Tiempos')
plt.xlabel('Tiempos')


countsL,bin_edgesL = np.histogram(tiemposL,200,density='True',range=(0,4000))
bin_centresL = (bin_edgesL[:-1] + bin_edgesL[1:])/2
plt.scatter(bin_centresL,countsL,marker='.',label='Langevin')




plt.yscale('log')
#plt.xscale('log')
#plt.xlim(500,10000)
plt.axvline(array.mean(), color='b', linestyle='dashed', linewidth=1,label='Media Langevin')
print(array.mean())
plt.legend(loc="upper right")
plt.show()
