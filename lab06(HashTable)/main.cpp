1.	Создать хэш-таблицу с цепочками (с прямой адресацией) со следующими полями: номер телефона, ФИО владельца. Ключ – номер телефона. Телефон хранится в переменной типа int, INT_MAX = 32767. Использовать хеш-функции 
2.	Организовать добавление, удаление и поиск элементов. 
3.	Организовать вывод всей таблицы.
4.	Построить хэш-таблицы разного размера (например, 16, 32 или 32, 64, 128) с коллизиями. Исследовать время поиска  в построенных хэш-таблицах.


#include "Hash_Twin_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <fstream>
#include "Lists.h"
#include <chrono>
#include<string>

#define MAXLENGTH 100
using namespace std;


struct AAA
{
	int key;
	string mas;
	AAA(int k, const char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = "";
	}
};
//-------------------------------
int hf(void* d)
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << ' - ' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
void foutF(ofstream& f, char* name);

int main(/*int argc, _TCHAR* argv[]*/)
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int current_size = 0;
	cout << "Ââåäèòå ðàçìåð òàáëèöû: ";
	cin >> current_size;
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)
	{
		cout << "1 - âûâîä òàáëèöû" << endl;
		cout << "2 - äîáàâèòü ýëåìåíò òàáëèöû" << endl;
		cout << "3 - óäàëèòü ýëåìåíò òàáëèöû ïî êëþ÷ó" << endl;
		cout << "4 - íàéòè ýëåìåíò ïî êëþ÷ó" << endl;
		cout << "âàø âûáîð" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;
			string str;
			cout << "ââåäèòå íîìåð òåëåôîíà : ";
			cin >> k;
			while (k > 32767) {
				cout << "ñëèøêîì áîëüøîå çíà÷åíèå!\nââåäèòå äðóãîé êëþ÷: ";
				cin >> k;
			}
			cin.ignore();
			
			a->key = k;
			cout << "ââåäèòå ÔÈÎ: ";
			getchar();
			getline(cin, str);
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "ââåäèòå êëþ÷: ";
			cin >> k;
			b->key = k;
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "ââåäèòå êëþ÷: ";
			cin >> k;
			c->key = k;
			auto begin = std::chrono::high_resolution_clock::now();
			H.Scan1(c);
			auto end = std::chrono::high_resolution_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			int long el = elapsed.count();
			std::cout << "time of working : " << el << " mks" << "\n\n\n" << std::endl;
		}
			  break;
		}
	}
	return 0;
}

