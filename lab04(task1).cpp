#include<iostream>
#include<windows.h>
using namespace std;

void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int N;
	cout << "×טסכמ עמגאנמג: ";
	cin >> N;
	while (N < 1 || N>10000) {
		cout << "Oרטבךא\n×טסכמ עמגאנמג: ";
		cin >> N;
	}
	int* a = new int[N];
	//int a[20]{};
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}

	int max = 0, i = 0, j = 0, k = 1, count = 0, min = 0;
	while (count < N && k < N && j < N) {
		for (i = max; i < N; i++) {
			if (a[i] > a[max]) {
				max = i;
			}
		}
		swap(a[max], a[j]); 
		for (i = min; i < N; i++) {
			if (a[i] < a[min]) {
				min = i;
			}
		}
		swap(a[min], a[k]);
		j += 2;
		k += 2;

		count++;
		max = j;
		min = k;
	}
	cout << endl << endl;
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			sum += a[i];
		}
	}
	cout << "\nmax sum = " << sum;

	delete[] a;
}