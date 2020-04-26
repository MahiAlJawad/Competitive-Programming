/***
Sorting library with complexity O(nlg(n))
***/
#include<stdio.h>

void merge(int A[], int b, int mid, int e)
{
    int p= b;
    int q= mid+1;
    int k= 0;
    int arr[e-b+1];
    //now we will generate a new arr[] merging the two arrays
    for(int i= b; i<=e; i++)//as we know the total elements are (e-b+1) in count
    {
        if(p>mid) arr[k++]= A[q++];//first array is taken already
        else if(q>e) arr[k++]= A[p++];//second array is taken already
        else if(A[p]<A[q]) arr[k++]= A[p++];
        else arr[k++]= A[q++];
    }
    //reassigning the new arr[] to our original array sorted
    for(int i= 0; i<k; i++)
    {
        A[b++]= arr[i];
    }
}
void mergeSort(int A[], int b, int e)
{
    if(b<e)
    {
        int mid= (b+e)>>1;
        mergeSort(A, b, mid);
        mergeSort(A, mid+1, e);
        merge(A, b, mid, e);
    }
}

int main()
{
    int arr[]= {2, 54, 1, 45, 8};
    mergeSort(arr,0, 4);
    printf("Sorted array: \n");
    for(int i= 0; i<5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
