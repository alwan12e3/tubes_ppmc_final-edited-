#include"lib.h"

int main(){
    prak_t p[3]={0};
    strcpy(p[2].id, "EB2200");
    strcpy(p[0].id, "EL2205");
    strcpy(p[1].id, "EL2208");
    jadwal_t jadwal[12][5]={0};
    char s[255];
    input_sch(jadwal, p);
    printf("testing %s test\n",jadwal[1][0].lab[1].prak);

    for (int i =0 ; i< 12;i++){
        for (int j = 0; j< 5 ; j++){
            //printf("Masuk");
            if (strcmp(jadwal[i][j].lab[0].prak,"")!=0){
           
                printf("Minggu %d Hari %d ada Prak %s rombongan %s di %s\n", i+3,j+1,jadwal[i][j].lab[0].prak,jadwal[i][j].lab[0].rom,jadwal[i][j].lab[0].id);
            }
            if (strcmp(jadwal[i][j].lab[1].prak,"")!=0){
              
                printf("Minggu %d Hari %d ada Prak %s rombongan %s di %s\n", i+3,j+1,jadwal[i][j].lab[1].prak,jadwal[i][j].lab[1].rom,jadwal[i][j].lab[1].id);
            }
            if (strcmp(jadwal[i][j].lab[2].prak,"")!=0){
            
                printf("Minggu %d Hari %d ada Prak %s rombongan %s di %s\n", i+3,j+1,jadwal[i][j].lab[2].prak,jadwal[i][j].lab[2].rom,jadwal[i][j].lab[2].id);
            }
            if (strcmp(jadwal[i][j].lab[3].prak,"")!=0){
                
                printf("Minggu %d Hari %d ada Prak %s rombongan %s di %s\n", i+3,j+1,jadwal[i][j].lab[3].prak,jadwal[i][j].lab[3].rom,jadwal[i][j].lab[3].id);
            }
        }
    }
    return 0;
}