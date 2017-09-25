#include<bits/stdc++.h>
#define m 50
using namespace std;

int dp[m][m];
bool visited[m][m];
string A, B, L;

int LCS(int i, int j)
{
    if(A[i]== '\0' || B[i]== '\0') return 0;
    if(visited[i][j]) return dp[i][j];

    int ans= 0;
    if(A[i]== B[j]) ans= 1+ LCS(i+1, j+1);
    else
    {
        int x= LCS(i+1, j);
        int y= LCS(i, j+1);
        ans= max(x, y);
    }
    visited[i][j]= 1;
    dp[i][j]= ans;
    return dp[i][j];
}

void printLCS(int i, int j)
{
    if(A[i]== '\0' || B[i]== '\0')
    {
        cout<< L<< '\n';
        return;
    }
    if(A[i]== B[i])
    {
        L+= A[i];
        printLCS(i+1, j+1);
    }
    else
    {
        if(dp[i+1][j]> dp[j+1][i]) printLCS(i+1, j);
        else printLCS(i, j+1);
    }
}

int main()
{
    getline(cin, A);
    getline(cin, B);
    printf("Length of the LCS: %d", LCS(0, 0));
    printf("\nThe LCS: ");
    printLCS(0, 0);
}

