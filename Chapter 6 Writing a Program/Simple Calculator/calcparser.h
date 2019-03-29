//
// Created by John J. Hritz on 3/29/2019.
//

#ifndef PRINCIPLES_AND_PRACTICES_CALCPARSER_H
#define PRINCIPLES_AND_PRACTICES_CALCPARSER_H

#include "Token.h"

// functions to match the grammar rules:
double expression(Token_stream *ts);        // deal with + and –.  Calls term() and get_token()
double term(Token_stream *ts);              // deal with *, /, and %.  Calls primary() and get_token()
double primary(Token_stream *ts);           // deal with numbers and parentheses.  Calls expression() and get_token()

#endif //PRINCIPLES_AND_PRACTICES_CALCPARSER_H
