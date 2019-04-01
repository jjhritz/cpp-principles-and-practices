//
// Created by John J. Hritz on 3/29/2019.
//

#include "Token.h"

Token::Token(char ch)    // make a Token from a char
    :kind(ch), value(0) { }


Token::Token(char ch, double val)     // make a Token from a char and a double
    :kind(ch), value(val) { }


// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0) { }   // no Token in buffer


// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}


Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch)
    {
        case print:    // for "print"
        case quit:    // for "quit"
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':       // Numeric literals
        {
            cin.putback(ch);                // put digit back into the input stream
            double val;
            cin >> val;                     // read a floating-point number
            return Token(this->num,val);    // A numerical token
        }
        default:
            error("Bad token");
    }
}


void Token_stream::ignore(char c)
{
    // If the buffer is full, just allow it to be overwritten
    if (full && c == buffer.kind)
    {
        full = false;
        return;
    }

    // Otherwise, dump the buffer and everything else until we get to c
    full = false;

    char ch = 0;
    while (cin >> ch)
    {
        if(ch == c) return;
    }
}