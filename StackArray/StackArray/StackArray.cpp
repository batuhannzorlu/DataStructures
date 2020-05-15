
#include <iostream>
#include "StackArray.h"

using namespace std;

stack*  init() {
	stack *s = new  stack;
	s->arr=NULL;
	s->top = 0;
	s->_size = 2;
  
	return s;
}
void _push(int a, stack *s) {
	if ( s->arr == NULL)
		s->arr = new int[2];

	if (s->top >= s->_size) {
		int *arr2 = new int[(s->_size) * 2];
		for (int i = 0; i <s->_size; i++)
		{
			arr2[i] = s->arr[i];
		}
		delete s->arr;
		s->_size *= 2;
		s->arr = arr2;
		
	}
	s->arr[(s->top)++] = a;
		
}
int pop(stack *s) {

	if (s->arr==NULL)
		cout << "ARRAY IS ALREADLY EMPTY!" << endl;

	if (s->top <=s->_size/4)
	{
		int *arr3 = new int[s->_size / 2];
		
		for (int i = 0; i < s->_size/2; i++)
		{
			arr3[i] = s->arr[i];			
		}
		s->_size = (s->_size / 2);
		cout << "INNER SIZE: " << s->_size << endl;
		delete s->arr;
		s->arr = arr3;	
		
	}
	return s->arr[--(s->top)];
}
void print(stack *s){
	cout << "ARRAY: "<< endl;
	for (int i = 0; i < s->top; i++)
	{
		cout <<s->arr[i]<<endl;
	}
}
