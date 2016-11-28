##Variadic Functions  
In this folder, we meet functions with a variable number of arguments for the first time.  
The following exercises were done to understand the concept and pratice. For each exercise, the prototype of the function is given. They are all gathered in `variadic_functions.h`.  
0. Write a function that returns the sum of all its parameters. The first argument is the number of arguments passed after.    
1. Write a function that prints numbers, followed by a new line. The first parameter of this function is a separator we have to print between each numbers, the second is the number of arguments passed after.  
2. Write a function that prints strings, followed by a new line. The same as number 1, except arguments here are strings.  
3. Write a function that prints anything. The first arguments is a string, it gives the order and type of the argument to expect in the variable part. Those types are limited to `c` for char, `f` for floats, `i` for integers and `s` for strings. To make things more interesting, this string can be peppered with other letters, we can declare up to 9 variables and we are only allowed to 2 `while` and 2 `if` inside the file.  
  
The following question is an extra not related to variadic functions:  
100. Write a 64-bit program in assembly that prints Hello, Holberton, followed by a new line. We are only allowed to use the system call write (use an interrupt, not a call)
