#include <stdio.h>
#include <stdlib.h>

struct node{
    int age;
    struct node*next;
};

typedef struct node nodes;
nodes*head;

nodes* createlist();
nodes*delete(nodes*head,int delage);
void traverselist(nodes* head);

nodes* createlist(){
    nodes*p;
    int n,k;
    printf("how many people : ");
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
        
        scanf("%d",&p->age);
    }

    p->next=NULL;
    return head;

}

nodes*delete(nodes*head,int delage){
    nodes*p,*q;
    p=head;
    while(p!=NULL){
        if(p->age==delage&&p==head){
            head=head->next;
            free(p);
            break;
        }
        else if(p->age==delage){
            q->next=p->next;
            free(p);
            break;

        }
        q=p;
        p=p->next;
    }
    return head;
}
void traverselist(nodes* head){
    nodes*p;
    p=head;
    system("cls");
    while(p!=NULL){
        printf("%d\t",p->age);
        p=p->next;
    }
}



int main(){
    
    head=createlist(head);
    int delage;
    printf("Enter the age you want to delete: ");
    scanf("%d",&delage);
    head=delete(head,delage);
    traverselist(head);

}