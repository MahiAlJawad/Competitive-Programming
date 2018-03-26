/******************************************************************************************************************************
*** "In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge to whom he wants."      ***
***     Author     : Mahi Al Jawad                                                                                          ***
***     University : Dept. of CSE, IIUC                                                                                     ***
***     github     : https://github.com/MahiAlJawad                                                                         ***
***     Email      : br.mahialjawad@gmail.com                                                                               ***
***     facebook   : https://www.facebook.com/jawad.wretched                                                                ***
*******************************************************************************************************************************/

#include<bits/stdc++.h>
#define fin(in) freopen("in.txt", "r", stdin)
#define fout(out) freopen("out.txt", "w", stdout)
#define pb push_back
#define lng long long
#define lld I64d//for CF submissions
#define pi acos(-1.0)
#define dis(x1, y1, x2, y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define t_area(a, b, c, s) sqrt(s*(s-a)*(s-b)*(s-c));//  s= (a+b+c)/2.0
#define t_angle(a, b, c) acos((a*a+b*b-c*c)/(2*a*b))// returns angle C in radian. a, b, c are anti-clockwise formatted and side a and b form angle C
#define forit(it,s) for(__typeof((s).end()) it=(s).begin(); it!= (s).end(); it++)
#define gcd(a,b) __gcd(a,b)
#define string_reverse(s) reverse(s.begin(), s.end())//Vector also can be reversed with this function
using namespace std;

lng dirx[]= {-1, 0, 0, 0, 1};
lng diry[]= {0, -1, 0, 1, 0};

char grid[23][23];
struct cell
{
    lng x, y;
    char c;
};

lng bfs(cell s)
{
    lng i;
    cell u, v;
    queue<cell> q;
    q.push(s);

    lng cnt= 1;
    while(!q.empty())
    {
        u= q.front();
        q.pop();
        for(i= 0; i<5; i++)
        {
            lng x= u.x+ dirx[i];
            lng y= u.y+ diry[i];
            v.x= x;
            v.y= y;

            if(grid[x][y]== '.')
            {
                cnt++;
                grid[x][y]= 'x';
                q.push(v);
            }
        }
    }

    return cnt;
}


int main()
{
    lng tc, n, m, i, j, x, y, cs= 0;
    scanf("%lld", &tc);
    while(tc--)
    {
        scanf("%lld%lld", &n, &m);
        for(i= 0; i<=m+1; i++) grid[i][0]= 'x';
        for(i= 0; i<=n+1; i++) grid[0][i]= 'x';
        for(i= 0; i<=n+1; i++) grid[m+1][i]= 'x';
        for(i= 0; i<=m+1; i++) grid[i][n+1]= 'x';
        for(i= 1; i<=m; i++)
        {
            for(j= 1; j<=n; j++)
            {
                cin>>grid[i][j];
                if(grid[i][j]== '@')
                {
                    x= i;
                    y= j;
                }
            }
        }
        cell src;
        src.c= '@';
        src.x= x;
        src.y= y;
        lng ans= bfs(src);
        printf("Case %lld: %lld\n", ++cs, ans);
    }

    return 0;
}


