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

class Token_stream
{
    public:
        static constexpr char quit = 'q';      // A quit command from the command line
        static constexpr char print = ';';     // A print command from the command line
        static constexpr char num = 'n';       // A numeric token (rather than an operator)

        Token_stream();   // make a Token_stream that reads from cin
        Token get();      // get a Token (get() is defined elsewhere)
        void putback(Token t);    // put a Token back

    private:
        bool full;        // is there a Token in the buffer?
        Token buffer;     // here is where we keep a Token put back using putback()
};


#endif //PRINCIPLES_AND_PRACTICES_TOKEN_H
