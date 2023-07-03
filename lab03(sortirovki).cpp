#include<iostream>
#include<ctime>
using namespace std;

void quicksort(int* mas, int first, int last);

void main() {
	setlocale(LC_ALL, "ru");
	int N, i, j;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	int* C = new int[N];
	int* D = new int[N];
	int* E = new int[N];
	srand(time(NULL));
	cout << "A:\n";
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 30;
		cout << A[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; i++) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

	//пузырьковая сортировка массива В пузыриками
	cout << "\nB: \n";
	for (int i = 0; i < N; i++) {
		cout << B[i] << " ";
	}
	cout << endl;
	unsigned int start = clock();
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (B[i] > B[j]) {
				int temp;
				temp = B[i];
				B[i] = B[j];
				B[j] = temp;
			}
		}
	}
	unsigned int end = clock();
	float dif = end - start;
	for (int i = 0; i < N; i++) {
		cout << B[i] << " ";
	}
	cout << "\nВремя B: " << dif << " мс\n";
	

	//сортировка массива C вставкой
	cout << "\nC: \n";
	for (int i = 0; i < N; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
	int buff;
	start = clock();
	for (int i = 1; i < N; i++) {
		buff = C[i];
		for (j = i - 1; j >= 0 && C[j] > buff; j--)
			C[j + 1] = C[j];

		C[j + 1] = buff;
	}
	end = clock();
	dif = end - start;
	for (int i = 0; i < N; i++) {
		cout << C[i] << " ";
	}
	cout << "\nВремя С: " << dif << " мс\n";


	//сортировка массива D выборкой
	cout << "\nD: \n";
	for (int i = 0; i < N; i++) {
		cout << D[i] << " ";
	}
	cout << endl;
	int min, buf;
	start = clock();
	for (int i = 0; i < N; i++) {
		min = i;

		for (int j = i + 1; j < N; j++)
			min = (D[j] < D[min]) ? j : min;

		if (i != min) {
			buf = D[i];
			D[i] = D[min];
			D[min] = buf;
		}
	}
	end = clock();
	dif = end - start;
	for (int i = 0; i < N; i++) {
		cout << D[i] << " ";
	}
	cout << "\nВремя D: " << dif << " мс\n";


	//сортировка массива E быстрой сортировкой
	
	cout << "\nE: \n";
	for (int i = 0; i < N; i++) {
		cout << E[i] << " ";
	}
	cout << endl;
	start = clock();
	quicksort(E, 0, N-1);
	end = clock();
	dif = end - start;
	for (int i = 0; i < N; i++) {
		cout << E[i] << " ";
	}
	cout << "\nВремя E: " << dif << " мс\n";

}

void quicksort(int* mas, int first, int last) {     //функция сортировки
	int mid, count;
	int f = first, l = last;
	mid = mas[(f + l) / 2]; 				//вычисление опорного элемента
	do
	{
		while (mas[f] < mid) f++;
		while (mas[l] > mid) l--;
		if (f <= l) 				//перестановка элементов
		{
			count = mas[f];
			mas[f] = mas[l];
			mas[l] = count;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(mas, first, l);
	if (f < last) quicksort(mas, f, last);
}