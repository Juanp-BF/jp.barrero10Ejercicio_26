import numpy as np
import matplotlib.pyplot as plt
import os

a = open('archivo.txt', 'r')

values = a.read()
a.close()

def split(n_splits):
    splitsize = len(values)//n_splits
    out = 'Split' + str('n_splits')
    write = open(out, 'w')
    write.write(vals[0:splitsize])
    write.close()

split = np.array[10,20, 50, 100]
for i in range(len(split)):
    split(i)
