#include<bits/stdc++.h>
using namespace std;

int BS(vector<int> v, int key)
{
    int beg, end, mid, index;
    beg= 0;
    end= v.size()-1;
    while(beg<= end)
    {
        mid= (beg+end)/2;
        if(key== v[mid])
        {
            index= mid;
            end= mid-1;//Alternately we can break and return, but we want
                    //the position of the left most value equals to key
                    //case of having multiple value equals to key.
        }
        else if(key>v[mid])
            beg= mid+1;
        else
            end= mid-1;
    }
    return index;
}

int main()
{
   int array[]= {10, 20 , 20, 30, 30, 40, 50};
   vector<int> v(array, array+ sizeof(array)/sizeof(array[0]));
   int element= 20;
   if(binary_search(v.begin(), v.end(), element))
        printf("%d is found at the position %d\n", element, BS(v, element));
   else
        printf("%d is not found\n", element);
    vector<int> ::iterator it1, it2;
    it1= upper_bound(v.begin(), v.end(), element);
    it2= lower_bound(v.begin(), v.end(), element);
    printf("The Upper Bound for %d is %d \n", element, it1-v.begin());//v.begin= 0, it1 minus v.begin gives the position
    printf("The Lower Bound for %d is %d \n", element, it2-v.begin());

    return 0;
}
