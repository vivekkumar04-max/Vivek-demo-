#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* create(struct node *p,int x) {

    if(p==NULL) {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->next=NULL;
        return p;
    }
    else {
        p->next=create(p->next,x);
        return(p);
    }

}
void insertatbeg(struct node **p,int x) {
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    q->data=x;
    q->next=*p;
    *p=q;
}
void insertatend(struct node *p,int x) {
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    while(p->next!=NULL) {
        p=p->next;
    }
    p->next=q;
    q->data=x;
    q->next=NULL;
}
void insertatany(struct node *p,int key,int x) {
    struct node *q;
    q=(struct node*)malloc(sizeof(struct node));
    while((p->next!=NULL)&&(p->data!=key)) {
        p=p->next;
    }
    q->next=p->next;
    q->data=x;
    p->next=q;
}
struct node* delanynode(struct node *p,int n) {
    int i;
    struct node *q,*r;
    if(p==NULL) {
        printf("list is empty");
    }
    else {
        q=NULL;
        r=p;
        i=1;
    }
    while(i<n) {
        q=r;
        r=r->next;
        i+=1;
    }
    if(q==NULL) {
        p=r->next;
        free(r);
    }
    else {
        q->next=r->next;
        free(r);
    }
    return p;
}
void traverse(struct node *p) {
    printf("\nThe list is \t");
    while(p!=NULL) {
        printf("\t%d",p->data);
        p=p->next;
    }
}

main() {
    int num=0,j,key,val,n;
    struct node *head=NULL;

    printf("\n1 :create");
    printf("\n2 :insertatbeg");
    printf("\n3 :insertatend");
    printf("\n4 :insertatany");
    printf("\n5 :delanynode");
    printf("\n6 :traverse");
    printf("\n7 :exit");
    do {
        printf("\nenter choice : ");
        scanf("%d",&j);

        switch(j) {
        case 1:
            printf("Enter the data to put on the node: ");
            scanf("%d",&val);
            head=create(head,val);
            break;

        case 2:
            printf("Enter new data to insert on the node : ");
            scanf("%d",&val);
            insertatbeg(&head,val);
            break;
        case 3:
            printf("Enter data at the end of the node : ");
            scanf("%d",&val);
            insertatend(head,val);
            break;
        case 4:
            printf("Enter the data you wanter to insert :");
            scanf("%d",&val);
            printf("Enter key at which you wanted to insert data : ");
            scanf("%d",&key);
            insertatany(head,key,val);
            break;
        case 5:
            printf("Enter the node you want to delete :");
            scanf("%d",&n);
            head=delanynode(head,n);
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