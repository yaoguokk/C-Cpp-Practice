
printf "13\n51\n-19\n19\n" > input_code2.txt
python EE599_Lab1_Code2_*
cat output_code2.txt > output.msa

printf "31\n1000\n10\n20\n" > input_code2.txt
python EE599_Lab1_Code2_*
cat output_code2.txt >> output.msa

printf "13\n10\n0\n2000\n" > input_code2.txt
python EE599_Lab1_Code2_*
cat output_code2.txt >> output.msa

printf "31\n0\n0\n1\n" > input_code2.txt
python EE599_Lab1_Code2_*
cat output_code2.txt >> output.msa

diff output.msa output_script_code2_golden.txt > result.msa
if [ -s result.msa ]
then
	echo "Test Failed!"
else
	echo "Test Passed!"
fi

# rm input.msa
rm output.msa
rm result.msa
