#!/bin/bash

echo "Enter the total numbers : "
read n

i=1					# initialize i as 1
sum=0					# initialize sum as 0

echo "Enter the numbers : "
while [ $i -le $n ]			# checking i is less than or equal to n
do
	read num			# if i <= n, get input from user
	sum=$((sum+num))		# add sum and number got from the user
	i=$((i+1))			# increment i
done

average=$(echo $sum / $n | bc -l)	# divide total sum by total number size to get average
					# bc --> command line calculator   l --> math library

#echo $average				# print average

printf "%0.2f\n" $average		# to print only 2 floating numbers

