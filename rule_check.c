//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Ryan Dritama
// File Name : rule_check.c
// Dependency : "lib.h"
//
// Description:
// rule checker
//
// Status:
// 1. Ryan Dritama - 13217048 : Create the file
// 2. dites bersama
//
//
//***********************************************************//
#include"lib.h"

void ruller_checker(int minggu[], int day[], int i, jadwal_t jadwal_prak[][5]){
	lab_t dummy = {0};
	int a,j,k,l ;
    
    

    //Eval
    int gugur=0;
    int mines = 0;
    for (int a=0; a<i;a++){
        for (j=0; j<4; j++){
            //printf("Count pada week %d day = %d  lab %s adalah %d\n", minggu[a], day[a],jadwal_prak[minggu[a]][day[a]].lab[j].id,jadwal_prak[minggu[a]][day[a]].lab[j].count );
            if (jadwal_prak[minggu[a]][day[a]].lab[j].count == 1){
                jadwal_prak[minggu[a]][day[a]].lab[j]=dummy;
                gugur= 1;
                
                //  printf("GAGAL\n");

            }
        }
        if (gugur){     
            mines++;
            gugur = 0;
        }
    }


    printf("%d/%d rule checked\n", i-mines, i);


}
/*
int main(){
    prak_t p[3]={0};
    strcpy(p[2].id, "EB2200");
    strcpy(p[0].id, "EL2205");
    strcpy(p[1].id, "EL2208");
    jadwal_t j[12][5]={0};
    //lab_t dummy={0};

    input_sch(j, p);
    FILE *f;
     
    f = fopen("file.txt","r");
    ruller_checker(f,j);
    fclose(f);

    return 0;
}*/