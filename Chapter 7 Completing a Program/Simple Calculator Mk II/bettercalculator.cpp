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
    Token_stream ts;        // provides get() and putback()

    try
    {
        while (cin)
        {
            cout << "> ";                       // Print prompt

            Token t = ts.get();

            while(t.kind == ';') t = ts.get();  // Eat consecutive "print now" characters.
            if(t.kind == 'q')                   // 'q' for quit.  Always useful.
            {
                keep_window_open("~~");
                return 0;
            }
            ts.putback(t);
            cout << "=" << expression(&ts) << '\n';
        }

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