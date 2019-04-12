#include "lib.h"

void savetocsvjadwal(jadwal_t j[][5], char nama[30]) {
    /*Membuat file agar hasil dapat dimasukkan ke dalam file csv*/
    FILE *outfile;
    char nama2[40];
    nama2= strcat(nama,"_rombongan.csv");
    outfile = fopen(nama2,"w");

    /*Layout jadwal*/
    fprintf(outfile,"Ruang, Praktikum, LAB1, LAB2, LAB3, LSS\n");
    fprintf(outfile,"Minggu, Hari\n");

    char day[5][7] = {"Senin","Selasa","Rabu","Kamis","Jumat"};

    /*looping untuk jadwal setiap minggu*/
    for (int minggu=3; minggu<=15; minggu++) {
        for (int hari=0; hari<=4; hari++) {
            /*layout jadwal (setiap baris selalu ada)*/
            fprintf(outfile,"%d, %s,", minggu, day[hari]);
            /*jadwal praktikum sesuai input*/
            //asumsi 1: kalau ga ada jadwal, hasilnya kosong
            //asumsi 2: r=4 untuk validasi
            /*LAB 1 = lab[r=0]*/
            fprintf(outfile,"%s-%s,", j[minggu][hari].lab[0].prak, j[minggu][hari].lab[0].rom);
            /*LAB 2 = lab[r=1]*/
            fprintf(outfile,"%s-%s,", j[minggu][hari].lab[1].prak, j[minggu][hari].lab[1].rom);
            /*LAB 3 = lab[r=2]*/
            fprintf(outfile,"%s-%s,", j[minggu][hari].lab[2].prak, j[minggu][hari].lab[2].rom);
            /*LAB LSS = lab[r=3]*/
            fprintf(outfile,"%s-%s\n", j[minggu][hari].lab[3].prak, j[minggu][hari].lab[3].rom);
        }
    }
    fclose(outfile);
}

void savetocsvasisten(jadwal_t j[][5], char nama[30]) {
    /*Membuat file agar hasil dapat dimasukkan ke dalam file csv*/
    FILE *outfile;
    char nama2[40];
    nama2= strcat(nama,"_asisten.csv");
    outfile = fopen(nama2,"w");

    /*Layout jadwal*/
    fprintf(outfile,"Ruang, Praktikum, LAB1, LAB2, LAB3, LSS\n");
    fprintf(outfile,"Minggu, Hari\n");

    char day[5][7] = {"Senin","Selasa","Rabu","Kamis","Jumat"};

    /*looping untuk jadwal setiap minggu*/
    for (int minggu=3; minggu<=15; minggu++) {
        for (int hari=0; hari<=4; hari++) {
            /*layout jadwal (setiap baris selalu ada)*/
            fprintf(outfile,"%d, %s,", minggu, day[hari]);
            /*jadwal praktikum sesuai input*/
            /*asumsi: jika array kosong, maka hasil cetaknya kosong*/
            /*LAB 1 = lab[r=0]*/
            fprintf(outfile,"%s-%s,",j[minggu][hari].lab[0].assist[0],j[minggu][hari].lab[0].assist[1]);
            /*LAB 2 = lab[r=1]*/
            fprintf(outfile,"%s-%s,",j[minggu][hari].lab[1].assist[0],j[minggu][hari].lab[1].assist[1]);
            /*LAB 3 = lab[r=2]*/
            fprintf(outfile,"%s-%s,",j[minggu][hari].lab[2].assist[0],j[minggu][hari].lab[2].assist[1]);
            /*LAB LSS = lab[r=3]*/
            fprintf(outfile,"%s-%s,\n",j[minggu][hari].lab[3].assist[0],j[minggu][hari].lab[3].assist[1]);
        }
    }
    fclose(outfile);
}

void importcsv(jadwal_t j[][5], char nama[30]) {
    //variabel
    char *file;
    char s[500];
    char *string;
    //variabel penyimpanan
    char hari[255][7], lab1[255][9], lab2[255][9], lab3[255][9], lss[255][9];
    int minggu[255];
    int i=0,a=0,b=0,c=0,d=0,e=0;
    //variabel pemisah prak dan rom
    char *str;

    //input user
    printf("Masukkan nama proyek: "); scanf("%s", file);
    nama= file;
    FILE* inp;
    inp = fopen(file,"r");
    if (inp == NULL) {
        printf("File kosong.");
    } else {
        printf("File berhasil dimuat.\n");
    }

	while(fgets(s,500,inp))
	{
		//minggu
		string = strtok(s,",");
		minggu[i] = atoi(string);
		printf("-%d\n",minggu[i]);
		i++;
		//hari
        string = strtok(NULL,",");
        strcpy(hari[a],string);
        printf("-%s\n",hari[a]);
		a++;
		//lab1
		string = strtok(NULL,",");
        strcpy(lab1[b],string);
        printf("1-%s\n",lab1[b]);
		b++;
		//lab2
		string = strtok(NULL,",");
        strcpy(lab2[c],string);
        printf("2-%s\n",lab2[c]);
		c++;
		//lab3
		string = strtok(NULL,",");
        strcpy(lab3[d],string);
        printf("3-%s\n",lab3[d]);
		d++;
		//lss
		string = strtok(NULL,",");
        strcpy(lss[e],string);
        printf("s-%s\n",lss[e]);
		e++;
	}
	//masuk ke variabel jadwal_t
	//asumsi, 0 = senin, 1 = selasa, dst.
	for (int z=0; z<=i; z++) {
        //LAB1
        if (strcmp(lab1[z],"-")!=0) {
            //prak
            str = strtok(lab1[z],"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[0].prak,str);
            //rom
            str = strtok(NULL,"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[0].rom,str);
        }
        //LAB2
        if (strcmp(lab2[z],"-")!=0) {
            //prak
            str = strtok(lab2[z],"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[1].prak,str);
            //rom
            str = strtok(NULL,"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[1].rom,str);
        }
        //LAB3
        if (strcmp(lab3[z],"-")!=0) {
            //prak
            str = strtok(lab3[z],"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[2].prak,str);
            //rom
            str = strtok(NULL,"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[2].rom,str);
        }
        //LSS
        if (strcmp(lss[z],"-")!=0) {
            //prak
            str = strtok(lss[z],"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[3].prak,str);
            //rom
            str = strtok(NULL,"-");
            strcpy(j[minggu[z]][str2enum_hari(hari[z])].lab[3].rom,str);
        }

	}
}

void buatcsv(char *nama) {
    //variabel
    char *file;

    printf("Masukkan nama file proyek: "); scanf("%s", file);
    //file= nama;
    nama= file;

}


