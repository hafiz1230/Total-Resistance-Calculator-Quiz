#ifndef QUIZ_H_INCLUDED
#define QUIZ_H_INCLUDED
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

void quiz()
{
    int mark=0 ;     //Initialize mark as zero

    double answer[5];
    for(int i=0;i<5;i++)
    {
        double user_ans[i];
        string str=randomgenerate();    //Call function to generate random circuit
        answer[i]=resistance(str);

        cout<<"\nCircuit "<<i+1<<" formula is "<<str;
        cout<<"\nEnter circuit "<<i+1<<" total resistance: ";
        cin>>user_ans[i];                //User input their own answer

        if(i!=4)
        {
            cout<<"\n...Repeat "<<5-i<<" more times to complete the games...\n"<<endl;;
        }

        if(user_ans[i]>=answer[i]-0.5 && user_ans[i]<=0.5+answer[i])     //Range of answer that are allowed and correct (-0.5<ans<+0.5)

        {
            mark++;     //Mark correct answer
        }

    }

    cout<<"\nYour mark for this quiz is "<<mark<<"/5 ";
    for(int i=0;i<5;i++)
    {

        cout<<"\nThe answer for circuit "<<i<<" is "<< setprecision(2)<<fixed<<answer[i];       //Display the correct answer with precision 2
    }
    cout<<endl;
}



#endif // QUIZ_H_INCLUDED
