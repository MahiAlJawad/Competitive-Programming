#include<iostream>//This one Wrong Answer.
using namespace std;

int main()
{
    char c;
    bool f= 1;

    while(cin>>c)
    {
        if(c== '"')
        {
            if(f)
                cout<< "``";
            else
                cout<< "''";
            f= (!f);
        }
        else
        {
            cout<< c;
        }
    }

    return 0;
}


/*This one is accepted. What is the difference between the previous one and this one?

#include<iostream>
#include<cstdio>

using namespace std;

int main()
{

    char c;
    bool ax=1;

    while(scanf("%c",&c)!=EOF)
    {
        if(c=='"')
        {
            if(ax) printf("``");
            else printf("''");

            ax=(!ax);
        }
        else printf("%c",c);
    }

    return 0;
}
*/
