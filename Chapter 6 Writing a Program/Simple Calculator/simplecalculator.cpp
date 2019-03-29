//
// A simple command line calculator
//
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/29/2019.
//

/* Grammar
 *
    Expression:
          Term
          Expression "+" Term         // addition
          Expression "–" Term         // subtraction
    Term:
          Primary
          Term "*" Primary             // multiplication
          Term "/" Primary             // division
          Term "%" Primary             // remainder (modulo)
    Primary:
          Number
           "(" Expression ")"          // grouping
    Number:
          floating-point-literal
 */

#include "simplecalculator.h"

// deal with + and –.  Calls term() and get_token()
double expression()
{
    double left = expression();         // Evaluate another expression
    Token t = get_token();              // Get the next token

    switch (t.kind)                     // Determine token type
    {
        case '+':                       // Addition operator
            return left + term();       // Evaluate the next term and sum it with the left expression
        case '-':                       // Subtraction operator
            return left - term();       // Evaluate the next term and subtract it from the lest expression
        default:                        // The next token isn't an addition or subtraction operator.
            return left;
    }
}