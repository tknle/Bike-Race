/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Thi Khanh Nhi Le          tknle1@myseneca.ca
   2) Chiao Ya Chang            cchang76@myseneca.ca
   3) YoonYeong Jeong           yjeong17@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "file_helper.h"
#define SIZE 5000

int main(void)
{
	// TODO: Code the necessary logic for your solution below
	//
	// NOTE: Use modularity whenever possible in your design
	//
	// HINTS:
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
	//
	// 2) Create a menu system to provide the user with
	//    the reporting options
	//
	// 3) Generate the user-selected report

    printf("******************** Seneca Cycling Race Results ********************\n");

    struct RiderInfo ri[SIZE] = { {0} };

    FILE* fp = NULL;
    int j = 0;
    int count = 0; // to count line in the file
    fp = fopen("data.txt", "r");
 
        if (fp != NULL) 
        {
            while (j < SIZE)
            {
                if (readFileRecord(fp, &ri[j]) == 0) 
                {
                    //reach the end of line
                    count++;
                }
                j++;
            }
            fclose(fp);
        }
        else
        {
            printf("***ERROR*** CANNOT OPEN FILE\n");
        }
      
    startBikeRaceManager(ri,count+1);
    

	return 0;
}
