/***
***/
#include<stdio.h>

int BinarySearch(int A[], int b, int e, int elem)//returns 'any' position of the elem
{
    int lo= b, hi= e, mid;
    while(lo<=hi)//decide the condition properly
    {
        mid= (lo+hi)>>1;
        /*
            decide when to do floor or ceil, we need to go/incline towards the solution
            and eliminate out of solution.
        */
        if(A[mid]== elem) return mid;
        else if(A[mid]>elem) hi= mid-1;//eliminating right part
        else if(A[mid]<elem) lo= mid+1;//eliminating left part
    }
    return -1;//if not found
}

int LowerBound(int A[], int b, int e, int elem)//returns the lower bound of the elem
{
    int lo= b, hi= e, mid;
    while(lo<hi)//decide the condition properly
    {
        mid= (lo+hi)>>1;
        /*
            decide when to do floor or ceil, we need to go/incline towards the solution
            and eliminate out of solution.
        */
        if(A[mid]== elem) hi= mid;//as high used to be decreased but we have not, hence taken floor of mid
        else if(A[mid]>elem) hi= mid-1;//eliminating right part
        else if(A[mid]<elem) lo= mid+1;//eliminating left part
    }
    return A[hi]==elem?hi:-1;
}
int UpperBound(int A[], int b, int e, int elem)//returns the Upper bound of the elem
{
    int lo= b, hi= e, mid;
    while(lo<hi)//decide the condition properly
    {
        mid= (lo+hi)%2== 0?(lo+hi)>>1:((lo+hi)>>1)+1;
        /*
            decide when to do floor or ceil, we need to go/incline towards the solution
            and eliminate out of solution.
        */
        if(A[mid]== elem) lo= mid;//as lo used to be increased but we have not hence we took ceil of mid
        else if(A[mid]>elem) hi= mid-1;//eliminating right part
        else if(A[mid]<elem) lo= mid+1;//eliminating left part
    }
    return A[lo]==elem?lo:-1;
}
int main()
{
    int arr[]= {1, 2, 2, 2, 3, 4, 7, 9};
    /*
    Lower bound of '2' is 1 i.e the first occurrence of 2
    Upper bound of '2' is 4 i.e the NEXT position after the last occurrence of 2
    */
    printf("Found %d\n", BinarySearch(arr, 0, 7, 3));
    printf("Lower bound of 2 : %d\n", LowerBound(arr, 0, 7, 2));
    printf("Upper bound of 2 : %d\n", UpperBound(arr, 0, 7, 2));
}
