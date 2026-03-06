//Вариант 12 Преобразовать строку таким образом, чтобы все слова в ней были напечатаны наоборот
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
    const int y = 255;
    char s[y];
    int start = 0, c;
    char t;

    cout << "Введите строку и добавьте точку в конце " << endl;
    getline(s, y);

    int l = strlen(s);
    for (int i = 0; i <= l; i++){
        if (s[i] == ' ' || s[i] == '.' || s[i] == '\0'){
            c = i - 1;
            while (start < c)
            {
                t = s[start];
                s[start] = s[c];
                s[c] = t;

                start++;
                c--;
            }
            start = i + 1;
        }
    }

    cout << "Результат: " << s << endl;
    return 0;
}
