#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    for(int i= 1; i<=10; i++)
        v.push_back(i);

    int elem= 10;
    if(find(v.begin(), v.end(), elem)!= v.begin()) printf("The element is in the vector.\n");
    else printf("There is not\n");

    return 0;
}
