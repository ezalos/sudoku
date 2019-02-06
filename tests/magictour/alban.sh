#!/bin/sh

i=9
name=1
j=1
echo "Nom du fichier?"
read file
echo "Nombre de tests?"
read test_nb
ln_nb="$test_nb * 10"

sed 's/.\{9\}/&\ /g' "$file" | perl -0777 -pe 's { } {$&\n}g' > tmp

while [[ $i -lt $ln_nb ]]; do
    sed -n ""$j","$i"p" tmp > hardest/"$name"
    i=$[$i + 10]
    j=$[$i - 8]
    name=$[$name + 1]
done < tmp
