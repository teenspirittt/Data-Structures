from math import log2
import matplotlib.pyplot as plt
import numpy as np



elems = [10, 100, 500, 1000, 2000, 3000, 4000, 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 75000, 100000]


#ord
ord_teor = elems[0:len(elems)]
for i in range(len(elems)):
    ord_teor[i] = elems[i]/2 
ord_insert = [7.2, 43.92, 201.28, 413.406, 826.291, 1241.19, 1625.02, 1971.19, 4007.02, 5989, 7870, 9710, 11962, 13907, 15485, 17020, 18550, 20185, 26774, 36284]
ord_delete = [8, 33.64, 200, 416, 798, 1217, 1610, 1912, 3843, 5721, 7199, 8878, 11509, 13316, 13506, 13956, 14419, 14917, 17768, 23369]
ord_search = [5.2, 40, 199, 417, 782, 1220, 1597, 1947, 3895, 5670, 7205, 8888, 11404, 13332, 13554, 13982, 14347, 14919, 17781, 23482]


#random
rand_teor = elems[0:len(elems)]
for i in range(len(elems)):
    rand_teor[i] = 1.39*log2(elems[i]) 
rand_insert = [3.2, 6.84, 10.184, 11.694, 13.031, 13.8313, 14.3105, 14.9128, 16.2404, 17.0663, 17.6034, 18.0371, 18.4489, 18.7731, 19.0023, 19.2275, 19.4015, 19.5915, 20.144, 21.9524]
rand_delete = [3.2, 7.6, 10.888, 12.068, 13.523, 14.5473, 14.922, 15.484, 16.8266, 17.6803, 18.2203, 18.661, 19.0183, 19.3561, 19.5999, 19.7823, 19.9997, 20.1597, 20.7794, 22.581]
rand_search = [1.8, 5.28, 8.752, 10.098, 11.504, 12.3333, 12.884, 13.1496, 14.5094, 15.344, 15.9039, 16.1689, 16.6319, 17.0922, 17.2025, 17.3019, 17.4042, 17.5619, 18.0477, 19.8509]

fig = plt.figure()
plt.ylabel('Nodes number')
plt.xlabel('Elements number')
plt.semilogy(elems, ord_teor, label='teoretical')
plt.semilogy(elems, ord_insert, label='insert')
plt.semilogy(elems, ord_delete, label='delete')
plt.semilogy(elems, ord_search, label='search')
plt.grid()
plt.legend()
plt.savefig('lord.png')

fig = plt.figure()
plt.ylabel('Nodes number')
plt.xlabel('Elements number')
plt.semilogy(elems, rand_teor, label='teoretical')
plt.semilogy(elems, rand_insert, label='insert')
plt.semilogy(elems, rand_delete, label='delete')
plt.semilogy(elems, rand_search, label='search')
plt.grid()
plt.legend()
plt.savefig('lrand.png')
