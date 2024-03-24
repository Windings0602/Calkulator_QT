#ifndef NUMBER_H
#define NUMBER_H
#include <string>
using namespace std;


class Number
{
public:
    Number(string n, string b, int p);
    string Tobase(int base);
    bool Chek(string x);
    double todecimal(string x);
    double getNumber();
    int prescrision;
    int base;
    double number;
};

#endif // NUMBER_H
