//#define GOMB char = 'r'
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string>

struct koltes
{
	char qx[64];
	int javit;
	int rezsi;
	int kaja;
	int benya;
};

float plus(float bal, float jobb) {
	printf("%f + %f\n", bal, jobb);
	return bal + jobb;
}

float szor(float bal, float jobb) {
	printf("%f * %f\n", bal, jobb);
	return bal * jobb;
}

int mod(int bal, int jobb) {
	printf("%i mod %i\n", bal, jobb);
	return bal % jobb;
}

int main() {
	setlocale(LC_ALL, "");
	//srand(time(NULL)); 		//if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z')
	int i = 0;
	
	do {
		printf("\n1. Oszto tippeles\n");
		printf("\n2. Kiszamolo\n");
		printf("\n3. ASCII tabla tombbol\n");
		printf("\n4. Qx kiadas kalkulator\n");
		printf("\n5. kilepes\n");
		scanf_s("%i", &i);
		switch (i) {
		
		case 1:
			
			printf("\n1. - Oszto tippeles\n"); {
				int y;
				int b = 0;
				int j = 0;
				int m = 0;
				
				printf("\nAdj meg ket tetszoleges egesz szamot, es tippeld meg, milyen maradekkal oszthatak!\n\nAz algoritmus kiszamolja neked, hogy oszthatoak-e egymassal ugy, hogy a tippelt maradekot adjak!\n");
				//printf("\nNyomj entert a tovabblepeshez\n");
				//getchar();
				
				printf("\nAdd meg az else szamot:\n");
				scanf_s("%i", &b);
				
				printf("\nAdd meg a masodik szamot:\n");
				scanf_s("%i", &j);
				
				printf("\nTippeld meg a maradekot:\n");
				scanf_s("%i", &m);
				y = mod(b, j);
				
				printf("\nAz eredmeny: %i\n", y);
				
				if (y != m) {
					printf("\nNem talaltad el a maradekot.\n");
				}
				else {
					printf("\nEltalaltad, oszthatoak ezzel a maradekkal.\n");
				}
				//printf("\nNyomj entert a tov�bbl�p�shez\n");
				//getchar();
			}
			break;
		
		case 2:
			
			printf("\n2. - Kiszamolo\n"); {
				float y;
				float b = 0;
				float j = 0;
				
				printf("\nAdj meg ket tetszoleges szamot, lehet tizedestort is! Az algoritmus kiszamolja neked az osszegek negyzetet\n");
				
				printf("\nAdd meg az elso szamot:\n");
				scanf_s("%f", &b);
				
				printf("\nAdd meg a masodik szamot:\n");
				scanf_s("%f", &j);
				y = szor(plus(b, j), plus(b, j));
				
				printf("\nAz eredmeny: %f\n", y);
				//printf("\nNyomj entert a tovabblepeshez\n");
				//getchar();
			}
			break;
		
		case 3:
			
			printf("\n3. menupontot valasztottad - ASCII tabla tombbol\n"); {
				int tomb[512];
				for (int i = 0; i < 255; i++) {
					//printf("%i\t%c\t", i, i);
					tomb[i] = i;
					printf("%i\t%c\t", tomb[i], tomb[i]);
				}
				
				printf("\nHa szeretned forditva sorba rendezni a tombot, nyomj r-t!\n"); //valamiert nem mukodik a karakterbekeres, kileptet, kulon futtatva a kodreszletet jo!
				char c = 0;
				scanf_s("%c", &c, 1);
				printf_s("%c", c);
				
				if (c == 'r') {
					for (int i = 256; i > 0; i--) {
						printf("%i\t%c\t", tomb[i], tomb[i]);
					}
				}
				else {
					getchar();
					return 0;
				}
			}
			break;
		
		case 4:
			
			printf("\n4. Qx kiadas kalkulator\n"); {
				FILE* fpin;
				FILE* fpout;
				int i = 0;
				int m = 0;
				int h = 0;
				int qxszum = 0;
				struct koltes havi[4]{};
				printf("\n\nNegyedeves koltseg osszesito file be- es kiolvasassal\n\n");
				
				while (i != 5) {
					printf("\nValaszd ki a kivant negyedevet:\n");
					printf("\n1. Q1 - Januar - Februar - Marcius\n");
					printf("\n2. Q2 - Aprilis - Majus - Junius\n");
					printf("\n3. Q3 - Julius - Augusztus - Szeptember\n");
					printf("\n4. Q4 - Oktober - November - December\n");
					printf("\n5. Kilepes\n");
					scanf_s("%d", &i);
					switch (i) {
					
					case 1:
						
						printf("\nQ1 - add meg a költségeidet:\n");
						strcpy(havi[i].qx, "Januar - Februar - Marcius");
						break;
						h = 1;
					
					case 2:
						
						printf("\nQ2 - add meg a költségeidet:\n");
						strcpy(havi[i].qx, "Aprilis - Majus - Junius");
						h = 4;
						break;
					
					case 3:
						
						printf("\nQ3 - add meg a költségeidet:\n");
						strcpy(havi[i].qx, "Julius - Augusztus - Szeptember");
						h = 7;
						break;
					
					case 4:
						
						printf("\nQ4 - add meg a költségeidet:\n");
						strcpy(havi[i].qx, "Oktober - November - December");
						h = 10;
						break;
					
					case 5:
						
						printf("\nKilepes\n");
						//break;
						return 0;
					
					default:
						
						printf("\nHibas bemenet\n");
						break;
					}

					printf("\nHonapok neve: %s\n", havi[i].qx);
					do {
						printf("\n%d. honap:\n", h);
						printf("\nJavitas, felujitas:\n");
						scanf_s("%d", &havi[i].javit);

						printf("\nRezsi:\n");
						scanf_s("%d", &havi[i].rezsi);

						printf("\nEtel:\n");
						scanf_s("%d", &havi[i].kaja);

						printf("\nUzemanyag:\n");
						scanf_s("%d", &havi[i].benya);

						fpout = fopen("koltseg.txt", "a+");

						fprintf(fpout, "%d %d %d %d ", havi[i].javit, havi[i].rezsi, havi[i].kaja, havi[i].benya);

						printf_s("\nAktualis ho kiadasai: %d %d %d %d\n", havi[i].javit, havi[i].rezsi, havi[i].kaja, havi[i].benya);
						fclose(fpout);

						i++;
						m++;
						h++;
					} while (m != 3);

					fpin = fopen("koltseg.txt", "r");
					int q = 0;
					int sz = 0;

					while (!feof(fpin)) {
						fscanf(fpin, "%d", &sz);
						qxszum = qxszum + sz;
						q++;
					}

					qxszum = qxszum - sz;
					fclose(fpin);
					printf_s("\nNegyedeves kiadasok osszesitve: %d\n", qxszum);
					fpout = fopen("koltseg.txt", "a+");
					fprintf(fpout, " %d", qxszum);
					fclose(fpout);
					getchar();
					//return 0;
				}

			}
			break;
		
		case 5:

			printf("\nKileptel, viszlat!\n");
			break;

		default:
			
			printf("\nHibas bemenet!\n");
			printf("\nSzamot irj be, ne betut!\n");
			getchar();
			return 0;
			break;
		}
	} while (i != 5);
}
























































