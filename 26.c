#include <stdio.h>


int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0;  // index for last unique element
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];  // place the unique element forward
        }
    }
    return i + 1; // new length
}


int main() {
    // Example input array
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int n = sizeof(nums)/sizeof(nums[0]);

    // Call function
    int k = removeDuplicates(nums, n);

    // Print result
    printf("New length: %d\n", k);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}