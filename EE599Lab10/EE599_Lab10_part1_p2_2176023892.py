import random
import os


# generate edge matrix for all possible

def oneloop(num):
    x = random.randint(5,10)
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
    edge_num = random.randint(x/2,max_edge*4/5)

    choose = random.sample(connect_list,edge_num)

    outputname = "input1_"+str(num)+".txt"

    file = open(outputname,"w")
    file.write("%s\n" % x)
    for i in range(len(choose)-1):
        file.write("%s,%s, " % (choose[i][0],choose[i][1]))
    file.write("%s,%s\n"% (choose[-1][0],choose[-1][1]))
    file.close()


def run(cppfilename,outputname):
    os.system('g++ ' + cppfilename + ' -o ' + "a.out")
    os.system('./a.out ' + outputname)

filename = "p1_code.cpp"
 
for i in range(10):
    oneloop(i)
    outputname = "input1_"+str(i)+".txt"
    run(filename,outputname)
