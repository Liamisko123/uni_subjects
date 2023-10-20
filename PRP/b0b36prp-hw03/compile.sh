clang -Wall -pedantic -Werror -std=c99 main.c -o main
#for i in `seq 1 7`
#do

./generate_solutions.sh
for i in `seq 1 7`
do
PUB=data/pub0$i
MYFILE=myfiles/pub0$i
./main < $PUB.in > $MYFILE.out 2>$MYFILE.err
diff $PUB.out $MYFILE.out
diff $PUB.err $MYFILE.err
echo $MYFILE
done
