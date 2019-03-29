//
// Parses the grammar of the simple calculator
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
    Primary:
          Number
           "(" Expression ")"          // grouping
    Number:
          floating-point-literal
 */

#include "calcparser.h"

Token_stream ts;        // provides get() and putback()


// deal with + and –.  Calls term() and get_token()
double expression()
{
    double left = term();               // Evaluate another term.  Calling Expression again results in infinite recursion.
    Token t = ts.get();                 // Get the next token from the token stream

    while(true)
    {
        switch (t.kind)                     // Determine token type
        {
            case '+':                       // Addition operator
                left += term();             // Evaluate the next term and sum it with the left expression
                t = ts.get();
                break;
            case '-':                       // Subtraction operator
                left -= term();             // Evaluate the next term and subtract it from the lest expression
                t = ts.get();
                break;
            default:                        // The next token isn't an addition or subtraction operator.
                ts.putback(t);              // Put the token back in the token stream for someone else to evaluate.
                return left;                // Return the answer.
        }
    }
}


// deal with *, /, and %.  Calls primary() and get_token()
double term()
{
    double left = primary();
    Token t = ts.get();

    while(true)
    {
        switch (t.kind)
        {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("Divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}


// deal with numbers and parentheses.  Calls expression() and get_token()
double primary()
{
    Token t = ts.get();
    switch (t.kind)
    {
        case '(':
        {
            double d = expression();
            t = ts.get();

            if(t.kind != ')') error("')' expected.  Close your parentheses!");

            return d;
        }
        case 'n':       // use 'n' to represent numbers because...well, what else can we use?
            return t.value;
        default:
            error("Primary expected.  Check the grammar!");
    }
}