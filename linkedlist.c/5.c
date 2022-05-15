#include <stdio.h>
#include <stdlib.h>

struct node{
    int number;
    struct node*next;
};

typedef struct node nodes;
nodes*head;

nodes* cutheadaddlast(nodes*head);
nodes* createlist();
void traverselist(nodes*head);

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

nodes*cutheadaddlast(nodes*head){
    nodes*p,*newhead;
    p=head;
    newhead=head->next;
    
    while(p!=NULL){
        if(p==head &&p->next==NULL){
            break;
        }
        else if(p->next==NULL){
            p->next=head;
            head->next=NULL;
            break;
        }
        
        p=p->next;
    }
    return newhead;
    
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

int main(){
    head=createlist();
    traverselist(head);
    head=cutheadaddlast(head);
    traverselist(head);

    return 0;
    
}





