i=0
for file in *.png; do
    mv -- "$file" "hld_$i.png"
    i=$((i + 1))
done