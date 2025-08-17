#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node* create(struct node *p,int x) {
    if(p==NULL) {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        p->prev=NULL;
        return (p);
    }
    else{
    p->next=create(p->next,x);
    }
    return (p);
}
void insertatbeg(struct node **p,int x) {
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    if(p==NULL) {
        q->next=NULL;
        q->prev=NULL;
    }
    q->data=x;
    (*p)->prev=q;
    q->next=(*p);
    q->prev=NULL;
    (*p)=q;
}
void insertatend(struct node *p,int x) {
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    while(p->next!=NULL) {
        p=p->next;
    }
    q->data=x;
    q->prev=p;
    p->next=q;
    q->next=NULL;
}
void insertatany(struct node *p,int key,int x) {
    struct node *q;
    q=(struct node *)malloc(sizeof(struct node));
    while(p->next!=NULL && p->data!=key) {
        p=p->next;
    }
    p->next->prev=q;
    q->next=p->next;
    q->data=x;
    q->prev=p;
    p->next=q;
}
struct node* delatany(struct node *p,int n) {
    int i;
    struct node *q,*r;
    if(p==NULL) {
        printf("\nThe list is empty");
    }
    else {
        i=1;
        q=NULL;
        r=p;
    }
    while(i<n) {
        q=r;
        r=r->next;
        i=i+1;
    }
    if(q==NULL) {
        p=p->next;
        p->prev=NULL;
        free(r);
    }
    else {
        r->next->prev=q;
        q->next=r->next;
        free(r);
    }
    return p;
}
void traverse(struct node *p) {
    printf("\nThe list is : \n");
    while(p!=NULL) {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    int num=0,j,k,val,n;
    struct node *head=NULL;
    printf("\n1: create");
    printf("\n2: insert at begning");
    printf("\n3: insert at end");
    printf("\n4: insert at any position");
    printf("\n5: delete any node");
    printf("\n6: traverse");
    printf("\n7: exit");
    do {
        printf("\nEnter choice : ");
        scanf("%d",&j);
        switch(j) {
        case 1:
            printf("Enter data to insert at node : ");
            scanf("%d",&val);
            head=create(head,val);
            break;
        case 2:
            printf("Enter data : ");
            scanf("%d",&val);
            insertatbeg(&head,val);
            break;
        case 3:
            printf("Enter data : ");
            scanf("%d",&val);
            insertatend(head,val);
            break;
        case 4:
            printf("Enter data : ");
            scanf("%d",&val);
            printf("Enter key : :");
            scanf("%d",&k);
            insertatany(head,k,val);
            break;
        case 5:
            printf("Enter node value : ");
            scanf("%d",&n);
            head=delatany(head,n);
            break;
        case 6:
            traverse(head);
            break;
        case 7:
            exit(0);
        }
    }
    while(num==0);
    return 0;
}