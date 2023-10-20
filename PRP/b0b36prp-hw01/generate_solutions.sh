#!/bin/sh

HW=01
PROGRAM=./b0b36prp-hw$HW-genref
MYPROGRAM=./main


if [ "$1" = "-osx" ]
then
	echo "Build for osx has been selected."
	PROGRAM=./b0b36prp-hw$HW-genref-osx
fi

mkdir -p files
for i in `seq 1 4`
do
   PROBLEM=files/hw$HW-$i
   PROBLEMSOLVED=myfiles/hw$HW-$i
   $PROGRAM -generate > $PROBLEM.in 2>/dev/null
   $PROGRAM < $PROBLEM.in > $PROBLEM.out 2>$PROBLEM.err
   $MYPROGRAM < $PROBLEM.in > $PROBLEMSOLVED.out 2>$PROBLEMSOLVED.err

   if cmp -s $PROBLEM.out $PROBLEMSOLVED.out
   then
      echo "The files match"
   else
      echo "The files are different"
   fi
   if cmp -s $PROBLEM.err $PROBLEMSOLVED.err
   then
      echo "The files match-err"
   else
      echo "The files are different"
   fi
done

return 0
