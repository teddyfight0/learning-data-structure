#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int left, int mid, int right){
    // first give the space
    int leftsize=mid-left+1;
    int rightsize=right-mid;
    int *leftarr=(int*)malloc(sizeof(int)*leftsize);
    int *rightarr=(int*)malloc(sizeof(int)*rightsize);
    // copy the number
    for (int i = 0; i < leftsize; i++)
    {
        leftarr[i]=arr[left+i];
    }
    for (int j = 0; j < rightsize; j++)
    {
        rightarr[j]=arr[mid+j+1];
    }
    int i=0;
    int j=0;
    int k=left;
    // change the location of the num
    while(i<leftsize&&j<rightsize){
    if (leftarr[i]>=rightarr[j])
    {
        arr[k]=rightarr[j];
        j++;
    }
    else{
        arr[k]=leftarr[i];
        i++;
    }
    k++;
    }
    // copy the left numbers in the array
    while(i<leftsize){
        arr[k]=leftarr[i];
        i++;
        k++;
    }
    while(j<rightsize){
        arr[k]=rightarr[j];
        j++;
        k++;
    }
    free(leftarr);
    free(rightarr);
}

// use the merge function to select the numbers
void mergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        // 
        merge(arr,left,mid, right);
    }
}

int main(){
    int arr[]={5,2,6,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    
    mergeSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}