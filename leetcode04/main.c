#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randNum10 10

int main()
{
/*  程序功能：
    随机生成一个数组 nums[]
    从键盘输入数组 nums[] 的长度 numsSize 和一个值 val，
    原地 移除所有数值等于 val 的元素
    并返回移除后数组的新长度。
*/
    int numsSize = 0;
    int val = 0;

    srand(time(NULL));
    printf("请输入数组长度：\n");
    scanf("%d", &numsSize);
    printf("请输入要删除的元素：\n");
    scanf("%d", &val);

    int *nums = (int *)malloc(sizeof(int) * numsSize);

    printf("生成长度为 %d 的数组:\n", numsSize);
    printf("nums[]: ");
    for (int idx = 0; idx < numsSize; idx++)
    {
        nums[idx] = rand() % randNum10 + 1;;
        printf("%d ", nums[idx]);
    }
    putchar(10);
    for (int idx = 0; idx < numsSize; idx++)
    {
        if (nums[idx] == val)
        {
            for (int jdx = idx; jdx < numsSize - 1; jdx++)  //一定要减 1 ，否则会导致内存泄漏
            {
                nums[jdx] = nums[jdx + 1]; 
            }
            idx--;
            numsSize--;
        }
    }
    printf("删除val: %d 后，数组变为：\n", val);
    printf("nums[]: ");
    for (int idx = 0; idx < numsSize; idx++)
    {
        printf("%d ", nums[idx]);
    }
    putchar(10);

    free(nums);

    return 0;
}