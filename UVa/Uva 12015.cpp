#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	string s[15];
	int t, n[15], i, max, c= 0;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	while(t--)
	{
		cin>>s[1];
		scanf("%d", &n[1]);
		max= n[1];
		for(i= 2; i<=10; i++)
		{
			cin>>s[i];
			scanf("%d", &n[i]);
			if(max<n[i])
                max= n[i];
		}
		printf("Case #%d:\n", ++c);
		for(i= 1; i<= 10; i++)
        {
            if(n[i]== max)
            {
                cout<<s[i]<<endl;
            }
        }
	}
	return 0;
}
