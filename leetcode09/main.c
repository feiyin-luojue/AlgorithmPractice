#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicArrayStack.h"

#define BUFFERSIZE 5
#define LEGITIMATE 0    //字符串合法
#define NOLEGITIMATE -1     //字符串不合法
/*  函数功能：
    给定一个只包括'(', ')', '[', ']', '{', '}' 的字符串 s
    判断字符串是否有效。
    有效字符串需满足：
    1.左括号必须用相同类型的右括号闭合。
    2.左括号必须以正确的顺序闭合。
    3.每个右括号都有一个对应的相同类型的左括号。
*/
int estimateArrayIfLegitimate(char *array)      //判断字符串是否合法，合法返回1，不合法返回0
{
    dynamicArrayStack *symbolStack = (dynamicArrayStack *)malloc(sizeof(dynamicArrayStack) * 1);
    memset(symbolStack, 0, sizeof(dynamicArrayStack) * 1);
    char *ptr = array;
    char *temp = (char *)malloc(sizeof(char));
    while (*ptr != '\0')
    {
        if (*ptr == '(' || *ptr == '[' || *ptr == '{')
        {
            dynamicArrayStackPush(symbolStack, (void *)ptr++);
            continue;
        }
        else
        {
            #if 0
            if (*ptr == ')')
            {
                dynamicArrayStackTop(symbolStack, (void**)&temp);
                //printf("temp = %c\n", *temp);
                if (*temp != '(')
                {
                    return NOLEGITIMATE;
                }
                else
                {
                    dynamicArrayStackPop(symbolStack);
                }
            }

            if (*ptr == ']')
            {
                dynamicArrayStackTop(symbolStack, (void **)&temp);
                //printf("temp = %c\n", *temp);
                if (*temp != '[')
                {
                    return NOLEGITIMATE;
                }
                else
                {
                    dynamicArrayStackPop(symbolStack);
                }
            }

            if (*ptr == '}')
            {
                dynamicArrayStackTop(symbolStack, (void**)&temp);
                //printf("temp = %c\n", *temp);
                if (*temp != '{')
                {
                    return NOLEGITIMATE;
                }
                else
                {
                    dynamicArrayStackPop(symbolStack);
                }
            }
            ptr++;
        #else       //优化
            dynamicArrayStackTop(symbolStack, (void**)&temp);
            if (*ptr == ')' && *temp == '(' || *ptr == ']' && *temp == '[' || *ptr == '}' && *temp == '{')
            {
                dynamicArrayStackPop(symbolStack);
                ptr++;
            }
            else
            {
                dynamicArrayStackDestroy(symbolStack);
                return NOLEGITIMATE;
            }
        #endif
        }
    }

#if 0
    if (dynamicArrayStackIsEmpty(symbolStack) == 1)
    {
        dynamicArrayStackDestroy(symbolStack);
        return LEGITIMATE;
    }
    else
    {
        dynamicArrayStackDestroy(symbolStack);
        return NOLEGITIMATE; 
    }
#else   //优化
    int stackIfEmpty = dynamicArrayStackIsEmpty(symbolStack);
    dynamicArrayStackDestroy(symbolStack);
    return stackIfEmpty == 1 ? LEGITIMATE : NOLEGITIMATE;
#endif
}

int printfifLegitimats(char *array)       //判断并显示字符串合法性的判断结果
{
    int ifLegitimats = estimateArrayIfLegitimate(array);
    if (ifLegitimats == LEGITIMATE)
    {
        printf("字符串合法\n");
    }
    else if (ifLegitimats == NOLEGITIMATE)
    {
        printf("字符串不合法\n");
    }
    else
    {
        printf("ifLegitimats = %d\n", ifLegitimats);
    }
    return ifLegitimats;
}


int main()
{
    char array1[] = {'(', '{', '[', ']', '}', ')'};      //合法示例
    char array2[] = {'(', '[', ']', ')', '(', '[', '{', '}', ']', ')'};      //合法示例
    char array3[] = {'(', '[', ']'};     //数量导致的 不合法示例  
    char array4[] = {'(', '(', ')', ']'};    //括号不匹配导致的 不合法示例
    char array5[] = {'(', '[', ')', ']'};    //括号位置错乱导致的 不合法示例

    printfifLegitimats(array2);     //判断并显示字符串合法性的判断结果

    return 0;
}