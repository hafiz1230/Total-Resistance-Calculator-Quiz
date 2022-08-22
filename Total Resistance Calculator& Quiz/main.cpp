//MUHAMMAD HAFIZ BIN ZULKEPLI (KIE190053)
//AHMAD MUAZ BIN MUSA (KIE190003)
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
double resistance(string);
string randomgenerate();
void quiz();

int main()
{
    int choice;
    string formula;

    cout<<"* Welcome to Total Resistance Calculator Program***"<<endl;
    cout<<"1. Enter circuit formula."<<endl;
    cout<<"2. Generate circuit randomly."<<endl;
    cout<<"3. Show circuit formula."<<endl;
    cout<<"4. Calculate total resistance."<<endl;
    cout<<"5. Play a quiz."<<endl;

    while(choice!=-1)
    {
        cout<<"Your choice [1-5] :";
        cin>>choice;

        switch (choice)
        {
            case 1: cout<<"Enter circuit formula: ";
                    cin>>formula;
                    break;
            case 2:cout<<"Random circuit is generated:\n";
                    formula=randomgenerate();
                    break;
            case 3: cout<<"Circuit formula is "<<formula<<endl;;
                    break;
            case 4: cout<<"Circuit total resistance is "<<resistance(formula)<<" ohm\n";
                    break;
            case 5: cout<<"Quiz is selected."<<endl;
                    quiz();
                    break;
        }
    }
    return 0;
}

