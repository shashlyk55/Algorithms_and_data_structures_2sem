#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>

using namespace std;

bool checkBrackets(string str) {
    stack<char> s;
    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false; 
            }
            char last = s.top();
            s.pop();
            if ((c == ')' && last != '(') || (c == ']' && last != '[') || (c == '}' && last != '{')) {
                return false; 
            }
        }
    }
    return s.empty(); 
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "Введите строку: ";
    getline(cin, str);
    if (checkBrackets(str)) {
        cout << "Скобки расставлены верно\n";
    }
    else {
        cout << "Скобки расставлены неверно\n";
    }
    return 0;
}
