#ifndef VALIDATE_H_INCLUDED
#define VALIDATE_H_INCLUDED

#include <string>
using namespace std;
//grepper validate int number c++
bool isInt(string num) {

    int value,a(0);

    for(int i = 0; i < num.length(); i++) {
        value = (int)num[i];
        if(value >= 48 && value <= 57 )
            a++;

        }
    return a == num.length() && num.length() != 0;

    }

#endif // VALIDATE_H_INCLUDED
