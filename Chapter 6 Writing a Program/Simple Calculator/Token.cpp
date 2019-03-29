//
// Created by John J. Hritz on 3/29/2019.
//

#include "Token.h"


Token::Token(char ch)    // make a Token from a char
            :kind(ch), value(0) { }


Token::Token(char ch, double val)     // make a Token from a char and a double
            :kind(ch), value(val) { }
