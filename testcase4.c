#include <stdio.h>
#include <stdlib.h>

char* triangleType(int* nums, int numsSize) {
    if (numsSize != 3) {
        return "Invalid input";
    }

    if (nums[0] <= 0 || nums[1] <= 0 || nums[2] <= 0) {
        return "Invalid input";
    }

    if (nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0]) {
        return "Not a triangle";
    }
    if (nums[0] == nums[1] && nums[1] == nums[2]) {
        return "Equilateral";
    } else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
        return "Isosceles";
    } else {
        return "Scalene";
    }
}