#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void main() {

	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(NULL)) * 100 * 100 * 100 * 100);

	
		// Объявление данных
		char n, otvet;
		int scope, number;
			cout << "Введите промежуток значений в котором вы хоитие загадать число\n";
			cin >> scope;
			/**cout << "Введите число, которое хотите загадать ";
			cin >> number;
			while (number > scope) {
				cout << "Ошибка!Число не находится в заданном промежутке\n";
				cin >> number;
			}*/
			
			int a = 1, b=scope, c=1, f;
			int random = scope / 2, count = 0, chast = scope / 2;
			while (a != 2) {
				
				cout << " Я думаю это число: " << random << "\n\n";
				cout << "1 - Меньше\n";
				cout << "2 - Больше\n";
				cout << "3 - Угадал\n";
				cin >> otvet;
				while (otvet > '3' || otvet < '1') {
					
					cout << "некорректный ответ\n\n\n";
					cout << "думаю это число: " << random << "\n";
					cout << "1 - Меньше\n";
					cout << "2 - Больше\n";
					cout << "3 - Угадал\n";
					cin >> otvet;
					
				}
				//Вычисление числa путём бинароного отбора
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
			//Максимальное количество шагов бинарного поиска
			int max_shag = 0, gread = scope;
			while (gread != 0) {
				gread = gread / 2;
				max_shag++;
			}
			//Вывод количество попыток компьютера
			cout << "Задуманное число: " << random << "\n";
			cout << "Программе понадобилось " << count << " попыток \n";
			cout << "Максимальное количество шагов бинарного поиска =  " << max_shag << "\n";		
}