#include<iostream>
#include<windows.h>
using namespace std;
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int N;
	cout << "���������� ����������: ";
	cin >> N;
	while (N < 1 || N > 10000) {
		cout << "O�����\n���������� ����������: ";
		cin >> N;
	}
	int* a = new int[N];
	//int a[20]{};
	for (int i = 0; i < N; i++) {
		//cin >> a[i];
		a[i] = rand() & 100;
		cout << a[i] << " ";
	}

	int max = -1, count = 0, sum = 0;
	

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < N; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		for (int i = 0; i < N; i++) {
			if (max == a[i] && a[i]>=0) {
				a[i] = -1;
				count++;
			}
		}
		sum += count;
		count = 0;
		max = -1;
	}

	cout << "\n�������: " << sum;

	delete[] a;
}