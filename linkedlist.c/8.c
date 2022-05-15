#include <stdio.h>
#include <stdlib.h>

struct node{
    int number;
    struct node *next;
};

typedef struct node nodes;
nodes *head,*last;

nodes*change(nodes*head);
nodes*createlist();
void treverselist(nodes*head);


nodes* createlist(){
    nodes*p;
    int n,k;
    printf("how many numbers do you enter : ");
    scanf("%d",&n);

    for(k=0;k<n;k++){
        if(k==0){
            head=(nodes*)malloc(sizeof(nodes));
            p=head;
        }
        else{
            p->next=(nodes*)malloc(sizeof(nodes));
            p=p->next;
        }
        printf("Enter number: ");
        scanf("%d",&p->number);
    }

    p->next=NULL;
    return head;

}

nodes *change(nodes*head){
    nodes*p,*ex;
    p=head;
    while(p!=NULL){
        if(p->next==NULL && p==head){
            break;   //linked list have only one node
        }
        else if(p->next==NULL&&head->next==p){
            p->next=head;
            head->next=NULL;
        }
        else if(p->next==NULL){
            p->next=head->next;
            ex->next=head;
            head->next=NULL;
            break;
        }
        ex=p;
        p=p->next;
    }
    return p;
}
void treverselist(nodes*head){
    nodes*p;
    p=head;
    while(p!=NULL){
        printf("%4d",p->number);
        p=p->next;
    }
}


int main(){
    head=createlist();
    treverselist(head);
    printf("\n");
    head=change(head);
    treverselist(head);
     return 0;
}