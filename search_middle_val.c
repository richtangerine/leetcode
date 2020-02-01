/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start

#include <stdio.h>

#define MIN(x, y)          ((x) < (y) ? (x) : (y))

static double getSingleMiddleVal(int *nums, int numSize)
{ 
    int middle = numSize / 2;
    if (numSize % 2) {
        return nums[middle];
    } else {
        return (double)(nums[middle - 1] + nums[middle]) / 2.0;
    }
}

static void DebugPrintArray(char *arrayName, int *nums, int numsSize)
{
    int i;
    printf("%s, numsSize=%d\n", arrayName, numsSize);
    for (i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/*
2085/2085 cases passed (4 ms)
Your runtime beats 100 % of c submissions
Your memory usage beats 80.64 % of c submissions (7.6 MB)
*/
static double getMiddleValByCuttingOff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    double ret = 0.0;
    if ((nums1 == NULL) && (nums2 == NULL)) {
        return ret;
    } else if ((nums1Size == 0) && (nums2Size == 0)) {
        return ret;
    }

    if ((nums1 == NULL) || (nums1Size == 0)) {
        // printf("[%s_%d] k=%d, nums2=%d\n", __func__, __LINE__, k, nums2[k - 1]);
        return nums2[k - 1];
    } else if((nums2 == NULL) || (nums2Size == 0)) {
        // printf("[%s_%d] k=%d, nums1=%d\n", __func__, __LINE__, k, nums1[k - 1]);
        return nums1[k - 1];
    } else {
        // printf("both are not null\n");
    }
    int n = MIN(k / 2, MIN(nums1Size, nums2Size));
    int idx = n - 1;
    // DebugPrintArray("nums1", nums1, nums1Size);
    // DebugPrintArray("nums2", nums2, nums2Size);
    // printf("-----------k=%d, n=%d, nums1Size=%d, nums2Size=%d\n", k, n, nums1Size, nums2Size);

    if (k == 1) {
        if (nums1Size && nums2Size) {
            return MIN(nums1[0], nums2[0]);
        } else if (nums1Size) {
            return nums1[0];
        } else {
            return nums2[0];
        }
    }
    if (nums1[idx] < nums2[idx]) {
        ret = getMiddleValByCuttingOff(&nums1[n], nums1Size - n, nums2, nums2Size, k - n);
    } else if ((nums1[idx] == nums2[idx]) && (nums1Size < nums2Size)) {
        ret = getMiddleValByCuttingOff(&nums1[n], nums1Size - n, nums2, nums2Size, k - n);
    } else {
        ret = getMiddleValByCuttingOff(nums1, nums1Size, &nums2[n], nums2Size - n, k - n);
    }
    return ret;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double ret = 0.0;
    int k;
    if ((nums1 == NULL) && (nums2 == NULL)) {
        return ret;
    } else if ((nums1Size == 0) && (nums2Size == 0)) {
        return ret;
    }
    if ((nums1 == NULL) || (nums1Size == 0)) {
        return getSingleMiddleVal(nums2, nums2Size);
    } else if((nums2 == NULL) || (nums2Size == 0)) {
        return getSingleMiddleVal(nums1, nums1Size);
    } else {
        // printf("both are not null\n");
    }

    k = (nums1Size + nums2Size);
    ret = getMiddleValByCuttingOff(nums1, nums1Size, nums2, nums2Size, k / 2 + 1);
    
    if ((k % 2) == 0) {
        ret += getMiddleValByCuttingOff(nums1, nums1Size, nums2, nums2Size, k / 2);
        ret /= 2;
    }
    // printf("ret=%f\n", ret);
    return ret;
}


// @lc code=end

