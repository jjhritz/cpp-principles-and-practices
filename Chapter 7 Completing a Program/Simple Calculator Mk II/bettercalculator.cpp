//
// A simple command line calculator
// Takes input via cin, through a custom Token_stream called ts.
//
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/29/2019.
//

/* Grammar
 *
    Statement:
        Expression
        Print
        Quit
    Print:
        ;
    Quit
        q
    Expression:
          Term
          Expression "+" Term           // addition
          Expression "–" Term           // subtraction
    Term:
          Primary
          Term "*" Primary              // multiplication
          Term "/" Primary              // division
          Term "%" Primary              // Floating-point modulo
    Primary:
          Number
           "(" Expression ")"           // grouping
           "-" Primary                  // unary negative
           "+" Primary                  // unary positive
    Number:
          floating-point-literal
 */

#include "bettercalculator.h"


int main()
{
    try
    {
        calculate();
        keep_window_open("~~");
        return 0;
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        keep_window_open("~~");
        return 1;
    }
    catch (...)
    {
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }
}


void calculate()
{
    const string prompt = ">";
    const string result = "=";
    Token_stream ts;        // provides get() and putback()

    while (cin)
    try
    {
        cout << prompt;                       // Print prompt

        Token t = ts.get();

        while(t.kind == ts.print) t = ts.get();  // Eat consecutive "print now" characters.
        if(t.kind == ts.quit)
        {
            keep_window_open("~~");
        }
        ts.putback(t);
        cout << result << expression(&ts) << '\n';
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        clean_input(&ts);
    }

}

void clean_input(Token_stream* ts)
{
    // Dump the problematic expression
    ts->ignore(ts->print);
}
