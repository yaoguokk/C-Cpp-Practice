echo 12.345 > input.msa
python EE599_Lab1_Code1_* > output.msa < input.msa
echo 1.2 > input.msa
python EE599_Lab1_Code1_* >> output.msa < input.msa
echo -1 > input.msa
python EE599_Lab1_Code1_* >> output.msa < input.msa

diff output.msa output_script_code1_golden.txt > result.msa

if [ -s result.msa ]
then
	echo "Test Failed!"
else
	echo "Test Passed!"
fi

rm input.msa
rm output.msa
rm result.msa
