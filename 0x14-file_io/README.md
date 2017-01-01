### Opening, writing to, reading from a file
This folder contains our first approach to file I/O in general and in C in particular. We are only allowed to use the system calls `read`, `write`, `open` and `close`. We also have to use `POSIX` standards. This [link](https://drive.google.com/open?id=16lRrXEEIlLHSRh2cir0YQScQkF8jBy89d4jSY4zmqgg) is a presentation I made. We had to answer the following questions, for each one the prototype was given.  
0. Write a function that reads a text file and prints it to the POSIX standard output. The expected number of letters to print is given in parameter and we return the actual number printed.  
1. Create a function that creates a file with 600 permissions if it does not exist and fill it with a given string.  
2. Write a function that appends a text at the end of an already existing file.  
3. Write a program that copies the content of a file to another file. Error messages are required and format is given.  
4. Write a program that displays the information contained in the ELF header at the start of an ELF file. (not done yet).  

