#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node * next;
};

typedef struct node node;

void traverselist(node *head);
node* addodd(node*head,int num);
node* addeven (node*p,int num);

node* addodd(node*head,int num){
    node*new;
    new=(node*)malloc(sizeof(node));
    new->next=(node*)malloc(sizeof(node));
    
    new->number=num;
    new->next=head;

    return new;

}
node* addeven (node*p,int num){
    node*new;
    new=(node*)malloc(sizeof(node));
    new->next=(node*)malloc(sizeof(node));

    p->next =new;
    new->number = num;
    new->next = NULL;

    return new;

}

void traverselist(node* head){
    node *k;
    k = head;
    system("cls");
    while(k != NULL)
    {
        printf("%4d",k->number);
        k = k->next;
    }    
      
}
int main(){
    int num;
    node *head,*p; 
    head=(node*)malloc(sizeof(node));
    head->next=(node*)malloc(sizeof(node));
    printf("Enter the number : ");
    scanf("%d",&num);
    if(num!=-1){
        head->number=num;
        head->next=NULL;
        p=head;
    }
    while(num!=-1){
        printf("Enter the number : ");
        scanf("%d",&num);
        if(num!=-1 && num%2==1){
            head=addodd(head,num);
        }
        else if(num!=-1 && num%2==0){
            p=addeven(p,num);
        }
    }
    traverselist(head);

 return 0;
}
