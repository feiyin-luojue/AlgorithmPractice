#include <stdio.h>
#include <stdlib.h>

int *mergeorderNums(int *num1, int num1Size, int *num2, int num2Size, int newNumSize)
{
    int *newNum = (int *)malloc((num1Size + num2Size));
    int contnew = 0;
    int cont1 = 0;
    int cont2 = 0;
    for(int idx = 0; idx < newNumSize / sizeof(int); idx++)
    {
        if(num1[cont1] < num2[cont2] && cont1 < num1Size / sizeof(int))
        {
            newNum[contnew] = num1[cont1];
            contnew++;
            cont1++;
            continue;
        }
        else if (cont2 < num2Size / sizeof(int))
        {
            newNum[contnew] = num2[cont2];
            contnew++;
            cont2++;
            continue;
        }
        else 
        {
            newNum[contnew] = num1[cont1];
            contnew++;
            cont1++;
            continue;
        }
    }
    return newNum;


}

int main(int argc, char const *argv[])
{
/* 程序功能：
        给定两个数组
        num1[] = {1, 1, 2, 3, 3, 5}
        num2[] = {2, 7, 9, 12, 17}
        合并数组得到
        newNum[] = {1, 1, 2, 2, 3, 3, 5, 7, 7, 9, 12, 17, 19}
        返回新数组 newNumSize
 */
    int num1[] = {1, 1, 2, 3, 3, 5};
    int num2[] = {2, 7, 9, 12, 17};
    int num1Size = sizeof(num1);
    int num2Size = sizeof(num2);
    int newNumSize = num1Size + num2Size;
    int *newNum = mergeorderNums(num1, num1Size, num2, num2Size, newNumSize);
    for(int idx = 0; idx < newNumSize / sizeof(int); idx++)
    {
        printf("%d\t", newNum[idx]);
    }
    
    putchar(10);
    free(newNum);
    return 0;
}
