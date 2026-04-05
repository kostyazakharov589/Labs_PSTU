//Вариант 12 - из файла f1 скопировать все строки, кроме той, в которой содержится больше всего гласных букв
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

int podschet(string s) {
    string glasnye = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if ((unsigned char)s[i] >= 0xC0) {
            string symvol = s.substr(i, 2);
            if (glasnye.find(symvol) != string::npos) {
                count += 1;
            }
            i++;
        }
    }
    return count;
}

void pechat(string name) {
    fstream f(name, ios::in);
    string line;
    int i = 1;
    cout << "файл " << name << endl;
    while (getline(f, line)) {
        cout << i++ << " : " << line << endl;
    }
    f.close();
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    string f1_name = "f1.txt";
    string f2_name = "f2.txt";

    pechat(f1_name);

    fstream file(f1_name, ios::in);
    if (!file.is_open()) {
        cout << f1_name << " не найден" << endl;
        return 1;
    }

    string lines[100];
    int chislo_strok = 0;
    int max_vse = -1;
    int t = -1;

    while (true) {
        getline(file, lines[chislo_strok]);
        if (!file) {
            break;
        }
        int vc = podschet(lines[chislo_strok]);
        if (vc > max_vse) {
            max_vse = vc;
            t = chislo_strok;
        }
        chislo_strok++;
    }
    file.close();

    fstream fileOut(f2_name, ios::out);
    for (int i = 0; i < chislo_strok; i++) {
        if (i != t) {
            fileOut << lines[i] << endl;
        }
    }
    fileOut.close();

    cout << endl << "Удалена строка номер " << t + 1 << " с " << max_vse << " гласных" << endl << endl;

    pechat(f2_name);
    fstream file22(f2_name, ios::in);
    if (!file22.is_open()) {
        cout << f2_name << " не найден" << endl;
        return 1;

    }


    return 0;
}