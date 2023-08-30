To develop an application that implements the display of the N-number of the Fibonacci sequence. Implement 2 ways of counting: recursive way; linear way.

#include<iostream>
#include<ctime>

using namespace std;

void main() {
	setlocale(LC_ALL, "RU");

	unsigned int n;
	
	unsigned int a = 0, b = 1, c;
	cout << "Íîìåð ÷èñëà ïîñëåäîâàòåëüíîñòè: ";
	cin >> n;
	float start = (float)clock();
	if (n == 1) {
		cout << a;
	}
	if (n == 2) {
		cout<< b;
	}
	else {
		for (int i = 0; i < n - 2; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		
	}
	float end = (float)clock() ;cout << b;
	float time = (float)(end - start) / CLOCKS_PER_SEC;
	cout << endl << time << " ñåêóíä";
}
