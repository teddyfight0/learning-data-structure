#include<stdio.h>
#include"sort.h"

// this program is  merge sort
#include <stdio.h>
#include <stdlib.h>

// 合并两个子数组 arr[left..mid] 和 arr[mid+1..right]
void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    // 创建临时数组
    int leftArr[leftSize], rightArr[rightSize];

    // 将数据复制到临时数组 leftArr[] 和 rightArr[]
    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    // 归并临时数组到 arr[left..right]
    int i = 0; // 初始化左子数组的起始索引
    int j = 0; // 初始化右子数组的起始索引
    int k = left; // 初始化归并子数组的起始索引
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // 复制 leftArr[] 的剩余元素，如果有的话
    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // 复制 rightArr[] 的剩余元素，如果有的话
    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// 使用归并排序排序数组 arr[left..right]
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // 找到中间点
        int mid = left + (right - left) / 2;

        // 递归排序两个子数组
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并已排序的子数组
        merge(arr, left, mid, right);
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 主函数测试
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printf("\nSorted array is \n");
    printArray(arr, arrSize);
    return 0;
}
