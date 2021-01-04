#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void printlist(list <int> listTemp)
{
	list<int>::iterator it;
	for(it = listTemp.begin(); it != listTemp.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
}

int main()
{
	list<int> l1, l2;
	l1.push_back(50);
	l1.push_back(60);
	l1.push_back(70);
	l1.push_back(800);
	l1.push_back(90);
	l1.push_front(40);
	printlist(l1);

	cout << "front " << l1.front() << endl;

	l1.pop_back();

	printlist(l1);

	l1.reverse();
	printlist(l1);

	l1.sort();
	printlist(l1);
	return 0;
}
