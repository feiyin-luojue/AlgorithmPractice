#include <stdio.h>

#define DAYS 7

int main(int argc, char const *argv[])
{
/*  程序功能：
    给定一个股票一周的估价情况：
    stockPrice[] = {7, 1, 4, 2, 5, 6, 3}
    计算出何时购入，何时抛售的收益最大
*/
    int stockPrice[DAYS] = {7, 1, 4, 2, 5, 6, 3};
    int MaxProfit = 0;      //最大收益
    int PurchaseDay = 0;        //购入日期
    int ShllDay = 0;        //抛售日期
    int bestPurchaseDay = 0;        //最佳购入日期
    int bestShllDay = 0;        //最佳抛售日期
    for (PurchaseDay = 0; PurchaseDay < DAYS - 1; PurchaseDay++)
    {
        for (ShllDay = 1; ShllDay < DAYS; ShllDay++)
        {
            int todayProfit = 0;        //当日收益
            todayProfit = stockPrice[ShllDay] - stockPrice[PurchaseDay];
            if (todayProfit > MaxProfit)
            {
                MaxProfit = todayProfit;
                bestPurchaseDay = PurchaseDay;
                bestShllDay = ShllDay;
            }
        }
    }
    printf("--\t 本 周 票 价 为\t\t--\n");
    printf("周一 周二 周三 周四 周五 周六 周日\n");
    for (int day = 0; day < DAYS; day++)
    {
        printf("  %d  ", stockPrice[day]);
    }
    putchar(10);
    printf("--\t 最佳购买日期为星期 %d\t--\n", bestPurchaseDay + 1);
    printf("--\t 最佳抛售日期为星期 %d\t--\n", bestShllDay + 1);
    printf("--\t   获 得 利 润 %d  \t--\n", MaxProfit);
    return 0;
}
