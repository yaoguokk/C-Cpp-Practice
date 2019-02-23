# EE599
# Author: Tommy Trojan
# Lab1 - Code1
# Description:
# Getting input from user
# simple arithmetic calculations
# changing the default setting for printing numbers
variable = input("Please type a number: ")
print "Input number: "
print variable
print "Square: "
print variable*variable
# Complete below
# Print the cube of the variable with three decimal digits
print "Cube: "
print "{0:.3f}".format(variable*variable*variable)
