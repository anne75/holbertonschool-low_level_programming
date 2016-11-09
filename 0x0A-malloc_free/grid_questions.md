###These are questions I have been asking myself.

In question 2, concatenate 2 strings into a new string:  
. If both arguments are `NULL`, why return a pointer to an empty string and not `NULL` ?   
. If one of the arguments is `NULL`, would not it be better to just return the other string ? But then, the main function always 
uses free(). And that leads to an error.  
. If we check for `NULL`, shouldn't we check for `SIZE_MAX`, if the strings are too large for malloc ?
  
In question 3, create an `int **grid`, initialize all values to 0:  
I have come up with 3 possibilities to do it. Yesterday, nothing was working. Today, the last one is missing one test case.  
1. `allocgood.c`  
I create a grid by first `malloc` the array of row pointers and then `malloc` each row. I check if `malloc` did not return `NULL`
and if not I set all values in that row to 0. With this method, all arrays are spread out in the whole memory.    
2. `allocafter.c`  
I create the grid as above but I set all values to 0 in a second time, in a separate loop.  
3. `allocsinglespace.c`  
I create a grid by first `malloc` the array of row pointers. Then I `malloc` the whole grid, assigning it to the first element
of the array. I then loop throught it to reestablish the bracket notation. In this case, the whole grid is in a single continuous
space in memory.  
I had no idea why my code was not working yesterday, cases to handle a 0x0 grid was done, 1xn, nx1, negative values as well...
so I went trying bigger and bigger sizes. I used this code:   
```
/**                                                                                                                                                   
 * main - check the 3 codes for the grid creation.                                                                                                    
 *                                                                                                                                                    
 * Return: Always 0.                                                                                                                                  
 */
int main(void)
{
        int row;

	      row = 0;
        while (row < 45)
        {
              	printf("row:%i  ", row);
                alloc_grid(123455, ++row);
	       }
        return (0);
}
```
Compiling for each file, I paste the result (adding a new line, at l 46):
```
$ gccplus 3-allocgood.c main-test.c
$ ./a.out 
row:0  row:1  row:2  row:3  row:4  row:5  row:6  row:7  row:8  row:9  row:10  row:11  row:12  row:13  row:14  row:15  row:16  row:17  row:18  row:19  row:20  row:21  row:22  row:23  row:24  row:25  row:26  row:27  row:28  row:29  row:30  row:31  row:32  row:33  row:34  row:35  row:36  row:37  row:38  row:39  row:40  row:41  row:42  row:43  row:44  
$ gccplus 3-allocafter.c main-test.c
$ ./a.out 
Killed
$ gccplus 3-allocsinglespace.c main-test.c
$ ./a.out 
Segmentation fault (core dumped)
$ 
```
OK, there is something. Since yesterday I had come up with solution 2 and 3, I tried to figure out why it was killed 
(did not look much into seg fault sorry). I started to read about  [*opportunistic allocation*]
(http://stackoverflow.com/questions/1865501/c-program-on-linux-to-exhaust-memory/1865527#1865527)
or [*opportunistic memory allocation scheme*](http://stackoverflow.com/questions/16674370/why-does-malloc-or-new-never-return-null).
It looks like linux is overbooks memory, giving away addresses and only checking if it is going to work as we try accessing 
the value. So I thought about solving that problem, and I found solution 1. However today solution 2 is working fine.
So, what was wrong yesterday ?
