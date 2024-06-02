#include<stdio.h>
#include"sort.h"

void change(int*a,int *b){
    int t=*a;
    *a=*b;
    *b= t;
// change the value
}


void heapify(int arr[], int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    //check part
    if(left<n&&arr[left]>arr[largest]) {
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest]) {
        largest=right;
    }
    if (largest!=i) {
    change(&arr[largest],&arr[i]);
    heapify(arr,n,largest);
    }
    
}

void build_heap(int arr[], int n){
    for (int i =n/2-1 ; i >= 0 ; i--)
    {
        heapify(arr,n,i);
    }
}
int main(void){
    int a[5]={1,2,3,2,1};
    int leng=sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < leng; i++)
    {
        printf("%d\n",a[i]);
    }
    build_heap(a,leng);
    for (int i = 0; i < leng; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}