#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT   10
typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType     *elem;
    ElemType data[10];
    int      length;
    int      listsize;

}SqList;
Status InitList_Sp(SqList L){

L.elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
if(! L.elem)exit(0);
L.length = 0;
L.listsize = LIST_INIT_SIZE;
return 1;

}

Status ListInsert_sq(SqList L,int i,ElemType e ){

    ElemType *newbase;
    ElemType *q,*p;

    if ( i<1 || i > L.length+1 )   return 0;
    if (L.length >= L.listsize){
        newbase = (ElemType *)realloc(L.elem,(L.listsize + LISTINCREMENT)* sizeof(ElemType));
        if(!newbase) exit(0);
        L.elem = &newbase;
        L.listsize += LISTINCREMENT;


    }
    q = &(L.elem[i - 1]);
    for( p = &(L.elem[L.length - 1]); p >= q; --p) *(p+1) = *p;
    *p = e;
    ++L.length;
    return 1;
    
}

Status ListDelete_sp(SqList L,int i, ElemType *e){
    ElemType *p,*q;
    if (i < 1 || i > L.length) return 0;
    p = &(L.elem[i - 1]);
    e = p;
    q = L.elem + L.length - 1;
   for(++p;p <=  q; ++p) *(p+1) = *p;
    --L.length;
    return 1;


}



//bug bug bug bug
/*int main(){
    ElemType *e;
    int i,q;
    SqList SqList_1;
    InitList_Sp(SqList_1);
   SqList_1.data[10]=1234567890;
    q = SqList_1.length;
    for(i = 0; i < q; i++)printf("%d",SqList_1.data);
    ListDelete_sp(SqList_1,3,e);
    q = SqList_1.length;
    for(i = 0; i < q; i++)printf("%d",SqList_1.data);
    return 0;
}
*/



