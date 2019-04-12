//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Ignasius Irvan
// File Name : main.c
// Dependency :stdio.h, "lib.h", "tampilan.c", "manual_sch_1.c"
//      asisten.c, "AssignAsistenManual.c", "rule_check.c",
//      "ExportImportCSV.c"
//
// Description:
// Main program
//
// Status:
// 1. Ignasius Irvan - 13217036 : Create the file
//
//***********************************************************//
//Ga perlu stdio.h , udah ada di LIB
//#include <stdio.h>

#include "lib.h"
//#include "tampilan.c"
//#include "manual_sch_1.c"
//#include "asisten.c"
//#include "AssignAsistenManual.c"
//#include "rule_check.c"
//#include "ExportImportCSV.c"
//Ga perlu lib.c udah ada di LIB.h
//#include "lib1.c"
//#include "assign sched.c"


int main(){
    prak_t p[3]={0};
    strcpy(p[2].id, "EB2200");
    strcpy(p[0].id, "EL2205");
    strcpy(p[1].id, "EL2208");
    jadwal_t jadwal[12][5]={0};
    //char s[255];
    int i, minggu[20], day[20];
    char line[100];
	char *pch;
    FILE *f;

    f = fopen("file.txt","r");
    srand(time(NULL));
    i = 0;
    while(fgets(line, sizeof(line), f) != NULL){
        pch = strtok(line," ");
        minggu[i] = atoi(pch)-3;
        pch = strtok (NULL," \n");
        day[i]=str2enum_hari(pch);
        i++;
    }

    printf("Menu:\n   1. Buat Proyek Baru\n   2. Muat Proyek dari Berkas\n   3. Keluar\n   Masukan: ");
    int begin=0;
    int start=0;
    char *nama;
    while (begin!=3){
        scanf("%d", begin);
        switch(begin){
            case 1:
                buatcsv(nama);
                break;
            case 2:
                importcsv(jadwal);
                break;
            case 3:
                start=1;
                break;
            default:
                printf("input salah, silahkan inout kembali");
                break;

        }
    }

    if (start!=1){

    int select=0;
    do{
        printf("[Menu Utama]\nPilih Mode:\n1. Tampilkan Schedule\n2. Schedule Manual\n3. Tampilkan Status Assignment Asisten\n4. Assign Asisten Manual\n5. Schedule Otomatis\n6. Assign Otomatis\n7. Rule Checker\n8. Simpan Proyek dan Keluar\nPilih Mode:");

        scanf("%d",&select);
        switch(select){
            case 1:
                //run tampil schedule
                tampil_sche(jadwal);
                break;
            case 2:
                //run schedule manual
                input_sch(jadwal,p);
                break;
            case 3:
                //run tampil sched assist
                tampil_as(jadwal);
                break;
            case 4:
                //run assign asst
                AssignAsistenManual(jadwal);
                break;
            case 5:
                //auto sched
                autobot(jadwal, p);
                break;
            case 6:
                //aouto asst

                break;
            case 7:
                //run rule check
                ruller_checker(minggu, day, i, jadwal);
                break;
            case 8:
                //run exit
                //main_save();
                savetocsvjadwal(jadwal);
                savetocsvasisten(jadwal);
                break;
            default:
                printf("\nInput tidak sesuai, silahkan masukkan kembali\n\n");
                break;
        }
    } while (select!=8);
    fclose(f);

    }
    return 0;
}

