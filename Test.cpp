#include <cstddef>
#include <stdlib.h>
using namespace std;

typedef struct Lnode{
    int data;
    Lnode *next;
}LNode, *LinkList;

typedef struct SNode{
    int data;
    SNode *top;
}SNode, *Stack;

int R_print(int argc);

int StackEmpty(Stack &S);

int StackPop(Stack &S,int x){
    return 0;
}

int StackPush(Stack &S,int x){
    return 0;
}

int Dele_Num(int x, LinkList &L){
    LinkList L2 = L;
    LNode *p = NULL;
    while(L2->next != NULL){
        if(L2->next->data == x){
            p = L2->next;
            L2->next = p->next;
            p->next = NULL;
            free(p);
        }
        else
            L2 = L2->next;
    }
    return 0;
}

int ReverseOutput(LinkList &L,Stack &S){
    LinkList L1 = L->next;
    while(L1 != NULL){
        StackPush(S,L1->data);
        L1 = L1->next;
    }
    int i = 0;
    while(!StackEmpty(S)){
        StackPop(S,i);
        R_print(i);
    }
    return 0;
}








