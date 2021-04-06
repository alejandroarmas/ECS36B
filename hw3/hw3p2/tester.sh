#! /bin/bash
# Alejandro Armas 
# 915110085

echo -e "Beginning tests..."

for i in {1..11}
do
    echo -e "test$i.in: "
    ./checkpack < test$i.in > test_alejandro_armas_$i.svg
    echo -e "done. "
done

echo -e "Verifying accuracy..."

for i in {1..11}
do
    diff test_alejandro_armas_$i.svg test$i.svg
done

echo -e "done. "