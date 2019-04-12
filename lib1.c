#include"lib.h"


const char rombongan_2205[][9] = {"A1", "A2", "B1", "B2", "C1", "C2", "A", "B", "C"};
const char rombongan_2208[][9] = {"A1", "A2", "A3", "B1", "B2", "B3", "C", "A", "B"};
const char rombongan_2200[][2] = {"A", "B"};
const char *ruangan [4] = {"LAB1", "LAB2", "LAB3", "LSS"};

enum hari str2enum_hari (const char *str)
{
     int j;
     for (j = 0;  j < sizeof (conversion_hari) / sizeof (conversion_hari[0]);  ++j)
         if (!strcmp (str, conversion_hari[j].str))
             return conversion_hari[j].val;    
}
enum prak str2enum_prak (const char *str)
{
     int j;
     for (j = 0;  j < sizeof (conversion_prak) / sizeof (conversion_prak[0]);  ++j)
         if (!strcmp (str, conversion_prak[j].str))
             return conversion_prak[j].val;    
}
enum prak str2enum_lab (const char *str)
{
     int j;
     for (j = 0;  j < sizeof (conversion_lab) / sizeof (conversion_lab[0]);  ++j)
         if (!strcmp (str, conversion_lab[j].str))
             return conversion_lab[j].val;    
}
int syarat_rombongan(int r, char *s){
    int c=-1;
    if (r == 0){
        for (int i = 0; i< sizeof(rombongan_2205)/ sizeof(rombongan_2205[0] );i++){
          if (strcmp(s,rombongan_2205[i])==0){
                       
                return i;
              
          }  
        }

    }else if (r == 1)
    {
        for (int i = 0; i< sizeof(rombongan_2208)/ sizeof(rombongan_2208[0] );i++){
          if (strcmp(s,rombongan_2208[i])==0){
             
            return i;
                      
          }  
        }
    }else if (r == 2)
    {
        for (int i = 0; i< sizeof(rombongan_2200)/ sizeof(rombongan_2200[0] );i++){
          if (strcmp(s,rombongan_2200[i])==0){
             
             return i;   
          }  
        }
    }
    return c; 
}
int input_minggu(){
    int d;
     do
    {
        printf("Minggu ke: \n");
        scanf("%d",&d);
    } while ((d<3)||(d>15));
    return d-3;
}
int input_hari(int prak, int s_r, int w, jadwal_t j[][5]){
    char s[255];
    int d = 5;
    int syarat = 0;
    do
    {
        int tabrakan=0;
        printf("Hari:\n");
        scanf("%s", s);
        d = str2enum_hari(s);
        if (prak == 1){
            for (int i=0;i<4;i++){
                if (strcmp("EL2205",j[w][d].lab[i].prak)==0){
                    printf("EL2208 tidak dapat dilaksanakan dengan EL2205\n");
                    tabrakan = 1;
                }
            }
            if (tabrakan==0){
                if ((s_r==6)){
                    if (d ==  Rabu){
                        syarat = 1;
                    }else{
                        printf("Harus di hari Rabu\n");
                    }
                }else
                {
                    syarat=1;
                }
                
            }
            
       }else if (prak == 2)
       {
          if ((d == Selasa)||(d == Kamis)){
              syarat =1;
          }else
          {
              printf("Harus di hari Selasa atau Kamis\n");
          }
          
       }else if (prak == 0)
       {
           for (int i=0;i<4;i++){
                if (strcmp("EL2208",j[w][d].lab[i].prak)==0){
                    printf("EL2205 tidak dapat dilaksanakan dengan EL2208\n");
                    tabrakan = 1;
                }
            }
            if (!tabrakan){
                syarat = 1;
            }
       }else
       {
           syarat = 1;
       }
       
    } while ((d == 5)||(syarat == 0));
    printf("Hari %d\n",d);
    return d;
}
int input_ruangan(int a, int prak, jadwal_t l){
    char s[255];
    int d=4;
    do
    {
        if (a == 0){
            printf("Ruangan :\n");
        }
        
        scanf("%s", s);
        
        d =str2enum_lab(s);
        if ((d == 3)&&((prak==1)||(prak==2))){
            d = 4;
            printf("Hanya EL2205 yang dapat menggunakan LSS\n");
        }
        if (l.lab[d].count==1){
            d =4 ;
            printf("%s sudah digunakan pada jadwal tersebut\n",s);
        }
    } while (d == 4);
    printf("Lab %d\n",d);
    return d;
}
int max_rom(int prak){
    switch (prak)
    {
        case 0:
            return 9;
            break;
        
        case 1:
            return 9;
            break;
    
    
        case 2:
            return 2;
            break;
    
        default:
            break;
    }
}
void input_sch(jadwal_t j[][5], prak_t *p){
    char s[225];
    int prak=3;
    int w, h, r, s_r,l;
    s_r=0;
    do{
        do
        {
            printf("Pilih Kode Praktikum (EL2205, EL2208, EB2200):\n");
            scanf("%s", s);
            prak =  str2enum_prak(s);
            if ((strcmp(s, "Q")!=0)&&(strcmp(s,"q")!=0)&&(prak!=3)){      
                s_r = -1;
                do
                {
                    int d;
                        
                    switch (prak)
                    {
                        case 0:
                            printf("Rombongan (A1, A2, B1, B2, C1 atau C2):\n");
                            scanf("%s", s);
                            s_r = syarat_rombongan(prak, s);
                            if (s_r>5){
                                w = input_minggu();
                                h = input_hari(prak,s_r,w,j);
                                printf("Ruangan 1:\n");
                                
                                r = input_ruangan(1,prak,j[w][h]);
                                
                                printf("Ruangan id = %d ; Rombongan id = %d\n", r, s_r);
                                if ((p[prak].r[(2*s_r)-12].count<7) ){
                                    printf("EL2205 masuk\n");
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                    strcpy(j[w][h].lab[r].rom,rombongan_2205[(2*s_r)-12]);
                                    p[prak].r[(2*s_r)-12].count++;
                                    j[w][h].lab[r].count++;
                                    printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,p[prak].r[(2*s_r)-12].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                                
                        
                                printf("Ruangan 2:\n");
                                r = input_ruangan(2,prak,j[w][h]);
                                
                                printf("Ruangan id = %d ; Rombongan id = %d\n", r, s_r);
                                if (p[prak].r[(2*s_r)-12].count<7) {
                                    printf("EL2205 masuk\n");
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                    strcpy(j[w][h].lab[r].rom,rombongan_2205[(2*s_r)-11]);
                                    p[prak].r[(2*s_r)-11].count++;  
                                    j[w][h].lab[r].count++;  
                                     printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,p[prak].r[(2*s_r)-11].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                                
                            }else if (s_r == -1)
                            {
                                    /* code */
                            }
                                
                            else
                            {
                                w = input_minggu();
                                h = input_hari(prak,s_r,w,j);
                                r = input_ruangan(0,prak,j[w][h]);
                                
                                printf("Prak id =  %d Ruangan id = %d ; Rombongan id = %d Jumlah prak = %d\n",prak, r, s_r,p[prak].r[s_r].count);
                                    //printf("Tes awal %d %d %d itu\n", w, h, r);
                                if (p[prak].r[s_r].count<7) {
                                    printf("EL2205 masuk\n");
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                    strcpy(j[w][h].lab[r].rom,rombongan_2205[s_r]);
                                    p[prak].r[s_r].count++;
                                    j[w][h].lab[r].count++;
                                    printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,p[prak].r[s_r].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                              
                            }
                                
                            
                            break;
                        case 1:
                            printf("Rombongan (A1, A2, A3, B1, B2, B3 atau C):\n");
                            scanf("%s", s);
                            s_r = syarat_rombongan(prak, s);
                            if (s_r>6){
                                w = input_minggu();
                                h = input_hari(prak,s_r,w,j);
                                printf("Ruangan 1:\n");
                                r = input_ruangan(1,prak,j[w][h]);
                                
                                printf("Ruangan id = %d ; Rombongan id = %d\n", r, s_r);
                                if ((p[prak].r[(3*s_r)-21].count<9) ){
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                    strcpy(j[w][h].lab[r].rom,rombongan_2208[(3*s_r)-21]);
                                    p[prak].r[(3*s_r)-21].count++;
                                    j[w][h].lab[r].count++;
                                    printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,p[prak].r[(3*s_r)-21].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                               
                                printf("Ruangan 2:\n");
                                r = input_ruangan(2,prak,j[w][h]);
                                
                                printf("Ruangan id = %d ; Rombongan id = %d\n", r, s_r);
                                if (p[prak].r[(3*s_r)-20].count<9 ){
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                    strcpy(j[w][h].lab[r].rom,rombongan_2208[(3*s_r)-20]);
                                    p[prak].r[(3*s_r)-20].count++;
                                    j[w][h].lab[r].count++;
                                     printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,p[prak].r[(3*s_r)-20].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                          
                                printf("Ruangan 3:\n");
                                r = input_ruangan(3,prak,j[w][h]);
                                
                                printf("Ruangan id = %d ; Rombongan id = %d\n", r, s_r);
                                if ((p[prak].r[(3*s_r)-19].count<9) ){
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                    strcpy(j[w][h].lab[r].rom,rombongan_2208[(3*s_r)-19]);
                                    p[prak].r[(3*s_r)-19].count++;
                                    j[w][h].lab[r].count++;
                                     printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,p[prak].r[(3*s_r)-19].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                                
                                                            
                            }else if (s_r==-1)
                            {
                                
                            }else
                            {
                            
                                w = input_minggu();
                                h = input_hari(prak,s_r,w,j);
                                r = input_ruangan(0,prak,j[w][h]);
                                
                                printf("Ruangan id = %d ; Rombongan id = %d\n", r, s_r);
                                    //printf("Tes awal %d %d %d %s itu\n", w, h, r, p[prak].id);
                                if ((p[prak].r[s_r].count<9) ){
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                    
                                    strcpy(j[w][h].lab[r].rom,rombongan_2208[s_r]);
                                        
                                    p[prak].r[s_r].count++;
                                    j[w][h].lab[r].count++;
                                     printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,p[prak].r[s_r].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                               
                                    
                            }               
                            break;
                        case 2:
                            printf("Rombongan (A atau B):\n");
                            scanf("%s", s);
                            s_r = syarat_rombongan(prak, s);
                            if (s_r!=-1){
                                w = input_minggu();
                                h = input_hari(prak,s_r,w,j);
                                r = input_ruangan(0,prak,j[w][h]);
                                
                                printf("Ruangan id = %d ; Rombongan id = %d\n", r, s_r);
                                // printf("Tes awal %d %d %d %s itu\n", w, h, r, p[prak].id);
                                if ((p[prak].r[s_r].count<5) ){
                                    strcpy(j[w][h].lab[r].prak,p[prak].id);
                                    strcpy(j[w][h].lab[r].id,ruangan[r]);
                                        //printf("Rom %s\n",rombongan_2200[s_r]);
                                    strcpy(j[w][h].lab[r].rom,rombongan_2200[s_r]);
                                    p[prak].r[s_r].count++;
                                    j[w][h].lab[r].count++;
                                    printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,j[w][h].lab[r].count);
                                }else{
                                    printf("Praktikum %s rombongan %s sudah menyelesaikan seluruh modul\n",j[w][h].lab[r].prak,j[w][h].lab[r].rom);
                                }
                               
                            }
                            break;            
                    }

                   //` printf("SR %d\n", s_r);
                    //printf("w %d h %d ruang %s\n",w,h,ruangan[r]);
                    if (s_r!=-1){
                        printf("Prak %s di Ruang %s Rombongan %s jumlah prak pada lab tsb%d\n",j[w][h].lab[r].prak,j[w][h].lab[r].id,j[w][h].lab[r].rom,j[w][h].lab[r].count);
                    
                    }
                     
                }while (s_r == -1);
                
            }else{
                prak = -1;
            }   
        } while (prak == 3);
    }while ((strcmp(s,"Q")!=0)&&(strcmp(s,"q")!=0));
}

void auto_input_sch (jadwal_t j[][5], prak_t *p){

}