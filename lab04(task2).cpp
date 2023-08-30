Task 2
According to the results of the Olympiad, participants are awarded diplomas. Those who score the same points receive diplomas of the same degree. The winner of the Olympiad is a participant who has received a diploma no worse than the III degree.
Based on the results of the Olympiad, determine the number of winners. 
Input: natural number of winners (N < 10000) and then N natural numbers – the results of the participants (generate from 1 to 100)
Output: one number is the number of winners.
Example:
Input     N=10 			1 3 4 3 5 6 7 7 6 1
Output 			5
Comment		The winners are the participants who scored 7, 6 or 5 points

  

#include<iostream>
#include<windows.h>
using namespace std;
void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int N;
	cout << "Number of participants: ";
	cin >> N;
	while (N < 1 || N > 10000) {
		cout << "Error\nNumber of participants: ";
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

	cout << "\nprize - winners: " << sum;

	delete[] a;
}
