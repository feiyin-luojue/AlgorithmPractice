#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkList.h"

#define BUFFER_SIZE    3

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

int printNodeData(void *node)   //钩子函数，用于遍历链表中结点的数据
{
    DoubleLinkNode *tempNode = (DoubleLinkNode *)node;
    int *temp = (int *)&(tempNode->data);
    printf(" %d ", *temp);
    return ON_SUCCESS;
}

/*  函数功能：
    将两个升序链表合并为一个新的 升序 链表并返回。
    新链表是通过拼接给定的两个链表的所有结点组成的。
*/
DoubleLinkList* mergeTwoLinkList(DoubleLinkList* list1, DoubleLinkList * list2)
{
    DoubleLinkList *merge = NULL;
    DoubleLinkList *anotherlist = NULL;
    if (!(list1 && list2))
    {
        return (DoubleLinkList*)NULL_PTR;
    }

    if (*(int *)list1->head->next->data < *(int *)list2->head->next->data)
    {   
        merge = list1;
        anotherlist = list2;
    }
    else
    {
        merge = list2;
        anotherlist = list1;
    }
    
    
    DoubleLinkNode *travelNode = merge->head->next;     //主链中 将要被用于连接下一个新结点的位置

    DoubleLinkNode *travelNodeRemaining = merge->head->next;    //主链中 被断开的位置
    DoubleLinkNode *anotherRemaining = anotherlist->head->next; //被连接到主链的位置

    int lenth1 = 0;
    int lenth2 = 0;
    DoubleLinkListGetLength(list1, &lenth1);
    DoubleLinkListGetLength(list2, &lenth2);

    while (travelNode->next != NULL)
    {
        if (*(int *)(travelNode->next->data) < *(int *)(anotherRemaining->data))
        {
            travelNode = travelNode->next;
            continue;
        }
        travelNodeRemaining = travelNode->next;

        travelNode->next = anotherRemaining;
        if (anotherRemaining != NULL)
        {
            anotherRemaining->prev = travelNode;
        }
        travelNode = anotherRemaining;
        anotherRemaining = travelNodeRemaining;
    }
    travelNode->next = anotherRemaining;    //将剩下的最后一个结点连接到主链
    anotherRemaining->prev = travelNode;
    return merge;
}

int main(int argc, char const *argv[])
{
    DoubleLinkList *list1 = NULL;
    DoubleLinkList *list2 = NULL;
    DoubleLinkListInit(&list1);
    DoubleLinkListInit(&list2);

    int buf1[] = {1, 2, 4};
    int buf2[] = {1, 3, 4};

    int size1 = sizeof(buf1) / sizeof(buf1[0]);
    int size2 = sizeof(buf2) / sizeof(buf2[0]);

    for (int idx = 0; idx < size1; idx++)
    {
        DoubleLinkListTailInsert(list1, (void *)&buf1[idx]);
    }
    
    for (int idx = 0; idx < size2; idx++)
    {
        DoubleLinkListTailInsert(list2, (void *)&buf2[idx]);
    }
    
    printf("list1: ");
    DoubleLinkListForeach(list1, printNodeData);
    putchar(10);

    printf("list2: ");
    DoubleLinkListForeach(list2, printNodeData);
    putchar(10);

    DoubleLinkList *merge = mergeTwoLinkList(list1, list2);
    printf("merge: ");
    DoubleLinkListForeach(merge, printNodeData);
    putchar(10);

    return 0;
}
