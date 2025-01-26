#include <stdio.h>

int canJump(int* nums, int numsSize) {
    int maxJump = nums[0];
    for(int i = 1; i <= maxJump; i++){
        if (i >= numsSize-1){
            return 1;
        }
        if (maxJump < nums[i]+i){

        maxJump = nums[i] + i;
        }
        printf("max jump is %d\n",maxJump);
    }
    return maxJump >= numsSize-1;
}


int main(){
    int nums[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    // int nums[] = {1,1,2,2,0,1,1};
    // int nums[] = {3,0,8,2,0,0,1,0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    printf("size of array nums is: %d\n",numsSize);
    printf("output: %d",canJump(nums,numsSize));
    return 0;
}