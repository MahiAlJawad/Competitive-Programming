#include<bits/stdc++.h>
using namespace std;
int power(int x, int n)
{
	int ans= 1, i;
	for(i= 1; i<=n; i++) ans*= x;
	return ans;
}

int b2d(int x)
{
	int ans= 0, i= 0;
	while(x)
	{
		ans+= (x%10)*power(2, i);
		x/= 10;
		i++;
	}
	return ans;
}


int main ()
{
    int t, tc= 0, i, a, b, c, d, w, x, y, z;
    string f, s, m, n;
    scanf("%d", &t);
    while(t--)
    {
    	cin>>f>>s;
    	m= ""; n= "";
    	int flen= f.size();
    	for(i=0; i<flen; i++)
    	{
    		if(f[i]== '.') m+= " ";
    		else m+= f[i];
    	}

    	int slen= s.size();
    	for(i=0; i<slen; i++)
    	{
    		if(s[i]== '.') n+= " ";
    		else n+= s[i];
    	}

    	istringstream is(m);
    	is>>a; is>>b; is>>c; is>>d;

    	istringstream IS(n);
    	IS>>w; IS>>x; IS>>y; IS>>z;

    	if(a== b2d(w) && b== b2d(x) && c== b2d(y) && d== b2d(z))
    		printf("Case %d: Yes\n", ++tc);
    	else printf("Case %d: No\n", ++tc);

    }

    return 0;
}
