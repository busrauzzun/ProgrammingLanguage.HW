#include <stdio.h>
 	int stdno;
    char name[40];
    int midterm;

int biggerfifty(FILE* mfptr);
int addten (FILE*mfptr);
int average(FILE*mfptr);


int main(){
    int i;
    
    FILE *mfptr;
    if((mfptr= fopen("student3.txt","w"))==NULL){
        printf("The file doesnt open ");
    }
    else{
        printf("Student number,name,midterm \n");
        for(i=0;i<10;i++){
		
        printf("?");
        scanf("%d%s%d",&stdno,name,&midterm);

        
        fprintf(mfptr,"%d %s %d\n",stdno,name,midterm);
        }
        

        fclose(mfptr);
    }



    int secim;
    printf(" 1-Notu elliden buyuk kisiler\n"
    "2-Notu 50 den az olanlara 10 puan ekle \n"
    "3-Ortalamayi bul\n"
    "4-EXIT");
    printf("\n");

    printf("secim giriniz :");
    scanf("%d",&secim);

    while (secim!=4){
        switch(secim){
            case 1:biggerfifty(mfptr);break;
            case 2:addten(mfptr); break;
            case 3: average(mfptr);break;
            case 4:break;
        }
        printf("\n");
        printf("secim giriniz: ");
        scanf("%d",&secim);
    }
    


 return 0;
}

int biggerfifty(FILE* mfptr){
   mfptr=fopen("student3.txt","r");
   int counter =0;
   
  fscanf(mfptr,"%d%s%d",&stdno,name,&midterm); 

   while(!feof(mfptr)){
       
        if(midterm>50){
            counter+=1;
            
            printf("%4d %s %4d\n",stdno,name,midterm);
         }
        fscanf(mfptr,"%d%s%d",&stdno,name,&midterm); 
    }
    printf("Notu 50 den buyuk olan kisi sayisi : %d",counter);


}

int addten (FILE*mfptr){
    mfptr=fopen("student3.txt","r+");
   
   
  fscanf(mfptr,"%d%s%d",&stdno,name,&midterm); 

   while(!feof(mfptr)){
       
        if(midterm<50){
            midterm+=10;

            printf("New midterms: %d",midterm);
            printf("\n");
        }
        fscanf(mfptr,"%d%s%d",&stdno,name,&midterm); 
    }

}

int average(FILE*mfptr){
    mfptr=fopen("student3.txt","r");
    int counter=0;
    int total=0;
    
    fscanf(mfptr,"%d%s%d",&stdno,name,&midterm); 

   while(!feof(mfptr)){
       counter++;
       total+=midterm;
       fscanf(mfptr,"%d%s%d",&stdno,name,&midterm); 
    }
    float ortalama = total/counter;
    printf("ortalama: %.2f",ortalama);

}