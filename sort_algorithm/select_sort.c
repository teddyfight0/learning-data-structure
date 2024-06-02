#include<stdio.h>

void swap(int*a,int*b){
    int t=*a;
    *a =*b;
    *b =t;
}
void selection(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=arr[i];
        int loc=i;
        for (int j = i; j < n; j++)
        {
            if (arr[j]<min)
            {
                min=arr[j];
                loc=j;
            }
            
        }
        swap(&arr[loc],&arr[i]);
    }
}
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}
int main(void){
    int arr[]={1,5,4,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    selection(arr,n);
    printArray(arr,n);
    return 0;
}