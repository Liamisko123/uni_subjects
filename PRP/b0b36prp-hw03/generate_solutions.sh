#!/bin/sh

HW=03
PROGRAM=./b0b36prp-hw$HW-genref
MY_PROGRAM=./main


if [ "$1" = "-osx" ]
then
   echo "Build for osx has been selected."
   PROGRAM=./b0b36prp-hw$HW-genref-osx
fi

mkdir -p files
for i in `seq 1 4`
do
   PROBLEM=files/hw$HW-$i
   $PROGRAM -generate > $PROBLEM.in 2>/dev/null
   $PROGRAM < $PROBLEM.in > $PROBLEM.out 2>$PROBLEM.err
done

echo ""
echo "Generate and solve optional + mandatory assignments"

for i in `seq 1 4`
do
   PROBLEM=`printf "files/hw%sopt-$i" $HW`
   $PROGRAM -generate -optional > $PROBLEM.in 2>/dev/null
   $PROGRAM < $PROBLEM.in > $PROBLEM.out 2>$PROBLEM.err
done
