#ifndef RESISTANCE_H_INCLUDED
#define RESISTANCE_H_INCLUDED
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

double resistance(string tempformula)
{
    double total=0;
    double r=0;
    double value[100];
    char valueoperation[100];
    int counts=1;

    string s=tempformula;
    int n=s.length();       //Find the total elements in string s
    char char_array[n+1];

    stringstream assignation (tempformula); //To parse this string

    strcpy(char_array,s.c_str());   //Convert string into character

    for(int i=0;i<n;i++)
    {
        if((char_array[i]=='+')||(char_array[i]=='/'))
        {
            counts++;       //Count the number of operation
        }
    }

    for(int i=0;i<counts;i++)
    {
        assignation>>value[i];          //Assign the value of resistor in array value[]
        assignation>>valueoperation[i]; //Assign the operations into its array

    }

    for(int i=0;i<counts;i++)     //For loop to calculate parallel resistance
    {
        if(valueoperation[i]=='/')
        {
            while(valueoperation[i]=='/')
            {
                r+=1/value[i];
                i++;
            }
            if(valueoperation[i]!='/')
            {
                r+=1/value[i];
                total+=1/r;      //Sum up total resistance
                r=0;
                continue;
            }
        }
        else
        {
            r=0;
            continue;
        }
    }

    for (int i=0;i<counts;i++)     //For loop to calculate series resistance
    {
        if(valueoperation[i]=='/'||valueoperation[i-1]=='/')
        {
            continue;
        }
        else
            total+=value[i];     //Sum up total resistance

    }
    return total;
}


#endif // RESISTANCE_H_INCLUDED
