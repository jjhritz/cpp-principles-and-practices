//
// Created by John J. Hritz on 3/29/2019.
//

#ifndef PRINCIPLES_AND_PRACTICES_TOKEN_H
#define PRINCIPLES_AND_PRACTICES_TOKEN_H

#include "../../Programming-_Principles_and_Practice_Using_Cpp/std_lib_facilities.h"

class Token
{
    // Representation of tokens taken from the command line
    public:
        char kind;
        double value;
        Token(char ch);
        Token(char ch, double val);
};


#endif //PRINCIPLES_AND_PRACTICES_TOKEN_H
