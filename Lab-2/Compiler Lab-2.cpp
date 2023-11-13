#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isOperator(char a) {
    return (a == '+' || a == '-' || a == '*' || a == '/' || a == '=');
}

bool isPunctuation(char a) {
    return (a == ';' || a == ',' || a == '.' || a == ':' || a == '(' || a == ')');
}

bool isConstant(const string& word) {
    for (char c : word) {
        if (!isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

void listPunctuationAndOperators(const string& myText) {
    cout << "Arithmetic Expression and Punctuation: ";
    for (int i = 0; i < myText.length(); i++) {
        if (isOperator(myText[i]) || isPunctuation(myText[i])) {
            cout << myText[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    string myText;
    ifstream MyReadFile("Lab Task-2.txt");

    if (MyReadFile.is_open()) {
        while (getline(MyReadFile, myText)) {
            listPunctuationAndOperators(myText);
        }
        MyReadFile.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}