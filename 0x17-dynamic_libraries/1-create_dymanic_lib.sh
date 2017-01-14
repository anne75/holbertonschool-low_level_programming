#/bin/bash
gcc -c -Wall -Werror -Werror -pedantic -fpic *.c
gcc -shared -o liball.so *.o
rm *.o
