#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[],int n){
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

int isLoop(struct Node *p){
    struct Node *q;
    q=p;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;  //move 'q' if 'q' is not NULL
    }while(p && q && p!=q);
    if(p==q)
        return 1;
    else
        return 0;
}

int main(){
    struct Node *t1,*t2;
    int A[]={10,20,30,40,50};
    create(A,5);
    t1=first->next->next;          //t1 will point to Node with 30
    t2=first->next->next->next->next; //t2 will point to node with 50
    t2->next=t1;                       //Now,there is loop in LL

    if(isLoop(first))
        printf("Loop\n");
    else
        printf("Linear\n");
    return 0;
}
