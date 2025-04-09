#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>
using namespace std;

// Перевірка: чи символ — літера або цифра
bool isAlphaNumeric(char ch) {
    return (ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch >= '0' && ch <= '9');
}

// Приведення великої літери до малої
char toLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ifstream file("text.txt");
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    map<string, int> wordCount;
    string word;
    char ch;

    while (file.get(ch)) {
        if (isAlphaNumeric(ch)) {
            word += toLower(ch);  // використовуємо власні функції
        }
        else if (!word.empty()) {
            wordCount[word]++;
            word.clear();
        }
    }

    // Додати останнє слово, якщо треба
    if (!word.empty()) {
        wordCount[word]++;
    }

    file.close();

    // Виведення результатів
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
