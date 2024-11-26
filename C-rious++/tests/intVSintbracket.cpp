#include <iostream>

using namespace std;

int main()
{
  int *y = new int();
  cout << "y = " << y << " &y = " << &y << " *y = " << *y << endl;
  int *p = new int;
  cout << "p = " << p << " &p = " << &p << " *p =" << *p << endl;
}