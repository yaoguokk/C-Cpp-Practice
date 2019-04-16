import networkx as nx
import numpy as np
import matplotlib.pyplot as plt

import random
import os


# while(True):
#     x = input('input the number of node <= 10 : ')
#     if x>10:
#         print "wrong input"
#     else:
#         break
#generate edge matrix for all possible
x = 6
connect_table = []
for i in range(x-1):
    row = []
    for j in range(i,x-1):
        row.append([i,j+1])
    connect_table.append(row)


#flattern the table and random choose random number of edge without replacement
connect_list = []
for i in connect_table:
    for j in i:
        connect_list.append(j)


# the maximal number of edge, the number of random edge shoule be less than the maximum
max_edge = x*(x-1)/2
edge_num = random.randint(x,max_edge)

choose = random.sample(connect_list,edge_num)
# print (choose)

file = open("input1_1.txt","w")
file.write("%s\n" % x)
for i in range(len(choose)-1):
    file.write("%s,%s, " % (choose[i][0],choose[i][1]))
file.write("%s,%s\n"% (choose[-1][0],choose[-1][1]))
file.close()

def run(cppfilename, aoutname):
    os.system('g++ ' + cppfilename + ' -o ' + aoutname)
    os.system('./'+aoutname+' input1_1.txt')

def transfer_to_matrix(choose,x,matrix):
    import numpy as np
    for i in range(x):
        row=[]
        for j in range(x):
            if([j,i] in choose):
                row.append(1)
            elif([i,j] in choose):
                row.append(1)
            else:
                row.append(0)
        matrix.append(row)

matrix = []
transfer_to_matrix(choose,x,matrix)
# for i in matrix:
#     print i
# print "\n"

filename = "p1_code.cpp"
aoutname = "a.out"
run(filename,aoutname)

adj = np.array(matrix)
G = nx.from_numpy_array(adj)

nx.draw(G, with_labels=True, font_weight='bold')

plt.show()
