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
    double left = term();               // Evaluate another term.  Calling Expression again results in infinite recursion.
    Token t = get_token();              // Get the next token

    while(true)
    {
        switch (t.kind)                     // Determine token type
        {
            case '+':                       // Addition operator
                left += term();             // Evaluate the next term and sum it with the left expression
                t = get_token();
                break;
            case '-':                       // Subtraction operator
                left -= term();             // Evaluate the next term and subtract it from the lest expression
                t = get_token();
                break;
            default:                        // The next token isn't an addition or subtraction operator.
                return left;                // Return the answer.
        }
    }

}