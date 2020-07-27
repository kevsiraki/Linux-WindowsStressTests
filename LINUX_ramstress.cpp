#include <iostream>
using namespace std;

int main() {
	char input = 'c';
	int *a;
	cout<<"Filling up RAM\n";
	while(true) {
		try {
			a = new int;
		}
		catch(std::bad_alloc& ba) {
			break;
		}
	}
	cout<<"Press enter key to stop. \n";
	getchar();
	delete[] a;	
	a=nullptr;
	return 0;
}
