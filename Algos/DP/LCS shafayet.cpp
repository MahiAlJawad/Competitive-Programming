//Iterative one is more efficient in Runtime. @Cormen Page 394
#include<bits/stdc++.h>
#define MAXC 1000
using namespace std;
string A, B;
int dp[MAXC][MAXC];

int calcLCS(int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0') return 0;
	if(dp[i][j]!= -1)return dp[i][j];

	int ans=0;
	if(A[i]==B[j]) ans=1+calcLCS(i+1,j+1);
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		ans=max(val1,val2);
	}
	dp[i][j]=ans;
	return dp[i][j];
}

string ans;
void printAll(int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0'){
		cout<<ans<<endl;
		return;
	}
	if(A[i]==B[j]){
		ans+=A[i];
		printAll(i+1,j+1);
		ans.erase(ans.end()-1); //Delete last character(বুঝি নাই এম্নে :p )
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(i,j+1);
		else//এই  পার্টটা লাগবে না, যদি না সকল LCS প্রিন্ট দরকার হয়।
		{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}

int main()
{
    A= "HELLO";
    B= "LOXHE";
	memset(dp, -1, sizeof(dp));
	printf("LCS: %d\n",calcLCS(0,0));
	printAll(0, 0);
	return 0;
}
