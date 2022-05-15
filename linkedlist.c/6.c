#include <stdio.h>
#include <stdlib.h>

struct node{
    int number;
    struct node * next;
};

typedef struct node nodes;
nodes*head;

nodes*addeven(nodes*head,int n);
nodes*addodd(nodes*p,int n);
void traverselist(head);

int main(){
    int n;
    nodes* p;
    printf("Enter number: ");
    scanf("%d",&n);

    head=(nodes*)malloc(sizeof(nodes*));
    head->next=(nodes*)malloc(sizeof(nodes*));

    if(n!=-1){
        head->number=n;
        head->next=NULL;
        p=head;
    }

    while(n!=-1){
        printf("Enter the number: ");
        scanf("%d",&n);

        if(n%2==0){
            head=addeven(head,n);
        }
        else if(n%2==1){
            p=addodd(p,n);
        }


    }

    traverselist(head);
    return 0;
}

nodes*addeven(nodes*head,int n){
    nodes*q;
    q=(nodes*)malloc(sizeof(nodes*));
    q->next=(nodes*)malloc(sizeof(nodes*));
    q->next=head;
    q->number=n;
return q;

}

nodes*addodd(nodes*p,int n){
    nodes*q;
    q=(nodes*)malloc(sizeof(nodes*));
    q->next=(nodes*)malloc(sizeof(nodes*));
    p->next=q;
    q->next=NULL;
    q->number=n;


    return q;
}


void traverselist(nodes* head){
    nodes*p;
    p=head;
    system("cls");
    while(p!=NULL){
        printf("%d\t",p->number);
        p=p->next;
    }
}
