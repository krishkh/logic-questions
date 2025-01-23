#include <stdio.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)  {
    int i = m - 1;
    int j = n - 1;
    if( n < 1){
        return;
    }
    int current = m+n - 1;
    while(current >= 0){
        if(i < 0){
            while (j >= 0){
                printf("Adding %d to %d\n", nums2[j], current);
                nums1[current] = nums2[j];
                j--;
                current--;
            }
            return;
        }
        else if(j < 0){
            while (i >= 0){
                printf("Adding %d to %d\n", nums1[i], current);
                nums1[current] = nums1[i];
                i--;
                current--;
            }
            return;
        }
        if (nums1[i] < nums2[j]){
            printf("Adding %d to %d\n", nums2[j], current);
            nums1[current] = nums2[j];
            j--;
        }
        else{
            printf("Adding %d to %d\n", nums1[i], current);
            nums1[current] = nums1[i];
            i--;
        }
        current--;
    }
}
void printArr(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int m = 3, n = 3;
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {4,5,6};
    printArr(nums1,m+n);
    printArr(nums2,n);
    merge(nums1,m+n, m,nums2,n,n);
    printArr(nums1,m+n);
    return 0;
}