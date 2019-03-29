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

