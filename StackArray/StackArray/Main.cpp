
#include <iostream>
#include "StackArray.h"

using namespace std;


int main()
{
	stack *s = init();
	s->arr = new int[s->_size * 2];

	for (size_t i = 0; i < 10; i++)
	{
		_push(i, s);
		cout << "SIZE OF THE ARRAY: " << s->_size << endl;
	}
	pop(s);
	pop(s);
	pop(s);
	print(s);
	cout << "SIZE OF THE ARRAY: " << s->_size << endl;
}