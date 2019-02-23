
# EE599-Lab6
# DO NOT CHANGE THE FIRST 10 LINES
# DO NOT INCLUDE ANY OTHER PACKAGE
import random
import os
import time
PARAM = {"seed":26, "size":10000, \
        "unsortedFile":"input.txt", "sortedFile":"output.txt", \
        "range": [0, 1000000], "alg":"quickSort"}

# TASKS: quickSort bubbleSort
# Seed your random generator with PARAM["seed"]
# Generate PARAM["size"] integers in range PARAM["range"]
# Write the random integers in PARAM["unsortedFile"]
# Don't forget to close the file (potential bug here!)
# Each integer should be in a separate line
# Compile your C++ code (use "os" package)
# Start a timer
# Run your C++ code with the correct arguments
# Print your timer (in sec) in a single line, that's the only thing you should print
# Write you code below: 

random.seed(PARAM["seed"])
name=PARAM["unsortedFile"]
fp = open(name,'w')
i=0
while(i<PARAM["size"]):
    m=random.randint(PARAM["range"][0],PARAM["range"][1])
    # print >> fp,m
    fp.write(str(m))
    fp.write("\n")
    i=i+1
fp.close()
start = time.time()

os.system('g++ main.cpp sort.cpp -o test')
os.system('./test '+PARAM["unsortedFile"]+" "+PARAM["sortedFile"]+" "+str(PARAM["size"])+" "+PARAM["alg"])

end = time.time()
print(end-start)
