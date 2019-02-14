#!/bin/bash

cat  /dev/null > output1.txt
cat  /dev/null > output2.txt
cat  /dev/null > output3.txt
cat  /dev/null > output4.txt


a=0
while read -r line
do
 ((num=2#$line)) #reference https://www.jb51.net/article/57943.htm
 remain=` expr $num % 3 `
#  if [ $remain == $a ]
if [ X"$remain" = X"$a" ]
 then
    echo $line >> output1.txt
 fi
done < Lab5_partII_Q1_golden_output.txt



grep -E '(((pickup|pick-up|pick up)( \b[A-Za-z0-9-]+\b){0,2})[ ]?red)|(red (\b[A-Za-z0-9-]+\b ){0,2}(pickup|pick-up|pick up)) truck (\b[A-Za-z0-9-]+\b ){0,}\$\d+' <  Lab5_partII_Q2_input.txt >> output2.txt


grep -E '^[0-9]{2}((\/[A-Z][a-z]{2}\/)|(\-[A-Z][a-z]*\-)|(\.[A-Z][a-z]*\.))[0-9]{4}' < Lab5_partII_Q3_input.txt >> output3.txt



# echo ee_classes.html | grep -Po '<<div class="course-info expandable" id=EE"\K[[:digit:]]*' 
# sed -n 's/.*<div class="course-info expandable" id="\([^"]*\).*/\1/p'   |  >> output4.txt 
# while read -r line
# do
# echo $line | grep -Po '<<div class="course-info expandable" id=EE"\K[[:digit:]]*(,[[:digit:]]+){0,1}'  >> output4.txt
# done < ee_classes.html
# echo '<script>document.getElementById("test-summary").innerHTML = "<strong>Test Pages:</strong> 1 right, 0 wrong, 0 ignored, 0 exceptions&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;' | sed -ne 's/.*"test-summary".* \([0-9][0-9]* right,[^&].*exceptions\)&nbsp.*/\1/p'

# sed -n 's/.*href="\([^"]*\).*/\1/p' ee_classes.html >> output4.txt
