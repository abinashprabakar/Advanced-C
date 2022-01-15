#!/bin/bash

echo "Enter the Password : "

while [ true ]
do
	read -s pas		# -s used to read password in silent mode 

	if [ "$pas" = "1234" ]	# check string pas is 1234 or not
	then
		echo "Password Matched"
		break;
	fi
	echo "Incorrect password"
done

