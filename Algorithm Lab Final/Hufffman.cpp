#include<bits/stdc++.h>
using namespace std;
int n= 5;//Let's say there are n characters

struct node
{
    int freq;
    node left;
    node right;
    char c;

    bool operator <(const node &b)
    {
        return freq< b.freq;
    }
};

priority_queue <node, vector<int>, greater<int> > pq;

node huffman()
{
    int i;
    printf("Enter %d frequencies and their characters: ", n);
    for(i= 0; i<n; i++)
    {
        int x;
        char c;
        node y;
        scanf("%d", &x);
        cin>> c;
        y.freq= x;
        y.c= c;
        pq.push(y);
    }

    while(pq.size()!= 1)
    {
        node a= pq.top();
        pq.pop();
        node b= pq.top();
        pq.pop();
        node z;
        z.freq= a.freq+ b.freq;
        z.left= a;
        z.right= b;
        pq.push(z);
    }
    return pq.top();
}

int main()
{
    node x= huffman();
    return 0;
}


