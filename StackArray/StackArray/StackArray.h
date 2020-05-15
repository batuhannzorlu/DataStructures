
#ifndef STACKARRAY_H




#define STACKARRAY_H

#include <iostream>
using namespace std;

struct s {

	int *arr;
	int  _size;
	int top;
};
typedef   s stack;

stack* init();
void print(stack *s);
int pop(stack *s); 
void _push(int a, stack *s);



#endif



