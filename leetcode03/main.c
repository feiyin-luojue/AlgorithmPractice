#include <stdio.h>

int main(int argc, char const *argv[])
{
/*  程序功能：
        给定 非严格递增数组 nums[] = {1, 1, 2, 3, 7, 9, 9, 11}
        原地删除重复出现的元素，使每个元素 只出现一次
        得到 严格递增数组 nums[] = {1, 2, 3, 7, 9, 11} 
        元素的相对顺序应该保持一致，然后返回 nums 中唯一元素的个数 k。
*/  
    int nums[] = {1, 1, 2, 3, 7, 9, 9, 11};
    int len = sizeof(nums) / sizeof(nums[0]);
    int k = 0;
    for (int idx = 0; idx < len; idx++)
    {
        if (nums[idx] == nums[idx + 1])
        {
            for (int jdx = idx + 1; jdx < len ; jdx++)
            {
                nums[jdx] = nums[jdx + 1];
            }
            len--;
        }
    }
    k = len;
    printf("k:%d\n", k);

/* 遍历数组 */
#if 0
    for (int idx = 0; idx < k; idx++)
    {
        printf("nums[%d] = %d ", idx, nums[idx]);
    }
    printf("\n");
#else
    printf("nums[] = ");
    for(int idx = 0; idx < k; idx++)
    {
        printf("%d, ", nums[idx]);
    }
    putchar(10);
#endif
    return 0;
}
