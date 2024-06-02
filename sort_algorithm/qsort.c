// this is used to write the quick sort function

#include<stdio.h>
#include<stdlib.h>

void swap(int*a , int*b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int arr[], int low, int high){
    
    int count=high-low-1;
    int i=low-1;
    // check and swap
    for (int j = 0; j <= count; j++)
    {
        if (arr[low+j]<arr[high])
        {
            i++;
            swap(&arr[i],&arr[low+j]);
        }
    }
    swap(&arr[high],&arr[i+1]);
    return (i+1);
    
}

void quicksort(int arr[], int low , int high){
    
    //check
    if (low<high)
    {
    int pi=partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
    }

    return ;
}
void printarray(int arr[], int n){
    for (int  i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return ;
    
}
int main(void){
    int arr[]={5 , 6 , 5 , 9 , 8 , 6 , 15};
    int n=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,n);
    quicksort(arr,0,n-1);
    printarray(arr,n);
    return 0;
}