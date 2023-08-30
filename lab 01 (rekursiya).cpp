To develop an application that implements the display of the N-number of the Fibonacci sequence. Implement 2 ways of counting: recursive way; linear way.

#include<iostream>
#include<ctime>
using namespace std;

int calc(int n, int a = 0, int b = 1);

void main() {
	setlocale(LC_ALL, "ru");
	unsigned int n;
	
	cout << "Íîìåð ÷èñëà ïîñëåäîâàòåëüíîñòè: ";
	cin >> n;
	unsigned int start = clock();
	cout << "×èñëî " << calc(n);
	unsigned int end = clock();
	float dif = end - start;
	cout << endl << (int)dif / 60000 << " ìèí " << (int)dif / 1000 << " ñ";
}

int calc(int n,int a,int b) {
	if (n == 1) {
		return a;
	}
	if (n == 2) {
		return b;
	}
	return calc(n - 1) + calc(n - 2);
}
