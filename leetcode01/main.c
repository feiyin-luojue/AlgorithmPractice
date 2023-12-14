#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE5 5
#define RAND_NUMS10 9
#define RAND_NUMS20 19

int main(int argc, char const *argv[])
{
    /*Example 1:
        随机生成数字 1-10，写入元素个数为 5 的数组 array[BUFFER_SIZE5]，
        随机生成数字 2-20，作为目标值 target
        判断数组array中是否有两个元素的和 sum 等于 target
        如果有，则返回 这两个元素的索引
    */
#if 0
    int array[BUFFER_SIZE5];
    memset(array, 0, sizeof(array));

    srand(time(NULL));
    for (int idx = 0;idx < BUFFER_SIZE5; idx++)
    {
        int temp = rand() % RAND_NUMS10 + 1;
        array[idx] = temp;
        printf("array[%d] = %d\n", idx, temp);
    }

    int target = rand() % RAND_NUMS20 + 2;
    printf("target = %d\n", target);

    int flag = 0;
    for (int idx = 0; idx < BUFFER_SIZE5 - 1; idx++)
    {
        for(int jdx = idx + 1; jdx < BUFFER_SIZE5; jdx++)
        {
            if ((array[idx] + array[jdx]) == target)
            {
                printf("\n-- array[%d] + array[%d] = target --\n", idx, jdx);
                printf("--     %d    +    %d     =   %d   --\n", array[idx], array[jdx], target);
                flag = 1;
            }
        }
    }

    if (flag == 0)
    {
        printf("\n-- array中没有两元素相加等于target --\n\n");
    }
#endif

    /*Example 2:
        数组 nums[] = {2, 7, 11, 15}，
        目标值 target = 9
        因为nums[0] + nums[1] == 9
        返回 [0, 1]。
        假设每种输入只会对应一个答案。
    */
#if 0
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int flag = 0;

    for(int idx = 0; idx < sizeof(nums) / sizeof(nums[0]) - 1 ; idx++)
    {
        for(int jdx = idx + 1; jdx < sizeof(nums) / sizeof(nums[0]); jdx++)
        {
            if (nums[idx] + nums[jdx] == target)
            {
                printf("[%d, %d]\n", idx,jdx);
                flag = 1;
                break ;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    if (flag == 0)
    {
        printf("nums中没有两元素相加等于target!\n");
    }
#endif

    /*Example 3:
        随机生成数字 1-20，写入元素个数为 5 的数组 array[BUFFER_SIZE5]，
        目标值 target = 22
        判断数组array中是否有两个元素的和 sum 等于 target
        如果有，则返回 这两个元素的索引
        只输出一个答案
        如果没有答案，返回[-1, -1]
    */
#if 1
    int nums[BUFFER_SIZE5];
    memset(nums, 0, sizeof(nums));
    int target = 22;

    srand(time(NULL));
    for (int idx = 0; idx < BUFFER_SIZE5; idx++)
    {
        int temp = rand() % RAND_NUMS20 + 1;
        nums[idx] = temp;
        printf("%d\n", nums[idx]);
    }

    int flag = 0;
    for (int idx = 0; idx < BUFFER_SIZE5; idx++)
    {
        for (int jdx = idx + 1; jdx < BUFFER_SIZE5; jdx++)
        {
            if (nums[idx] + nums[jdx] == target)
            {
                printf("[%d, %d]\n", idx, jdx);
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        
    }
    if (!flag)
    {
        printf("[-1, -1]\n");
    }
#endif

    return 0;
}
