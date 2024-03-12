/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    
    /* 
    Regular array instantiation falls of the stack with the function
    return. Malloc arrays need to be explcitly cleared with free()
    */
    int* returnArray = malloc(2 * sizeof(int));
    *returnSize =2;
    returnArray[0] = 0;
    returnArray[1] = 0;

    for(i = 0; i < numsSize; i++) {
        int intA = nums[i];

        for(j = i+1; j < numsSize; j++) {
            int intB = nums[j];
            if (intA + intB == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;

                return returnArray;
            }
        }
    }

    return returnArray;
}