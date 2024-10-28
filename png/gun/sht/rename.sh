i=0
for file in *.png; do
    mv -- "$file" "sht_$i.png"
    i=$((i + 1))
done