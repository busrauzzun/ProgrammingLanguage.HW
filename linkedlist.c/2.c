#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node * next;
};

typedef struct node node;
node *head,*p;


node* createlist();
void traverselist(node* head);
node* cutlastaddhead(struct node* head);


node* createlist(){
    int n,k;
    printf("how many numbers do you enter : ");
    scanf("%d",&n);

    for(k=0;k<n;k++){
        if(k==0){
            head=(node*)malloc(sizeof(node));
            p=head;
        }
        else{
            p->next=(node*)malloc(sizeof(node));
            p=p->next;
        }
        printf("Enter number: ");
        scanf("%d",&p->number);
    }

    p->next=NULL;
    return head;

}

node* cutlastaddhead(struct node* head){
    node*p,*temp;
    p=head;
    
    while(p!=NULL){
        if (p->next == NULL && p == head)
        {
            break;
        }
        else if(p->next==NULL){
            temp->next=NULL;
            p->next =head;
            break;
            
        }
        temp=p;
        p=p->next;
    }
    return p;
}






void traverselist(node*head){
    node*p;
    p=head;
    while(p!=NULL){
        printf("%4d",p->number);
        p=p->next;
    }
}



int main(){
    head=createlist();
    traverselist(head);
    printf("\n \n");
    head = cutlastaddhead (head);
    traverselist(head);
    
     return 0;
}