//
// A simple command line calculator
//
// Yes, I'm aware "using namespace std" is bad practice; it's just how the header works
// I'm hoping Stroustrup will address this eventually.
//
// Created by John J. Hritz on 3/29/2019.
//

#include "bettercalculator.h"


int main()
{
    double val = 0;
    Token_stream ts;        // provides get() and putback()

    try
    {
        while (cin)
        {
            cout << "> ";                   // Print prompt

            Token t = ts.get();

            if(t.kind == 'q') break;        // 'q' for quit.  Always useful.

            if(t.kind == ';')               // ';' for print now.  Allows evaluation to be printed immediately after expression is entered.
            {
                cout << "=" << val << '\n';
            }
            else
            {
                ts.putback(t);
            }

            val = expression(&ts);
        }

        keep_window_open();
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...)
    {
        cerr << "exception \n";
        keep_window_open();
        return 2;
    }

}