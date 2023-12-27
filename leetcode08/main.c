#include <stdio.h>
#include <string.h>

enum ERRORCODE
{
    RUNSUCCESS = 0,
    NULLERROR = -1,
    OTHERERROR = -2,
};

/*  交换两个指针位置上的字符    */
void changChar(char *left, char *right)
{
    char tempchar = *left;
    *left = *right;
    *right = tempchar;
}

/*  翻转两个指针之间的所有元素
    （abcde -> edcba）  */
void overturnDataBetweenTowPointer(char *left, char *right)
{
    char *templeft = left;
    char *tempright = right;
    while (*templeft != *tempright)
    {
        // char tempchar = *tempArray;
        // *tempArray = *arrayEnd;
        // *arrayEnd = tempchar;
        changChar(templeft, tempright);
        // if (templeft == tempright)
        // {
        //     break;
        // }
        templeft++;
        if (templeft == tempright)
        {
            break;
        }
        tempright--;
        if (templeft == tempright)
        {
            break;
        }
    }
}

/*  将字符串 “abcd” 
    翻转为 “dcba”   */
void exchangePosition(char *array)
{
    char *tempArray = array;

    char *arrayEnd = array;
    while (*(++arrayEnd + 1) != '\0');  //指针后移，找到最后一个 非\0 的元素
/*
    while (1)
    {
        // char tempchar = *tempArray;
        // *tempArray = *arrayEnd;
        // *arrayEnd = tempchar;
        changChar(tempArray, arrayEnd);
        tempArray++;
        if (tempArray == arrayEnd)
        {
            break;
        }
        arrayEnd--;
        if (tempArray == arrayEnd)
        {
            break;
        }
    }
*/
    overturnDataBetweenTowPointer(tempArray, arrayEnd);
}


/*  给定一个字符串
    array[] = " I   am  from china    "
    实现字符串内单词的翻转，得到
    newArray[] = "    china from  am   I "*/
void *changeWord(char *array, int sizeofArray)
{
   exchangePosition(array);
   char *tempArray = array;
   while (*tempArray != '\0')
   {
        if(*tempArray == ' ')
        {
            tempArray++;
        }
        else
        {
            char *thisWordHead = tempArray;

            char *thisWordEnd = tempArray;
            while (*(thisWordEnd + 1) != ' ')
            {
                thisWordEnd++;
            }
            overturnDataBetweenTowPointer(thisWordHead, thisWordEnd);
            if (*(thisWordEnd + 1) != '\0')
            {
                tempArray = thisWordEnd + 1;
            } 
        }
}
}





int main(int argc, char const *argv[])
{
/*  程序功能：
    给定一个字符串
    array[] = " I   am  from china    "
    实现字符串内单词的翻转，得到
    newArray[] = "    china from  am   I "
*/
    char array[] = " I   am  from china    ";
    int sizeofArray = sizeof(array);

    changeWord(array, sizeofArray);

    printf("%s\n", array);
    return 0;
}
