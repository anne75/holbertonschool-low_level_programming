#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c $(ls *.c)
ar rcs liball.a *.o
rm -f *.o
