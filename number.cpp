#include "number.h"
#include <string>
#include <algorithm>
#include <QDebug>
using namespace std;

string Number::Tobase(int base){
    string left;
    string res = "";
    string right;
    string x = to_string(number);
    if(prescrision == 0){
        int y = number;
        while(y>0){
            if(y%base>=10 && y%base<=15){
                char tempchar = 'A' + y%base - 10;
                res = tempchar + res;
            }
            else{
                res = to_string(y % base) + res;
            }
            y = y / base;
        }
        return res;
    }
    else{

        left = x.substr(0, x.find('.', 0));
        right = x.substr(x.find('.', 0)+1, x.size());
        int y = stoi(left);
        while(y>0){
            if(y%base>=10 && y%base<=15){
                char tempchar = 'A' + y%base - 10;
                res = tempchar + res;
            }
            else{
                res = to_string(y % base) + res;
            }
            y = y / base;
        }
        right = "0." + right;
        double z = stod(right);
        res += ".";
        for(int i = 0; i < prescrision; i++){
            int add;
             z = z * base;
             add = floor(z);
             qDebug() << z << " " << add << '\n';
             if(add >= 10){
                res += 'A' + add-10;
             }
             else{
                 res += to_string(add);
             }
             z = z- add;
        }
        return res;
    }
}

double Number::todecimal(string x){
    double res = 0;
    int temp;
    if(prescrision == 0){
        for(int i = 0; i < x.size(); i++){
            if(x[i] >= 'A' && x[i] <= 'F'){
                temp = 10+x[i]-'A';
            }
            else{
                temp = x[i] - '0';
            }
            res+=temp*pow(base, x.size() - i - 1);
        }
        return res;
    }
    else if(prescrision > 0){
        string left;
        string right;
        left = x.substr(0, x.find('.', 0));
        right = x.substr(x.find('.', 0)+1, x.size());
        for(int i = 0; i < left.size(); i++){
            if(left[i] >= 'A' && left[i] <= 'F'){
                temp = 10+left[i]-'A';
            }
            else{
                temp = left[i] - '0';
            }
            res+=temp*pow(base, left.size() - i - 1);
        }
        for(int i = 0; i < right.size(); i++){
            if(right[i] >= 'A' && right[i] <= 'F'){
                temp = 10+right[i]-'A';
            }
            else{
                temp = right[i] - '0';
            }
            res+=temp*pow(base, i - 1);
        }
        return res;
    }
    else{
        return -1;
    }
}

bool Number::Chek(string x){
    for(auto i: x){
        if(i == '.'){
            continue;
        }
        int didgit = i - '0';
        int move = abs('A' - i);
        if(i >= 'A' && i <= 'Z'){
            didgit = 10 + move;
        }
        if(didgit >= base){
            qDebug() << i << " " << didgit << '\n';
            return false;
        }
    }
    return true;
}


double Number::getNumber(){
    return number;
}




Number::Number(string n, string b, int p)
{
    base = stoi(b);
    prescrision = p;
    if(b == "10" && p>=0 && Chek(n)){
        number = stod(n);
    }
    else if(base>=2 && base<=16 && p>=0 && Chek(n)){
        number = todecimal(n);
    }
    else{
        throw "ошибка";
    }
}
