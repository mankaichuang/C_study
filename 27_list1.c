/*
*   头节点不包含数据的情况
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Listnode;


/*链表的创建就，头节点不数据*/
static Listnode *creatList(int n, int data[])
{
    Listnode *head, *node, *end;
    int i = 0;

    head = (Listnode *)malloc(sizeof(Listnode));    //申请头节点空间
    end = head;

    for(i = 0; i<n; i++){
        node = (Listnode *)malloc(sizeof(Listnode));   //申请节点空间
        node->value = data[i];          //给节点赋值
        end->next = node;               //将前一个节点指向当前节点
        end = node;                     //将当前节点设置为尾节点
    }
    end->next = NULL;
    return head;
}

/*打印链表数据*/
static int printList(Listnode *head)
{
    Listnode *p;
    int count = 0;

    p = head->next;     //将p指向数据节点
    while(p != NULL){   //如果该数据节点不为空
        printf("%d ", p->value); //打印数据
        p = p->next;    //指向一下节点
        count++;            //计数器+1
    }
    printf("\n");
    
    return count;
}

/*删除第n个节点*/
static int delnode_for_num(Listnode *head, int n)
{
    Listnode *p, *temp;
    int i = 0;

    p = head;       //p指向头节点
    if(n > 0){      //n要大于0
        while(p->next != NULL && n){    //如果下一个节点不为空并且n不为0
            temp = p;
            p = p->next;
            n--;
        }
        if(n>0){                    //如果遍历完成，n还大于0，说明节点不存在
            return 0;               //返回0
        }
        if(p->next != NULL){        //如果删除的是中间节点
            temp->next = p->next;   //将前一个节点指向下一个节点
            free(p);                //释放当前节点
            return 1;
        }else{                      //如果删除的是尾节点
            temp->next = NULL;      //将前一个节点的next设为NULL
            free(p);                //释放当前节点
            return 1;
        }
    }else{                          //如果输入0节点，返回错误
        return 0;
    }
}


/*插入节点*/
static int insertNode(Listnode *head, int n, int data)
{
    Listnode *p, *temp, *node;
    int i;
    p = head;
    if(n>0){
        while(p->next != NULL && n){
            temp = p;
            p = p->next;
            n--;
        }
        if(n > 1){
            return 0;
        }else if(n == 1){
            node = (Listnode *)malloc(sizeof(Listnode));
            node->value = data;
            node->next = NULL;
            p->next = node;
            return 1;
        }else{
            node = (Listnode *)malloc(sizeof(Listnode));
            node->value = data;
            temp->next = node;
            node->next = p;
            return 1; 
        }       
    }else{
        return 0;
    }
}

int main(void)
{
    Listnode *head;
    int n = 5;
    int data[5] = {1,2,3,4,5};
    int len;

    head = creatList(n,data);
    len = printList(head);
    printf("%d\n", len);
    if(delnode_for_num(head,5)){
        len = printList(head);
        printf("%d\n", len); 
    }else{
        printf("节点不存在\n");
    }
    if(insertNode(head,3,6)){
        len = printList(head);
        printf("%d\n", len); 
    }else{
        printf("插入的位置无效\n");
    }
    return 0;
}