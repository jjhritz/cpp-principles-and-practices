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


Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        //not yet   case ';':    // for "print"
        //not yet   case 'q':    // for "quit"
        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
            return Token('n',val);   // let 'n' represent "a number"
        }
        default:
            error("Bad token");
    }
}


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


// deal with *, /, and %.  Calls primary() and get_token()
double term()
{
    double left = primary();
    Token t = get_token();

    while(true)
    {
        switch (t.kind)
        {
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("Divide by zero");
                left /= d;
                t = get_token();
                break;
            }
            default:
                return left;
        }
    }
}


// deal with numbers and parentheses.  Calls expression() and get_token()
double primary()
{
    Token t = get_token();
    switch (t.kind)
    {
        case '(':
        {
            double d = expression();
            t = get_token();

            if(t.kind != ')') error("')' expected.  Close your parentheses!");

            return d;
        }
        case 'n':       // use 'n' to represent numbers because...well, what else can we use?
            return t.value;
        default:
            error("Primary expected.  Check the grammar!");
    }
}