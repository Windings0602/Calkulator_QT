#include "calk.h"
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

Calk::Calk()
{

}
deque<string> Calk::To_Postficks(string exp){
    string temp = "";
    deque<string> num;
    deque<char> opers;
    for(auto i: exp){
        if(isdigit(i) || i=='.'){
            temp += i;
        }
        else if(i == '('){
            opers.push_back(i);
            if(!temp.empty()){
                throw string{"отсутсвует знак умножения перед скобкой"};
            }
        }
        else if(i==')'){
            if(temp.empty()){
                throw string{"отсутсвует число перед скобкой"};
            }
            num.push_back(temp);
            temp = "";
            while(!opers.empty() && opers.back() != '('){
                num.push_back(string{opers.back()});
                opers.pop_back();
            }
            if(!opers.empty() && opers.back() == '('){
                opers.pop_back();
            }
            else{
                throw string{"отсутствует скобка"};
            }
        }
        else{
            if(temp.empty()){
                throw string{"нет числа"};
            }
            num.push_back(temp);
            temp = "";
            while(!opers.empty() && priority[opers.back()] >= priority[i]){
                num.push_back(string{opers.back()});
                opers.pop_back();
            }
            opers.push_back(i);
        }
    }
    if(!temp.empty()){
        num.push_back(temp);
    }
    while(!opers.empty()){
        num.push_back(string{opers.back()});
        opers.pop_back();
    }
    return num;
}
double Calk::Run(string exp){
    deque <string> postfix(To_Postficks(exp));
    deque <double> vars;
    for(auto i: postfix){
        if(Is_Didgits(i) == true){
            vars.push_back(stod(i));
        }
        else{
            double second = vars.back();
            vars.pop_back();
            double first = vars.back();
            vars.pop_back();
            vars.push_back(Doing(first, second, i));
        }
    }
    if(vars.empty()){
        throw string{"Нет данных"};
    }
    return vars.back();
}
bool Calk::Is_Didgits(string exp){
    for(auto i: exp){
        if(!isdigit(i) && i != '.'){
            return false;
        }
    }
    return true;
}

double Calk::Doing(double a, double b, string c){
    if(c == "+"){
        return a+b;
    }
    else if(c == "-"){
        return a-b;
    }
    else if(c == "X"){
        return a*b;
    }
    else if(c== "/"){
        if(b == 0){
            throw string{"Ошибка"};
        }
        return a/b;
    }
    else if(c == "^"){
        return pow(a,b);
    }
}


