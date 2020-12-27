/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Thi Khanh Nhi Le          tknle1@myseneca.ca
   2) Chiao Ya Chang            cchang76@myseneca.ca
   3) YoonYeong Jeong           yjeong17@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.h                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

   /********************************************************/
   /* Define the missing members for the RiderInfo data    */
   /* used to store Rider information read from a file     */
   /********************************************************/
struct RiderInfo
{
    // TODO:  Fill in the missing members:
    char name[21];
    int age;
    char raceLength;
    double startTime;
    double mountainTime;
    double finishTime;
    char withdrawn;

};


/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!        DO NOT ALTER THE CONTENTS BELOW       !!!*/
/*!!!             ( function prototype )           !!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/********************************************************/
/* Read all the information on one rider from the       */
/* file and store it in the struct. Return true         */
/* when end of file has been reached.                   */
/********************************************************/

//readFileRecord will read each line of file in the record
int readFileRecord(FILE* fp, struct RiderInfo* info);

//run the whole cycling program
void startBikeRaceManager(struct RiderInfo* ri, int count);
//show users the options to lookup
int menu(void);

//the range for 0 to 4 options
int getNumber(int, int);

//calculate rider's minute
int minute(double start, double end);

//calculate rider's hour
int hour(double start, double end);

//prompt to the user the option we choose
char whichCategory(void);

//clear the buffer
void clearKeyboard(void);

//devide all riders from an array of group distribute by their age
void displayAllRiders(struct RiderInfo cate[], struct RiderInfo loser[], int sz, char ch);

//group distribute by their age
const char* ageGroup(int);

//show who withdrew from the race
const char* withdrew(int withdraw);

//display the header rider, age group, time for output
void displayHeaderShort(void);

//display the header rider, age group, category, time , withdrew for output 
void displayHeaderLong(void);

//reverse the bottom riders to the top
void sortRiderInfo(struct RiderInfo cate[], int sz);

//display the fastest 3 riders
void displayTopRiders(struct RiderInfo cate[], char ch, int sz);

//display the slowest 3 riders
void displayLastRiders(struct RiderInfo cate[], char ch, int sz);

//display the fastest riders in each group
void displayWinnersInAllCate(struct RiderInfo cate[], int sz);

//display the km for riders
const char* printkm(char ch);

#endif
