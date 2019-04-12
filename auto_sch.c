#include"lib.h"

const char rombongan_2205_1[][9] = {"A1", "A2", "B1", "B2", "C1", "C2", "A", "B", "C"};
const char rombongan_2208_1[][9] = {"A1", "A2", "A3", "B1", "B2", "B3", "C", "A", "B"};
const char rombongan_2200_1[][2] = {"A", "B"};
const char *ruangan_1 [4] = {"LAB1", "LAB2", "LAB3", "LSS"};
/*
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

void auto_sch(jadwal_t j[][5], prak_t *p){
    int prak = rand()%3;
    int rom = rand();
    int w = rand()%12;
    int h = rand()%5;
    int lab = rand()%4;
    int p_in, r_in, w_in, h_in, lab_in;
    int max_rom, max_prak;
    int count =0;
    //Iterasi Prak
    for (int i = 0; i< 3;  i++){
        p_in = (i + prak)%3;
        switch (p_in)
        {
        case 0:
            
            max_prak = 7;
            max_rom = 6;
            break;
        
        case 1:
            
            max_prak = 9;
            max_rom = 7;
            break;

        case 2:
            
            max_prak = 5;
            max_rom =  2;
            break;
        default:
            break;
        }
        for (j=0;j<max_rom;j++){
            r_in =  (j+ rom)%max_rom;
            while (p[p_in].r[r_in].count<max_prak){
                w_in = w+count;
                h_in = h+h_count;
            }

        }
    }


}

*/
int syarat_lab(int prak, int rom, jadwal_t j[][5], int w, int h){
    int index;
    int syarat = -1;
    int count = 0;
    index = rand()%4;
    
    do
    {
       // printf("Masuk Lab, index %d, syarat = %d, prak %d, count %d\n", index,syarat, prak, count);
        if ((prak != 1)&&(index == 3)){
           // printf("Masuk salah\n");
        }else
        {
         //   printf("Masuk if seharusnya\n");
           // printf("Nilinya %d\n",j[w][h].lab[index].count);
            if (j[w][h].lab[index].count==0){
                syarat = index;
            }
        }
        if (count == 4){
            syarat = -2;
        }
        count++;
        
        index=(index+1)%4;
    } while (syarat == -1);
    return syarat;
}

int syarat_hari(int prak, int rom, int w, jadwal_t j[][5]){
    int index, full, count, syarat, tabrakan;
    tabrakan = 0;
    syarat = -1;
    full = 1;
    count = 0;
    index = rand()%5;
    printf("Masuk hari, index %d\n", index);
    do
    {
        if (syarat_lab(prak, rom, j, w, index) != -2){
            full = 0;
        }
    
       // printf("Full %d\n", full);
        if (prak == 1){
            if (rom != 6){
                for (int l=0;l<4;l++){
                    if (strcmp("EL2205", j[w][index].lab[l].id)==0){
                        tabrakan = 1;
                    }
                }
            }
        }
        //printf("Tabrakan 1 %d\n", tabrakan);
        if (prak == 0){
            for (int l=0;l<4;l++){
                if (strcmp("EL2208", j[w][index].lab[l].id)==0){
                    tabrakan = 1;
                }
            }
        }
       // printf("Tabrakan 2 %d\n", tabrakan);
        if ((full)||(tabrakan)){
            index= (index+1)%5;
        }else
        {
            syarat = index;
        }
        if (count == 5){
            syarat = -2;
        }
        count++;
           
    } while (syarat == -1);
    
    return syarat;
}



int syarat_minggu(int prak, int rom, jadwal_t j[][5]){
    int syarat=-1;
    int index;
    int full=1;
    printf("Masuk Minggu\n");
    index = rand()%12;
    printf("Index %d\n", index);
    do
    {
    
        if (syarat_hari(prak, rom, index, j)!=-2){
            full = 0;
        }
        //printf("Syarat hari di minggu %d\n", syarat_hari(prak, rom, index, j));
    
        if (full){
            index = (index+1)%12;
        }else
        {
            syarat = index;
        }
        
    } while (syarat ==-1);
    

}


//Implementasi DFS

void randomize(int prak, int rom, jadwal_t j[][5], prak_t *p){
    int w, h, lab, w_in, h_in, lab_in;
    /*w = rand()%12;
    h = rand()%5;
    lab = rand()%4;*/

    printf("Masuk\n");
    w_in = syarat_minggu(prak,rom, j);
    printf("W_in %d\n",w_in);
    
    
    h_in = syarat_hari(prak, rom, w_in, j);
    printf("H_in %d\n",h_in);
    
    lab_in = syarat_lab(prak, rom, j, w_in, h_in);
    printf("Lab_in %d\n",lab_in);
    strcpy(j[w_in][h_in].lab[lab_in].prak,p[prak].id);
    printf("testing Prak %s\n",j[w_in][h_in].lab[lab_in].prak);
    strcpy(j[w_in][h_in].lab[lab_in].id,ruangan_1[lab_in]);
    switch (prak)
    {
    case 0:
        strcpy(j[w_in][h_in].lab[lab_in].rom,rombongan_2205_1[rom]);
        break;
    case 1:
        strcpy(j[w_in][h_in].lab[lab_in].rom,rombongan_2208_1[rom]);
        break;
    case 2:
        strcpy(j[w_in][h_in].lab[lab_in].rom,rombongan_2200_1[rom]);
        break;
    
    default:
        break;
    }
    //strcpy(j[w_in][h_in].lab[lab_in].rom,rombongan_2205_1[rom]);
    p[prak].r[rom].count++;
    j[w_in][h_in].lab[lab_in].count++;
    printf("Prak %s di Ruang %s Rombongan %s jumlah prak %d\n",j[w_in][h_in].lab[lab_in].prak,j[w_in][h_in].lab[lab_in].id,j[w_in][h_in].lab[lab_in].rom,p[prak].r[rom].count);        
}

void autobot(jadwal_t jadwal[][5], prak_t *p){
    int max_prak, max_rom;
    for (int i = 0;i <3;i++){
        switch (i)
        {
        case 0:
            max_prak =  7;
            max_rom = 6;
            break;
        case 1:
            max_prak =  9;
            max_rom = 7;
            break;
        case 2:
            max_prak =  5;
            max_rom = 2;
            break;
        
        default:
            break;
        }
        printf("Dipilih prak %s \n", p[i].id);
        for (int j=0;j<max_rom;j++){
            printf("Dipilih rom %d \n", j);
            while (p[i].r[j].count<max_prak){
                randomize(i, j, jadwal, p);
            }
        }
    }
}