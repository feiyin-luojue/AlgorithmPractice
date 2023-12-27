#include <stdio.h>
#include <string.h>

/* 删除字符串中的非字母元素 */
void delNot_A_or_a(char *ch)
{
    for(int idx = 0; ch[idx] != '\0'; idx++)
    {
        if ( (ch[idx] > 64 && ch[idx] < 90) || (ch[idx] > 96 && ch[idx] < 123) )
        {

        }
        else
        {
            for(int jdx = idx; ch[jdx] != '\0';jdx++)
            {
                ch[jdx] = ch[jdx + 1];
            }
        }
    }
}

/* 将字符串中的大写字母转化为小写字母 */
void change_A_to_a(char *ch)
{

}


int main(int argc, char const *argv[])
{
/*  程序功能：
        判断一个字母字符串是否是回数
        不区分大小写
        无视非字母符号
*/
    char ch1[] = "L0,e.1V-2/e3+L4*";
    char ch2[] = "sooNoos";
    delNot_A_or_a(ch1);

    int len = strlen(ch1);
    for (int idx = 0; idx < len; idx++)
    {
        printf("%c", ch1[idx]);
    }
    putchar(10);
    
    return 0;
}
