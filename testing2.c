#include <stdio.h>

int canJump(int* nums, int numsSize) {
    int travel = 0;
    int lowerLimit = nums[0];
    int lowerLimitOccurence = 0;
    int offset = 0;
    for(int i = 0; i < numsSize-1; i += travel){
        // here if we travelled back we would have the offset
        travel += nums[i] - offset;
        // if we reach at last location or above it if we bailin
        if (nums[travel] >= numsSize-1){
            return 1;
        }
        // if we encounter a 0, we travel back
        if (nums[travel] == 0){
            travel -= nums[i];
            offset++;
        }
    }
    return 1;
}

int main(){
    int nums[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    printf("output: %d",canJump(nums,numsSize));
    return 0;
}