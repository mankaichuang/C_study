#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Listnode;

/*头节点包含数据*/
Listnode *creatList(int n, int data[])
{
    int i;
    Listnode *head, *node, *end;    
    head = (Listnode *)malloc(sizeof(Listnode));
    head->value = data[0];      //头节点包含数据，所以将第一个数据给头节点
    end = head;
    for(i = 1; i<n; i++){       //保存其他数据
        node = (Listnode *)malloc(sizeof(Listnode));
        node->value = data[i];
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}

/*  打印节点内容
*   返回值为数据长度
*/
int printList(Listnode *head)
{
    int i = 0;
    Listnode *p = head;
    while(p != NULL){
        printf("%d ",p->value);
        p = p->next;
        i++;
    }
    printf("\n");
    return i;
}

/*  删除节点
*   head为头节点,头节点含数据；
*   data为要删除数据为data的节点
*/
Listnode *delnode(Listnode *head, int data)
{
    Listnode *p, *temp;
    p = head;
    if(p != NULL){              
        if(p->value == data){    //如果要删除的是头节点数据
            head = p->next;     //将头节点指向下一个节点
            free(p);
            return head;
        }else{
            temp = p;           //保存当前节点
            p = p->next;        //p指向下一个节点
        }
    }
    while(p != NULL){
        if(p->value == data){          //如果要删除的是当前P节点数据
            temp->next = p->next;     //将上一节点指向下一个节点
            free(p);                  //释放p的空间
            return head;
        }else{
            temp = p;                 //保存当前节点
            p = p->next;              //p指向下一个节点
        }
    }
    return head;
}

int main(void)
{
    int n = 5;
    int data[5] = {1,2,3,4,5};
    int len = 0;
    Listnode *head = NULL;
    head = creatList(n, data);
    len = printList(head);
    printf("%d\n",len);
    head = delnode(head, 1);
    len = printList(head);
    printf("%d\n",len);
}