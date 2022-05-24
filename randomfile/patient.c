#include <stdio.h>


void olustur(FILE*myptr);
void textdosya(FILE*myptr);
void hastagirisi(FILE*myptr);
void kayitara(FILE*myptr);
void sil(FILE*myptr);
void duzenle(FILE*myptr);
void listele(FILE*myptr);

struct hasta{
    int no;
    char ad[20];
    int yas;
    char bilgi[40];
    struct hasta*next;
};

int main(void){
    FILE *myptr;
    olustur(myptr);

    int secim;
    if((myptr=fopen("hasta.dat","r+"))==NULL){
        printf("Dosya acilamadi.");
    }
    else{
        printf("Yapmak istediginiz islemi seciniz: \n" );
        printf("1-Hasta girisi yap\n"
        "2-Dosyayi metin dosyasina yaz \n"
        "3-Kayit arama\n"
        "4-Hasta kaydi sil\n"
        "5-Hasta kaydi duzenle\n"
        "6-Listele\n"
        "7-Cikis");
        printf("\n");
        printf("Secim giriniz: ");
        scanf("%d",&secim);
        while(secim!=7){
            switch(secim){
                case 1:hastagirisi(myptr);break;
                case 2:textdosya(myptr); break;
                case 3:kayitara(myptr); break;
                case 4:sil(myptr);break;
                case 5:duzenle(myptr);break;
                case 6:listele(myptr);break;
            }
            printf("Secim giriniz: ");
            scanf("%d",&secim);
        }
        fclose(myptr);
    }
    return 0;
}

void olustur(FILE*myptr) {
    int n,i;

    struct hasta boshasta={0,"",0,""};
    if((myptr=fopen("hasta.dat","w"))==NULL){
        printf("Dosya olusturulamadi. ");
    }
    else{
        for(i=0;i<100;i++){
            fwrite(&boshasta,sizeof(struct hasta),1,myptr);
        }
        fclose(myptr);
    }
}

void hastagirisi(FILE*myptr){
    struct hasta hastabilgi={0,"",0,""};
    
    printf("Hasta no girin \n");
    scanf("%d",&hastabilgi.no);
    while(hastabilgi.no!=0){
        printf("Ad yas ve bilgi girin \n");
        scanf("%s%d%s",hastabilgi.ad,&hastabilgi.yas,hastabilgi.bilgi);
        fseek(myptr,(hastabilgi.no-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&hastabilgi,sizeof(struct hasta),1,myptr);
        printf("Hasta no girin \n");
        scanf("%d",&hastabilgi.no);
    }

}

void textdosya(FILE*myptr){
    struct hasta hastabilgi={0,"",0,""};

    FILE*fptr;
    if((fptr=fopen("hastaa.txt","w"))==NULL){
        printf("Dosya acilamadi.");
    }
    else{
        rewind(myptr);
        fprintf(fptr,"%-10s%-10s%-10s%10s","Hasta no","Ad","Yas","Hasta bilgi");
        while(!feof(myptr)){
            fread(&hastabilgi,sizeof(struct hasta),1,myptr);
            if(hastabilgi.no!=0){
                fprintf(fptr,"%-10d%-10s%-10d%10s",hastabilgi.no,hastabilgi.ad,hastabilgi.yas,hastabilgi.bilgi);
            }
        }
        fclose(fptr);
    }
}
void kayitara(FILE*myptr){
    struct hasta hastabilgi={0,"",0,""};

    int hastano;
    printf("Aramak istediginiz hasta no'sunu girin :\n");
    scanf("%d",&hastano);

    fseek(myptr,(hastano-1)*sizeof(struct hasta),SEEK_SET);
    fread(&hastabilgi,sizeof(struct hasta),1,myptr);

    if(hastabilgi.no==hastano){
        fseek(myptr,(hastano-1)*sizeof(struct hasta),SEEK_SET);
        printf("%10d %10s %10d %10s\n",hastabilgi.no,hastabilgi.ad,hastabilgi.yas,hastabilgi.bilgi);
    }
    else{
        printf("Kayit bulunamadi\n");
    }
}

void sil(FILE*myptr){
    struct hasta hastabilgi,boshasta={0,"",0,""};

    int hastano;
    printf("Aramak istediginiz hasta no'sunu girin :\n");
    scanf("%d",&hastano);

    fseek(myptr,(hastano-1)*sizeof(struct hasta),SEEK_SET);
    fread(&hastabilgi,sizeof(struct hasta),1,myptr);

    if(hastabilgi.no==0){
        printf("Silinecek hesap yok\n");
    }
    else{
        fseek(myptr,(hastano-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&boshasta,sizeof(struct hasta),1,myptr);
    }
}

void duzenle(FILE*myptr){
    struct hasta hastabilgi={0,"",0,""};

    int hastano;
    int yasmiktari;
    printf("Aramak istediginiz hasta no'sunu girin :\n");
    scanf("%d",&hastano);
    fseek(myptr,(hastano-1)*sizeof(struct hasta),SEEK_SET);
    fread(&hastabilgi,sizeof(struct hasta),1,myptr);

    if(hastabilgi.no==0){
        printf("Bilgi girilmemis\n");
    }
    else{
        fseek(myptr,(hastano-1)*sizeof(struct hasta),SEEK_SET);
        printf("Yasin artma miktarini gir\n");
        scanf("%d",&yasmiktari);
        hastabilgi.yas+=yasmiktari;
        printf("%10d %10s %10d %10s",hastabilgi.no,hastabilgi.ad,hastabilgi.yas,hastabilgi.bilgi);
        fseek(myptr,(hastano-1)*sizeof(struct hasta),SEEK_SET);
        fwrite(&hastabilgi,sizeof(struct hasta),1,myptr);
    }
}

void listele(FILE*myptr){
    struct hasta hastabilgi={0,"",0,""};
    printf("%-10d%-10s%-10d%10s","Hasta no","Ad","Yas","Hasta bilgi");

    while(!feof(myptr)){
        fread(&hastabilgi,sizeof(struct hasta),1,myptr);
        if(hastabilgi.no!=0){
            printf("%10d %10s %10d %10s",hastabilgi.no,hastabilgi.ad,hastabilgi.yas,hastabilgi.bilgi);
        }
    }
}





