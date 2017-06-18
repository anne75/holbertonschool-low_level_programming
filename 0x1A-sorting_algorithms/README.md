# Sorting Algorithms in C

This project is a compilation of several sorting algorthims along with their time complexity.
It is organized this way:  
<ul>
<li>a x-name.c file with the algorithm name implemented</li>  
<li>a O-x file with the time complexity for:
  <ul>
  <li>best case</li>
  <li>average case</li>
  <li>worst case</li>
  </ul>
  </li>
</ul>

0. [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sort). Best case is O(n) when the array is already sorted, the worst case is when it is sorted in reverse order, it is O(n^2).  
1. [Insertion Sort](https://en.wikipedia.org/wiki/Insertion_sort). The best case is O(n) when the array is sorted otherwise it is in O(n^2).  
2. [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort). There is no best case, it will always be in O(n^2).  
3. [Quick Sort](https://en.wikipedia.org/wiki/Quicksort), using Hoare partitioning. The best case is O(nlog(n)), the worst case is O(n^2) when the array is already sorted. In this case the partition moves only 1 index at a time.  
4. Answer the time complexity for
```
void f(int n)
{
    printf("n = %d\n", n);
}
```

5. Answer the time complexity for
```
void f(int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("[%d]\n", i);
    }
}
```

6. Answer the time complexity for
```
void f(int n)
{
    int i;

    for (i = 0; i < n; i += 98)
    {
        printf("[%d]\n", i);
    }
}
```

7. Answer the time complexity for
```
void f(unsigned int n)
{
    int i;

    for (i = 1; i < n; i = i * 2)
    {
        printf("[%d]\n", i);
    }
}
```

8. Answer the time complexity for
```
var factorial = function(n) {
    if(n == 0) {
        return 1
    } else {
        return n * factorial(n - 1);
    }
}
```

9. Answer the time complexity for
```
foreach($numbers as $number)
{
    echo $number;
}
```

10. Answer the time complexity for
```
void f(unsigned int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j = j * 2)
        {
            printf("[%d] [%d]\n", i, j);
        }
    }
}
```

11. Answer the time complexity for
```
void f(int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (j = 0; j < n; j = j * 2)
            {
                printf("[%d] [%d]\n", i, j);
            }
        }
        else
        {
            for (j = 0; j < n; j = j + 2)
            {
                printf("[%d] [%d]\n", i, j);
            }
        }
    }
}
```

12. Answer the time complexity for
```
int Fibonacci(int number)
{
    if (number <= 1) return number;

    return Fibonacci(number - 2) + Fibonacci(number - 1);
}
```

13. Answer the time complexity for
```
def func(n):
    a=5
    b=6
    c=10
    for i in range(n):
        for j in range(n):
            x = i * i
            y = j * j
            z = i * j
    for k in range(n):
        w = a*k + 45
        v = b*b
    d = 33
```

14. Answer the time complexity for
```
void f(int n)
{
     int i;
     int j;

     for (i = 0; i < n; i++)
     {
          for (j = i + 1; j < n; j++)
          {
               printf("[%d] [%d]\n", i, j);
          }
     }
}
```

15. Answer the time complexities of those operations on an unsorted array
<ul>
<li>Accessing the nth element</li>
<li>Inserting at index n</li>
<li>Removing at index n</li>
<li>Searching for an element in an array of size n</li>
<li>Setting value at index n</li>
</ul>

16. Answer the time complexities of those operations on a singly linked list
<ul>
<li>Accessing the nth element</li>
<li>Inserting after the nth element (Considering you have a pointer to the node to insert)</li>
<li>Removing the nth element (Considering you have a pointer to the node to remove)</li>
<li>Searching for an element in a linked list of size n</li>
<li>Setting the value of the nth element (Considering you have a pointer to the node to set the value of)</li>
</ul>

17. Answer the time complexities of those operations on a doubly linked list
<ul>
<li>Accessing the nth element</li>
<li>Inserting after the nth element (Considering you have a pointer to the node to insert)</li>
<li>Removing the nth element (Considering you have a pointer to the node to remove)</li>
<li>Searching for an element in a linked list of size n</li>
<li>Setting the value of the nth element (Considering you have a pointer to the node to set the value of)</li>
</ul>

18. Answer the time complexities of those operations on an unsorted Python 3 list
<ul>
<li>Accessing the nth element</li>
<li>Inserting at index n</li>
<li>Removing at index n</li>
<li>Searching for an element in a Python list of size n</li>
<li>Setting value at index n</li>
</ul>

19. Answer the time complexities of those operations on a stack
<ul>
<li>push</li>
<li>pop</li>
<li>Searching for an element in a stack of size n</li>
</ul>

20. Answer the time complexities of those operations on a queue
<ul>
<li>push</li>
<li>pop</li>
<li>Searching for an element in a queue of size n</li>
</ul>

21. Answer the time complexities of those operations on a hash table (chaining)
<ul>
<li>Searching for an element, best case</li>
<li>Searching for an element, worst case</li>
<li>Insertion, best case</li>
<li>Insertion, worst case</li>
<li>Deletion, best case</li>
<li>Deletion, worst case</li>
</ul>

22. /100 [Shell Sort](https://en.wikipedia.org/wiki/Shellsort). No O for this one as it depends on the gap chosen...   
23. /101 [Cocktail Shaker Sort](https://en.wikipedia.org/wiki/Cocktail_shaker_sort). An improvement on bubble sort, but the time complexities are the same, O(n) for best case, O(n^2) for worst case  
24. /102 [Counting Sort](https://en.wikipedia.org/wiki/Counting_sort). This sorting algorithm does not rely on comparison, but it requires to take into account the maximum key value (k), so the time complexity is O(n+k). The extra space required is O(k)  
25. /103 [Merge Sort](https://en.wikipedia.org/wiki/Merge_sort). It runs in O(nlog(n))  
26. /104 sift-down [Heap Sort](https://en.wikipedia.org/wiki/Heapsort). It runs in O(nlog(n))  
27. /105 [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort) or LSD sort. It does not rely on comparison, but requires to take into account the word size w of the keys. It is in O(wn) and requires extra space  
28. /106 [Bitonic Sort](https://en.wikipedia.org/wiki/Bitonic_sorter). *(non recursive)* It runs in O((log(n))^2), and it can run in parallel  
29. /1000 Sort a deck of cards given as a doubly linked list  
