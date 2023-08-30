1. In the developed application (on the walls) it is necessary to enter a character string that can contain numbers, letters, signs of mathematical operations (+, -, *, /) and three types of brackets: (), [] and {}. 
Determine whether the brackets are correctly placed (the characters between the brackets are not taken into account). For example, in the lines ()[{}] and [{}([])] the brackets are placed correctly, and in the lines ([)] and ]]]((( - incorrect. 
As an answer, print the text "brackets are placed correctly" or "brackets are placed incorrectly".

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
    cout << "Ââåäèòå ñòðîêó: ";
    getline(cin, str);
    if (checkBrackets(str)) {
        cout << "Ñêîáêè ðàññòàâëåíû âåðíî\n";
    }
    else {
        cout << "Ñêîáêè ðàññòàâëåíû íåâåðíî\n";
    }
    return 0;
}
