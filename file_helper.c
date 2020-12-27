/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Thi Khanh Nhi Le          tknle1@myseneca.ca
   2) Chiao Ya Chang            cchang76@myseneca.ca
   3) YoonYeong Jeong           yjeong17@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.c                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   |                                                        |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   |  !!!      DO NOT ALTER THE CONTENTS BELOW         !!!  |
   |  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include "file_helper.h"
#define SIZE 5000
#include <string.h>
#include <math.h>
   /********************************************************/
   /* Read from the opened file the time (HH:MM) parts of  */
   /* the record and return the time as decimal hours      */
   /********************************************************/
double readTime(FILE* fp)
{
	int hour, min;

	fscanf(fp, "%d%*c", &hour);
	fscanf(fp, "%d", &min);

	return hour + (min / 60.0);
}

/********************************************************/
/* Read all the information on one rider from the valid */
/* (pre-opened) file and store it in the struct.        */
/* Return true when end of file has been reached.       */
/********************************************************/
int readFileRecord(FILE* fp, struct RiderInfo* info)
{
	int result = 1, ch;

	if (!feof(fp))
	{
		result = 0;

		// read from file and assign to data structure
		fscanf(fp, "%[^,]%*c", info->name);
		fscanf(fp, "%d", &info->age);
		fscanf(fp, " %c", &info->raceLength);
		info->startTime = readTime(fp);
		info->mountainTime = readTime(fp);
		info->finishTime = readTime(fp);

		// Last Field (withdrawn: may not be present)
		ch = fgetc(fp);
		info->withdrawn = 0;

		if (ch == ' ')
		{
			ch = fgetc(fp);
			info->withdrawn = ch == 'W';
			ch = fgetc(fp);
		}

		// clear input file buffer until end of line (record):
		while (!feof(fp) && ch != '\n')
		{
			ch = fgetc(fp);
		}
	}

	return result;
}

int getNumber(int min, int max) {
	int num = 1000;
	int inRange = 0; //not in range

	do {
		scanf("%d", &num);
		inRange = num >= min && num <= max;

		if (!inRange)
		{
			printf("Option is out of range, option is between %d and %d only: ", min, max);
		}
	} while (!inRange);

	return num;
}

int hour(double start, double end)
{
	return end - start;
}

int minute(double start, double end)
{
	int hours;
	hours = hour(start, end);
	double k = ((end - start - hours) * 60.0);
	return round(k);
}

const char* ageGroup(int age)
{
	char* a = "bc";
	if (age >= 16 && age <= 20) {
		a = "Juniors";
	}
	if (age >= 21 && age <= 34) {
		a = "Adult";
	}
	if (age >= 35) {
		a = "Senior";
	}
	return a;
}

const char* withdrew(int withdraw)
{
	char* a = "any";
	if (withdraw == 1) {
		a = "Yes";
	}
	else if (withdraw == 0)
	{
		a = "No";
	}
	return a;
}

const char* printkm(char ch)
{
	char* a = "any";

	if (ch == 'S' || ch == 's')
	{
		a = "50 km";

	}
	if (ch == 'M' || ch == 'm')
	{
		a = "75 km";

	}
	if (ch == 'L' || ch == 'l')
	{
		a = "100 km";

	}
	return a;
}

void displayHeaderShort(void) {
	printf("\nRider                    Age Group Time\n---------------------------------------\n");
}

void displayHeaderLong(void) {
	printf("\nRider                    Age Group Time Withdrew\n------------------------------------------------\n");
}

void sortRiderInfo(struct RiderInfo cate[], int sz) {
	struct RiderInfo temp;
	int i;
	int j;
	int k = 0; //for char
	char ch[4] = "SML";

	for (i = 0; i < sz - 1; i++) {

		for (j = 0; j < sz - i - 1 && strlen(ch) < 4; j++) {
			
	

					if ((cate[j].finishTime - cate[j].startTime) > (cate[j + 1].finishTime - cate[j + 1].startTime))
					{
						temp = cate[j];
						cate[j] = cate[j + 1];
						cate[j + 1] = temp;

					}
		
			

		}

	}
}

void startBikeRaceManager(struct RiderInfo* ri, int count) {

	int exit = 0; //fail to exit
	
	struct RiderInfo cate[SIZE] = { {0} };
	struct RiderInfo loser[SIZE] = { {0} };
	

	//do copy to apply sort

	int i;
	for (i = 0; i < SIZE; i++) {
		if(ri[i].withdrawn == 1 )
		{
			strcpy(loser[i].name, ri[i].name);
			loser[i].age = ri[i].age;
			strcpy(&loser[i].raceLength, &ri[i].raceLength);
			strcpy(&loser[i].withdrawn, &ri[i].withdrawn);
		}
		else
		{
			strcpy(cate[i].name, ri[i].name);
			cate[i].age = ri[i].age;
			strcpy(&cate[i].raceLength, &ri[i].raceLength);
			cate[i].startTime = ri[i].startTime;
			cate[i].finishTime = ri[i].finishTime;
			
		}
	}


	sortRiderInfo(cate, count);

	
	do {
		char ch = 'a';

		switch (menu()) {
		case 1:
			ch = whichCategory();
			displayTopRiders(cate, ch, count);
			
			break;

		case 2:
			ch = whichCategory();
			displayAllRiders(cate, loser, count, ch);
			
			break;

		case 3:
			ch = whichCategory();
			displayLastRiders(cate, ch, count);
			break;

		case 4:
			displayWinnersInAllCate(cate, count);
			break;

		case 0:
			printf("\n Keep on Riding!");
			exit = 1;

		}
		printf("\n");

	} while (!exit);
}

int menu(void)
{

	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Print top 3 riders in a category\n");
	printf("2 - Print all riders in a category \n");
	printf("3 - Print last 3 riders in a category\n");
	printf("4 - Print winners in all categories \n");
	printf(": ");
	return getNumber(0, 4);
}
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

char whichCategory(void)
{
	char nl = 'a';
	char ch = 'a';
	int keepRunning = 1;
	clearKeyboard();
	do
	{
		printf("\nWhich category (S, M, L): ");
		scanf("%c%c", &ch, &nl);

		if (nl == '\n') {
			if (ch == 'S' || ch == 's') {

				if (ch == 's')
				{
					ch = 'S';
				}
				keepRunning = 0;
			}
			else if (ch == 'M' || ch == 'm') {
				if (ch == 'm')
				{
					ch = 'M';
				}
				keepRunning = 0;
			}
			else if (ch == 'L' || ch == 'l') {
				if (ch == 'l')
				{
					ch = 'L';
				}
				keepRunning = 0;

			}
		}
		else {
			clearKeyboard();
		}
		if (keepRunning) {
			printf("ERORR*** only S/s M/m L/l is accept\n");
		}
	} while (keepRunning);

	return ch;
}

void displayAllRiders(struct RiderInfo cate[], struct RiderInfo loser[], int sz, char ch)
{
	int i;
	
	displayHeaderLong();
	for (i = 0; i < sz; i++)
	{
		if (cate[i].raceLength == ch)
		{
			
			 printf("%-27s %7s %d:%02d %7s\n", cate[i].name, ageGroup(cate[i].age), hour(cate[i].startTime, cate[i].finishTime), minute(cate[i].startTime, cate[i].finishTime), withdrew(cate[i].withdrawn) ); 
			
		}
	}

	//print loser at the bottom
	int j;
	int found = 0;
	for (j = 0; j < sz && found == 0; j++)
	{
		if ( strlen(loser[j].name) != 0)
		{
			printf("%-27s %7s  N/A %7s\n", loser[j].name, ageGroup(loser[j].age), withdrew(loser[j].withdrawn));
		}
	}
}

void displayTopRiders(struct RiderInfo cate[], char ch, int sz)
{
	int i,j;
	int topthree = 0;

	displayHeaderShort();
	for (i = 0; i < sz && topthree < 3; i++)
	{

		if (cate[i].raceLength == ch && cate[i].name != ' ')
		{
			
			printf("%-26s %7s %d:%02d\n", cate[i].name, ageGroup(cate[i].age), hour(cate[i].startTime, cate[i].finishTime), minute(cate[i].startTime, cate[i].finishTime));
		
			topthree++;
		}
	}
}

void displayLastRiders(struct RiderInfo cate[], char ch, int sz)
{
	int i, j,k=0;
	int lastthree = 0; // to count if the number of people is equal to 3
	struct RiderInfo last[3] = { {0} };

	displayHeaderShort();

	for ( i = sz - 1; i >= 0 && lastthree < 3; i --) // this is a trick for S ONLY
	{
		//printf("j is %d\n", j);
		if (cate[i].raceLength == ch)
		{
			
			strcpy(last[k].name, cate[i].name);
			last[k].age = cate[i].age;
			strcpy(&last[k].raceLength, &cate[i].raceLength);
			last[k].startTime = cate[i].startTime;
			last[k].finishTime = cate[i].finishTime;
				

				lastthree++;
				k++;
		}

	}

	//diaplay reverse
	for (j = 2; j >=0 ; j--) {
		printf("%-26s %7s %d:%02d\n", last[j].name, ageGroup(last[j].age), hour(last[j].startTime, last[j].finishTime), minute(last[j].startTime, last[j].finishTime));
	}

}

void displayWinnersInAllCate(struct RiderInfo cate[], int sz)
{
	int i, j;
	int found = 0; // check if it matches with the category
	char ch[4] = "SML";
	printf("\nRider                    Age Group Category Time\n------------------------------------------------ \n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 15 && found == 0 && strlen(ch) < 4; j++)
		{
			if (cate[j].raceLength == ch[i] && cate[i].name != ' ')
			{
				
				printf("%-26s %7s %8s %d:%02d\n", cate[j].name, ageGroup(cate[j].age), printkm(cate[j].raceLength), hour(cate[j].startTime, cate[j].finishTime), minute(cate[j].startTime, cate[j].finishTime));
				
				found = 1;
			}

		}
		found = 0;
	}

}


