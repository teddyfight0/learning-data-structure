#include<stdio.h>
void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
/* void shellSort(int arr[],int n){
    for (int gap = n/2; gap > 0; gap/=2)
    {   
        for (int j = gap,count=0; j < n; j++,count++)
        {
            if (arr[j]<arr[count])
            {
                swap(&arr[j],&arr[count]);
            }
        }
    }
} */
// still have bugs , use the classic way
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printArr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(void){
    int arr[]={1,5,8,6,4,6,489,51,45,132,51,57,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArr(arr,n);
    shellSort(arr,n);
    printArr(arr,n);
    return 0;
}