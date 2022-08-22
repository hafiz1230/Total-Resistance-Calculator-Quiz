#ifndef RANDOM_H_INCLUDED
#define RANDOM_H_INCLUDED
#include <iostream>
#include <string>
#include<cstring>
#include <sstream>
#include <iomanip>
#include<ctime>
#include<cstdlib>
#include<bits/stdc++.h>

#include "quiz.h"
#include "resistance.h"
#include "random.h"

using namespace std;

string randomgenerate()
{
    int randomnum, randomparallelseries,value;
    string newformula,formulas, randomvalue,symbols;

    srand(time(0));
    randomnum=rand()%8+3;   //Randomize the number of resistors (3 to 8 resistors)

    if (randomnum>8)   //Limit the resistor
    randomnum=8;       //to up to 8 resistors

    while(randomnum>0)
    {
        value=rand()%100+10;             //Randomize the value of each resistor (10 to 100ohm)
        randomparallelseries=rand()%2+1; //Randomize the operations

        ostringstream strg;             //Insert the values into a string
        strg<<value;                    //Insert the values into a string
        string randomvalue=strg.str();  //Make it as a string

        //Assign the operation whether parallel or series
        if(randomparallelseries==1)    //If the random number is 1,therefore parallel ('/')
        {
            symbols="/";
        }

        else if(randomparallelseries==2)   //If the random number is 2,therefore series ('+')
        {
            symbols="+";
        }

        if (randomnum!=1)       //Insert value and symbol to only one string (To make a circuit Eg. 2/2+3/)
        {
            newformula +=randomvalue+symbols;
        }
        else if (randomnum==1)   //Finalize a complete string full of
        {                       //value and operations
            formulas=newformula+randomvalue;        //To make a complete full circuit (Eg. 2/2+3/3)
        }

    randomnum--;
    }

    return formulas;
}

#endif // RANDOM_H_INCLUDED
