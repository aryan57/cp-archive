#include <iostream>
using namespace std;
class MyClass
{
	int y,z;
	static int x; // Declare static
public:
	void get() { 
		x = 15;
	}
	void print()
	{
		x = x + 10;
		cout << "x = " << x << endl;
	}
};
// int MyClass::x;
	int MyClass::x;
int main()
{

	MyClass obj1, obj2;
	obj1.get();
	obj2.get();
	obj1.print();
	obj2.print();
	cout<<sizeof(MyClass);cout<<"\n";
	cout<<sizeof(obj1);cout<<"\n";
	return 0;
}