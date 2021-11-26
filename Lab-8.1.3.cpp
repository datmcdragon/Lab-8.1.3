#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

char* ChangeSim(char* cs)
{
    if (strlen(cs) < 3)
        return cs;
    char* tmp = new char[strlen(cs) * 3 / 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';
    int i = 0;
    while (cs[i] != 0)
    {
        if ((cs[i] == '+')
            ||
            (cs[i] == '-')
            ||
            (cs[i] == '='))
        {

            strcat(t, "**");
            t += 2;
            i += 1;
        }
        else
        {
            *t++ = cs[i++];
            *t = '\0';
        }
    }
    *t++ = cs[i++];
    *t++ = cs[i++];
    *t = '\0';
    strcpy(cs, tmp);
    return tmp;
}



int CountSim(char* s, const char* cs)
{
    int k = 0,
        pos = 0;
    char* t;
    while (t = strpbrk(s + pos, cs))
    {
        pos = t - s + 1;
        k++;
    }
    return k;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    char cs[201];

    cout << "Ввод: ";

    cin.getline(cs, 200); cout << endl;

    char s[] = "+-=";

    cout << "Кол-во:  " << CountSim(cs, s) << endl;

    char* dest = new char[151];
    dest = ChangeSim(cs);

    cout << "Вывод(Резултат): " << dest << endl;

    return 0;
}