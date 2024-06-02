#include<stdio.h>
#include<string.h>
#include "sort.h"

void change(int*a,int *b){
    int t=*a;
    *a=*b;
    *b= t;
// change the value
}

void bubble_sort(int *aim,int leng){
    for (int i = 0; i < leng-1; i++)
    {
        int sign=0;
        for (int j = 0; j < leng-i-1; j++)
        {
            if (aim[j]<aim[j+1]){
             change(&aim[j],&aim[j+1]);
             if(sign!=1) sign=1;
        }
        }
        if (sign==0) break;   
    }
    
}
// improved bubble sort
