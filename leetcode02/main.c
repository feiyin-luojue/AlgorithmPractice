#include <stdio.h>

/* 状态码 */
typedef enum STATUS_CODE
{
    SC_SUCCESS,
    SC_NULLPTR = -1,
} STATUS_CODE;

/*  冒泡排序 
        函数参数 nums:要排序的数组地址 
                len：要排序的数组地址的长度
*/
int bobleSort(int *nums, int len)
{
    if(!nums || len < 1)
    {
        return SC_NULLPTR;
    }

    int idxtail = len - 2;
    int jdxtail = len - 1;
    for (int idx = 0; idx < idxtail; idx++)
    {
        for (int jdx = idx + 1; jdx < jdxtail; jdx++)
        {
            
            if (nums[idx] > nums[jdx])
            {
                int temp = nums[idx];
                nums[idx] = nums[jdx];
                nums[jdx] = temp;
            }
        }
    }
    return SC_SUCCESS;
}

/*  以 %d\t 形式遍历整形数组 
        函数参数：
            array:要排序的数组地址 
            arrayLen：要排序的数组地址的长度 
*/
int printfArray(int *array, int arrayLen)
{
    if (!array || arrayLen < 1)
    {
        return SC_NULLPTR;
    }
    for (int idx = 0; idx < arrayLen; idx++)
    {
        printf("%d\t", array[idx]);

    }
    putchar(10);
    return SC_SUCCESS;
}

int main(int argc, char const *argv[])
{
/*  程序功能：    
        给定数组nums[] 7, 1, 4, 9, 2, 3 ,11= {}
        将数组中的元素按照从小到大的顺序排序
        得到nums[] = {1, 2, 3, 4, 7, 11}
*/
    int nums[] = {7, 1, 4, 9, 2, 3 ,11};
    int len = sizeof(nums) / sizeof(nums[0]);

    bobleSort(nums, len);
    printfArray(nums, len);
    return 0;
}
