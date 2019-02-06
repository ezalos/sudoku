#!/bin/bash

i=0
echo "Nombre de tests"
read nb
name=1

while true; do
    read -p "Do you want random generated" yn
    case $yn in
    [Yy]* ) value=1; break;;
    [Nn]* ) value=0; break;;
    * ) echo "Please answer yes or no, no joke this time";;
    esac
done

if [[ $value = 1 ]]; then
	while [[ $i -le "$nb" ]]; do
		name=$[ ( RANDOM % 10000) + 1]
		echo './sudoku tests/magictour/10k/'$name''
		./sudoku tests/magictour/10k/"$name"
		i=$[$i + 1]
	done
else
	while [[ $name -le "$nb" ]]; do
		echo './sudoku tests/magictour/10k/'$name''
		./sudoku tests/magictour/10k/"$name"
		name=$[$name + 1]
	done
fi
