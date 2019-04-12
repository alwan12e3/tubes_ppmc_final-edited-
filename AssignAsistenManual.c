//***********************************************************//
// [ Source Code ]
//
// Institution : Institut Teknologi Bandung
// Name : Fikki Maulana Aulia Siswanto
// File Name : AssignAsistenManual.c
// Dependency : "lib.h"
//
// Description:
// assign asisten yang diinput dari STDIN ke (jadwal_t) jadwal
// jika semua verifikasi terpenuhi
//
// Status:
// 1. Fikki Maulana - 13217033 : membuat program
// 2. Alwan Abdurrafi - 18316025 : edit supaya bisa dicompile
//                      koreksi script
//
//
//***********************************************************//
#include "lib.h"

//cek search lagi
int search(char* array[], char* item, int max_length)
{
    int i=0, val=0;
    while((array[i]!=NULL)&&(i<max_length))
    {
			if (strcmp(array[i],item)==0)
			{
				val = 1; //ditemukan
				break;
			} else
			{
				i=i+1;
			}
	}
	return(val);
}

asisten namaAsisten (char initial)
{
	asisten Assist={0};
	if (initial=='A')
	{
		Assist.nama = "Amir";
		Assist.prak[0] = "EL2205";
		Assist.hari[0] = "Rabu";
	} else if (initial=='B')
	{
		Assist.nama = "Budi";
		Assist.prak[0] = "EL2205";
		Assist.hari[0] = "Senin";
	} else if (initial=='C')
	{
		Assist.nama = "Cici";
		Assist.prak[0] = "EL2205";
		Assist.hari[0] = "Selasa";
		Assist.hari[1] = "Rabu";
	} else if (initial=='D')
	{
		Assist.nama = "Doni";
		Assist.prak[0] = "EL2205";
		Assist.hari[0] = "Senin";
		Assist.hari[1] = "Rabu";
	} else if (initial=='E')
	{
		Assist.nama = "Endang";
		Assist.prak[0] = "EL2205";
		Assist.prak[1] = "EL2208";
	} else if (initial=='F')
	{
		Assist.nama = "Fadel";
		Assist.prak[0] = "EL2205";
		Assist.hari[0] = "Selasa";
	} else if (initial=='G')
	{
		Assist.nama = "Gilang";
		Assist.prak[0] = "EL2205";
		Assist.prak[1] = "EB2200";
		Assist.hari[0] = "Kamis";
	} else if (initial=='H')
	{
		Assist.nama = "Hero";
		Assist.prak[0] = "EL2208";
		Assist.hari[0] = "Kamis";
	} else if (initial=='I')
	{
		Assist.nama = "Intan";
		Assist.prak[0] = "EL2205"; 
		Assist.prak[1] = "EL2208";
		Assist.prak[2] = "EB2200";
		Assist.hari[0] = "Rabu";
	} else if (initial=='J')
	{
		Assist.nama = "Joko";
		Assist.prak[0] = "EL2208";
		Assist.hari[0] = "Jumat";
	} else if (initial=='K')
	{
		Assist.nama = "Kiki";
		Assist.prak[0] = "EL2208", 
		Assist.prak[1] = "EB2200";
		Assist.hari[0] = "Jumat";
	} else if (initial=='L')
	{
		Assist.nama = "Luis";
		Assist.prak[0] = "EL2208";
	} else if (initial=='M')
	{
		Assist.nama = "Mini";
		Assist.prak[0] = "EL2208";
		Assist.hari[0] = "Rabu";
		Assist.hari[1] = "Kamis";
	} else if (initial=='N')
	{
		Assist.nama = "Nina";
		Assist.prak[0] = "EL2208";
		Assist.prak[1] = "EB2200";
	}
	return(Assist);
}

void scanMinggu(int* week)
{
	do
	{
		printf("Minggu: "); scanf("%d", week);
		if (((*week-3)<0)||((*week-3)>12))
		{
			printf("Minggu salah\n");
		}
	} while (((*week-3)<0)||((*week-3)>12));
}

void scanHari(char* day)
{
	do
	{
		printf("Hari: "); scanf("%s",day);
		if ((str2enum_hari(day)<0)||(str2enum_hari(day)>4))
		{
			printf("Hari salah\n");
		}
	} while ((str2enum_hari(day)<0)||(str2enum_hari(day)>4));
}

void scanRuang(char* ruang)
{
	do
	{
		printf("Ruang: "); scanf("%s", ruang);
		if ((str2enum_lab(ruang)<0)||(str2enum_lab(ruang)>3))
		{
			printf("Ruang salah\n");
		}
	} while ((str2enum_lab(ruang)<0)||(str2enum_lab(ruang)>3));
}

int cekBisa(asisten asis, char* item)
{
	int val;
	if(search(asis.hari, item, 5)==0)
	{
		val = 1;
	} else
	{
		val = 0;
	}
	return(val);
}

int cekAda(asisten asis, int week, char* day, char* lab, jadwal_t jadwal[][5])
{
	int val;
	int hari = str2enum_hari(day);
	int room = str2enum_lab(lab);

	char* prak = jadwal[week-3][hari].lab[room].prak;
	if(search(asis.prak, prak, 4)==1)
	{
		val = 1;
	} else
	{
		val = 0;
	}
	return(val);
}

void assignAsisten(jadwal_t jadwal[][5])
{
	char init[50];
	char lab[255];
	char day[255];
	int week;
	asisten Assist_func={0};
	do
	{
		int test = 0;
		do
		{
			printf("Pilih Asisten (A-N): ");
			scanf("%s", init);
			if((strcmp(init,"A")!=0)&&(strcmp(init,"B")!=0)&&(strcmp(init,"C")!=0)&&(strcmp(init,"D")!=0)&&(strcmp(init,"E")!=0)&&(strcmp(init,"F")!=0)&&(strcmp(init,"G")!=0)&&(strcmp(init,"H")!=0)&&(strcmp(init,"I")!=0)&&(strcmp(init,"J")!=0)&&(strcmp(init,"K")!=0)&&(strcmp(init,"L")!=0)&&(strcmp(init,"M")!=0)&&(strcmp(init,"N")!=0)&&(strcmp(init,"q")!=0)&&(strcmp(init,"Q")!=0))
			{
				printf("Tidak ada asisten\n");
			}
			else
			{
      	test = 1;
			}
		} while (test==0);

		if((strcmp(init,"Q")!=0)&&(strcmp(init,"q")!=0)) //pasti asisten ada
		{
			Assist_func = namaAsisten(init[0]);
			scanMinggu(&week);
			scanHari(day);
			scanRuang(lab);
			if (jadwal[week-3][str2enum_hari(day)].lab[str2enum_lab(lab)].assist_count < 2) //jumlah asisten kurang dari dua
			{
				if (cekAda(Assist_func, week, day, lab, jadwal))
				{
					//ada praktikum bersangkutan, cek bisa asisten bisa atau engga
					if (cekBisa(Assist_func, day))
					{
						//cek apakah asisten bisa, jika bisa masukkan ke schedule
						int count = jadwal[week-3][str2enum_hari(day)].lab[str2enum_lab(lab)].assist_count;
						strcpy(jadwal[week-3][str2enum_hari(day)].lab[str2enum_lab(lab)].assist[count], Assist_func.nama);
						jadwal[week-3][str2enum_hari(day)].lab[str2enum_lab(lab)].assist_count++; //jumlah assist_count naik
						printf("Data asisten telah dimasukkan\n\n");
					} else
					{
						//cetak error asisten tidak bisa
						printf("Asisten berhalangan pada hari %s\n", day);
					}
				} else
				{
					printf("Jadwal Asisten Praktikum tidak sesuai (tidak ada praktikum bersangkutan)\n");
				}
			} else
			{
				printf("Asisten sudah penuh\n");
			}
		}
	} while ((strcmp(init,"Q")!=0)&&(strcmp(init,"q")!=0));
	//return;
}

void AssignAsistenManual(jadwal_t jadwal[][5]) //fungsi yang bisa dipanggil oleh main (bener2 main)
{
	printf("[Mode Assign Asisten]\n");
	printf("Isi `q` atau `Q` untuk kembali ke menu\n");
	assignAsisten(jadwal); 
}

/*int main()
{
	jadwal_t jadwal[12][5]={0};
	printf("[Mode Assign Asisten]\n");
	printf("Isi 'q' atau 'Q' untuk kembali ke menu\n");
	assignAsisten(jadwal);
	return 0;
}*/
