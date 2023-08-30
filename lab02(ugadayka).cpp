Develop an application implementing the game "Guessing Game!" based on binary search.

#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
using namespace std;

void main() {

	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(NULL)) * 100 * 100 * 100 * 100);

	
		// data declaration
		char n, otvet;
		int scope, number;
			cout << "Enter the range of values in which you want to guess the number\n";
			cin >> scope;
			
			int a = 1, b=scope, c=1, f;
			int random = scope / 2, count = 0, chast = scope / 2;
			while (a != 2) {
				
				cout << " ß äóìàþ ýòî ÷èñëî: " << random << "\n\n";
				cout << "1 - less\n";
				cout << "2 - more\n";
				cout << "3 - you gessed it\n";
				cin >> otvet;
				while (otvet > '3' || otvet < '1') {
					
					cout << "incorrect response\n\n\n";
					cout << "I think it's a number: " << random << "\n";
					cout << "1 - less\n";
					cout << "2 - more\n";
					cout << "3 - you gessed it\n";
					cin >> otvet;
					
				}
				//Calculating a number by binary selection
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
			//Ìàêñèìàëüíîå êîëè÷åñòâî øàãîâ áèíàðíîãî ïîèñêà
			int max_shag = 0, gread = scope;
			while (gread != 0) {
				gread = gread / 2;
				max_shag++;
			}
			//Output the number of computer attempts
			cout << "The intended number: " << random << "\n";
			cout << "the program needed " << count << " attempts \n";
			cout << "Maximum number of binary search steps =  " << max_shag << "\n";		
}
