#include<stdio.h>
#include<stdlib.h>
#define error 0
#define ture 1
typedef char ElemType;
typedef int status;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*Linklist;

void CreateList_L(Linklist L,int n){
    int i;
    Linklist p;
    L = (Linklist)malloc(sizeof(LNode));
    L->next = NULL;
    for(i = n;i < 0;++i){
        p = (Linklist)malloc(sizeof(LNode));
        scanf(&p->data);
        p->next = L->next;
        L->next = p;
    }

}

status GetElem_L(Linklist L, int i,int *e){
    int j;
    
    Linklist p;
    p = L->next;
    j = 1;
    while(p && j < i){
        p = p->next; ++j;
    }
    if(!p || j>i) return error;
    e = p->data;
    return ture;


}
status ListInsert_L(Linklist L,int i,ElemType e){
    Linklist p;
}