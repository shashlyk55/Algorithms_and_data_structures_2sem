#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void main() {

	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(NULL)) * 100 * 100 * 100 * 100);

	
		// ���������� ������
		char n, otvet;
		int scope, number;
			cout << "������� ���������� �������� � ������� �� ������ �������� �����\n";
			cin >> scope;
			/**cout << "������� �����, ������� ������ �������� ";
			cin >> number;
			while (number > scope) {
				cout << "������!����� �� ��������� � �������� ����������\n";
				cin >> number;
			}*/
			
			int a = 1, b=scope, c=1, f;
			int random = scope / 2, count = 0, chast = scope / 2;
			while (a != 2) {
				
				cout << " � ����� ��� �����: " << random << "\n\n";
				cout << "1 - ������\n";
				cout << "2 - ������\n";
				cout << "3 - ������\n";
				cin >> otvet;
				while (otvet > '3' || otvet < '1') {
					
					cout << "������������ �����\n\n\n";
					cout << "����� ��� �����: " << random << "\n";
					cout << "1 - ������\n";
					cout << "2 - ������\n";
					cout << "3 - ������\n";
					cin >> otvet;
					
				}
				//���������� ����a ���� ���������� ������
				count++;
				if (otvet == '1') {
					b = random;
					if (count == 1) {
						random = chast - chast / 2;
						chast = chast / 2;
					}
					else {
						random = random - chast;
					}
					if (chast == 0) {
						random = random - 1;
					}
					if (count != 1) {
						if (c >= random || f == 1)break;
					}
				}
				if (otvet == '2') {
					c = random;
					if (count == 1) {
						random = chast + chast / 2;
						chast = chast / 2;
					}
					else {
						random = random + chast;
					}
					if (chast == 0) {
						random = random + 1;
					}
					if (count != 1) {
						if (b <= random || f == 2)break;
					}
				}
				if (otvet == '3') {
					a = 2;
				}
				chast = chast / 2;
				f = otvet;
				if (random >= scope || random <= 0) {
					break;
				}
			}
			//������������ ���������� ����� ��������� ������
			int max_shag = 0, gread = scope;
			while (gread != 0) {
				gread = gread / 2;
				max_shag++;
			}
			//����� ���������� ������� ����������
			cout << "���������� �����: " << random << "\n";
			cout << "��������� ������������ " << count << " ������� \n";
			cout << "������������ ���������� ����� ��������� ������ =  " << max_shag << "\n";		
}