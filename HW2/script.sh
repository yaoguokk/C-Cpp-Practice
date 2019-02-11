# EE355 - Spring 2019
# Lab2 - shell script
# Shahin Nazarian
# Author: Xuejing Lei

gcc EE599_Lab2_*.c -o code.o
./code.o < input.txt

for i in `seq 1 2`
do
    diff output_p1_m$i.txt output_p1_golden.txt > result$i.txt
    if [ -s result$i.txt ]
	then
		echo "Method $i: Test Failed!"

	else
		echo "Method $i: Test Passed!"
	fi
	rm result$i.txt
done

rm code.o
