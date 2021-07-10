#include<iostream>
using namespace std;

double divide(double a, double b) {
	if (b == 0) {
		throw "b不能为0";
	}
	return a / b;
}

int main() {

	double a, b;
	cin >> a >> b;

	try {
		divide(a, b);
	}
	catch(const char* &e){
		cout << e << endl;
	}
	return 0;
}
