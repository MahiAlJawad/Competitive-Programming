#include<iostream>
#include<string>
using namespace std;

int main()
{
    string answer, guess;
    int n, i, j, stroke;

    while(cin>> n && n!= -1)
    {
        cin>> answer>> guess;
        stroke= 0;
        for(i= 0; answer[i]!= NULL; i++)
        {
            for(j= 0; guess[j]!= NULL; j++)
            {
                if(guess[j]== answer[i])
                    guess[j]= '1';
            }
        }
        for(i= 0; guess[i]!= NULL; i++)
        {
            if(guess[i]!= '1')
                stroke++;
        }
        if(stroke>=7)
        {
            cout<< "Round "<<n<<endl<< "You lose.\n";
        }
        else if(stroke== 0)
        {
            cout<< "Round "<<n<<endl<< "You win.\n";
        }
        else
            cout<< "Round "<<n<<endl<< "You chickened out.\n";
    }
    return 0;
}
