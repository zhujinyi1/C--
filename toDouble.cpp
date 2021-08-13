#include<iostream>
#include<string>
#include<cmath>
using namespace std;

double toDouble(string str) {
	double a = 0.0;
	bool dot = false;
	double p=0.1;
	for (char i : str) {
		if (i != '.') {
			if (!dot) {
				a = a * 10 + (double)(i - '0');
			}
			else {
				a += p * (double)(i - '0');
                p = p*0.1;
			}
		}
		else {
			dot = true;
		}
			
	}
    return a;
}

int main(){
    string str;
    getline(cin,str);
    cout << toDouble(str) << endl;
}