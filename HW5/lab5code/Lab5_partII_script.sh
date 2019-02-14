# EE599 - Spring 2019 Shahin Nazarian
# Lab5 partII grading script
# Author: Suofei YU
#

sh Lab5_partII_*.sh

diff output1.txt  Lab5_partII_Q1_golden_output.txt > result1.txt

if [ -s result1.txt ]
then
	echo "Test1 Failed!"
else
	echo "Test1 Passed!"
fi
diff output2.txt  Lab5_partII_Q2_golden_output.txt > result2.txt

if [ -s result2.txt ]
then
	echo "Test2 Failed!"
else
	echo "Test2 Passed!"
fi
diff output3.txt  Lab5_partII_Q3_golden_output.txt > result3.txt

if [ -s result3.txt ]
then
	echo "Test3 Failed!"
else
	echo "Test3 Passed!"
fi
diff output4.txt  Lab5_partII_Q4_golden_output.txt > result4.txt

if [ -s result4.txt ]
then
	echo "Test4 Failed!"
else
	echo "Test4 Passed!"
fi
rm result1.txt
rm result2.txt
rm result3.txt
rm result4.txt







