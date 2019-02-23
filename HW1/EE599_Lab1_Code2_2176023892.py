import random

fp = open('input_code2.txt', 'r')
fp1 = open('output_code2.txt', 'w')
linesfp = fp.readlines()
seednum = int(linesfp[0])
count = int(linesfp[1])
lowerlimits = int(linesfp[2])
upperlimits = int(linesfp[3])
result = []
random.seed(seednum)
i = 0
fp1.write("counter integers\n")

if count != 0 and upperlimits - lowerlimits > 0:
    while i < count:
        # generate random integer [lowerlimits, upperlimits]
        result.append(random.randint(lowerlimits, upperlimits))
        i += 1
    # transfer list to set to eliminate duplicated elements
    newset = set(result)
    # then save to lists to sort

    newlist = [element for element in newset]
    newlist.sort()

    num = 5
    countnum = 1
    # if countnum is larger than boudary, set it as the maximun possible numbers

    str1 = ""
    # output into string
    if count != 0 and upperlimits - lowerlimits > 0:
        for n in newlist:
            if countnum % 5 == 1:
                str1 += str(countnum) + ": "
            if countnum < len(newset) and countnum % 5 != 0:
                str1 += str(n) + ','
            else:
                str1 += str(n)
            if (countnum % 5 == 0 and countnum != 0) or countnum == len(newlist):
                str1 += '\n'
            countnum += 1
        fp1.write(str1)



