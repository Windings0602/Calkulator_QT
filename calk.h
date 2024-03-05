#ifndef CALK_H
#define CALK_H
#include <map>
#include <deque>
#include <string>
using namespace std;


class Calk
{
public:
    Calk();
    map <char, int> priority{
        {'+', 1},
        {'-', 1},
        {'X', 2},
        {'/', 2},
        {'^', 3},
    };
    deque<string> To_Postficks(string exp);
    double Run(string exp);
    bool Is_Didgits(string exp);
    double Doing(double a, double b, string c);
};

#endif // CALK_H
