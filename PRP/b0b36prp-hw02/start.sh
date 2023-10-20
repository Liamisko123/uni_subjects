clang -Wall -pedantic -Werror -std=c99 main.c -o main
./main < data/pub01.in > program.out 2>program.err
diff -r data/pub01.out program.out
echo $'\nExit status:' $?