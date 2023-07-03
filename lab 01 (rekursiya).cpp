#include<iostream>
#include<ctime>
using namespace std;

int calc(int n, int a = 0, int b = 1);

void main() {
	setlocale(LC_ALL, "ru");
	unsigned int n;
	
	cout << "����� ����� ������������������: ";
	cin >> n;
	unsigned int start = clock();
	cout << "����� " << calc(n);
	unsigned int end = clock();
	float dif = end - start;
	cout << endl << (int)dif / 60000 << " ��� " << (int)dif / 1000 << " �";
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