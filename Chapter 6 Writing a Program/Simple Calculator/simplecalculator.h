//
// Created by John J. Hritz on 3/29/2019.
//

#ifndef PRINCIPLES_AND_PRACTICES_SIMPLECALCULATOR_H
#define PRINCIPLES_AND_PRACTICES_SIMPLECALCULATOR_H

#include "Token.h"

// functions to match the grammar rules:
Token get_token();          // read characters and compose tokens.  Uses cin
double expression();        // deal with + and –.  Calls term() and get_token()
double term();              // deal with *, /, and %.  Calls primary() and get_token()
double primary();           // deal with numbers and parentheses.  Calls expression() and get_token()


#endif //PRINCIPLES_AND_PRACTICES_SIMPLECALCULATOR_H
