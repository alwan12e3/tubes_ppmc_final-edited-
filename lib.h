#ifndef LIB_H
#define LIB_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


typedef struct 
{
    int count;
    char id[255];
}rombongan_t;

typedef struct 
{
    char id[255];
    rombongan_t r[7];
}prak_t;

typedef struct
{
    int count;
    int assist_count;
    char assist[2][255];
    char id[255];
    char prak[255];
    char rom[255];
}lab_t;

typedef struct 
{
    lab_t lab[4];
}jadwal_t;

typedef struct
{
	char* nama;
	char* prak[4];
	char* hari[5];
} asisten;

enum hari
    {Senin, Selasa, Rabu, Kamis, Jumat};

const static struct {
    enum hari val;
    const char *str;
} conversion_hari [] = {
    {Senin, "Senin"},
    {Selasa, "Selasa"},
    {Rabu, "Rabu"},
    {Kamis, "Kamis"},
    {Jumat, "Jumat"},
};


enum prak
    {EL2205, EL2208, EB2200};

const static struct {
    enum prak      val;
    const char *str;
} conversion_prak [] = {
    {EL2205, "EL2205"},
    {EL2208, "EL2208"},
    {EB2200, "EB2200"},
};


enum lab
    {LAB1, LAB2, LAB3, LSS};


const static struct {
    enum lab val;
    const char *str;
} conversion_lab [] = {
    {LAB1, "LAB1"},
    {LAB2, "LAB2"},
    {LAB3, "LAB3"},
    {LSS, "LSS"},
};

enum prak str2enum_prak (const char *str);
enum hari str2enum_hari (const char *str);
enum prak str2enum_lab (const char *str);
int syarat_rombongan(int r, char *s);

int input_minggu();

int input_hari(int prak, int s_r, int w, jadwal_t j[][5]);

int input_ruangan(int a, int b, jadwal_t l);

int max_rom(int prak);

void input_sch(jadwal_t j[][5], prak_t *p);

void auto_input_sch(jadwal_t j[][5], prak_t *p);

int search(char* array[], char* item, int max_length);

asisten namaAsisten (char initial);

void scanMinggu(int* week);

void scanHari(char* day);

void scanRuang(char* ruang);

int cekBisa(asisten asis, char* item);

int cekAda(asisten asis, int week, char* day, char* lab, jadwal_t jadwal[][5]);

void assignAsisten(jadwal_t jadwal[][5]);

void AssignAsistenManual(jadwal_t jadwal[][5]);

void tampil_as(jadwal_t jadwal_prak[][5]);

void tampil_sche(jadwal_t jad[][5]);

void ruller_checker(int minggu[], int day[], int i, jadwal_t jadwal_prak[][5]);

void autobot(jadwal_t jadwal[][5], prak_t *p);

void randomize(int prak, int rom, jadwal_t j[][5], prak_t *p);

int syarat_minggu(int prak, int rom, jadwal_t j[][5]);

int syarat_hari(int prak, int rom, int w, jadwal_t j[][5]);

int syarat_lab(int prak, int rom, jadwal_t j[][5], int w, int h);

void savetocsvjadwal(jadwal_t j[15][5]);

void savetocsvasisten(jadwal_t j[15][5]);

void buatcsv(char *nama);

void importcsv(jadwal_t j[][5]);

#endif
