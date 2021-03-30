#include "subforwardlist.h"
#include <iostream>

using namespace std;

int main()
{
	//auto* s = new subforwardlist<int>();
	subforwardlist<int> sfl;
	sfl.push_back(0);
	sfl.push_back(1);
	cout << endl;
	sfl.print();
	cout << endl;

	cout << "poped back: " << sfl.pop_back() << endl;
	sfl.print();
	cout << endl;

	sfl.push_forward(17);
	sfl.print();
	cout << endl;

	cout << "poped forward: " << sfl.pop_forward() << endl;
	sfl.print(); 
	cout << endl;

	sfl.push_where(1, 33);
	sfl.print();
	cout << endl;
	cout << "size before erasing: " << sfl.size() << endl;

	cout << "erased first: " << sfl.erase_where(1)<< endl;
	cout << endl;
	sfl.print();
	cout << endl;

	cout  << "size after erasing: " << sfl.size() << endl;

	cout << "poped forward: " <<  sfl.pop_forward() << endl;
	cout << "final size: " << sfl.size() << endl;
	cout << endl;

	return 0;
}
