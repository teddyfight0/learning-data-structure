#include<stdio.h>
#include "sort.h"
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