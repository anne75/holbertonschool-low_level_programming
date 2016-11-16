#ifndef _CALC_H_
#define _CALC_H_

/*functions needed in question 4*/

int op_add(int, int);
int op_sub(int, int);
int op_mul(int, int);
int op_div(int, int);
int op_mod(int, int);

int (*get_op_func(char *s))(int, int);

#endif
