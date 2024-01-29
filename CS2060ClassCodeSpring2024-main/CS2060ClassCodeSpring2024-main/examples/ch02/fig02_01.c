// fig02_01.c
// A first program in C.
#include <stdio.h>
int a = 1;
int length = 0 ;
int width = 0;
int area = 0;
double avg = 0;
int scanfReturn1 = 0;
int scanfReturn2 = 0;
// function main begins program execution 
int main(void) {
   printf("Welcome to C!\n");
   do {
	   puts("enter the length");
	   scanfReturn1 = scanf("%d", &length);
	   if (scanfReturn1 == 1 && length >= 0) {
		   a = 0;
	   }
	   else {
		   printf("invalid input pls try again and enter an integer!?\n");
		   while (getchar() != '\n');
			}
	   } while (a == 1);
	   a = 1;
	   do {
		   puts("enter the width");

		   scanfReturn2 = scanf("%d", &width);
		   if (scanfReturn2 == 1 && width >= 0) {
			   a = 0;
		   }
		   else {
			   printf("invalid input pls try again and enter an integer!?\n");
			   while (getchar() != '\n');
		   }
	   } while (a == 1);
	   avg = (length + width) / 2.0;
	   area = length * width;

	   printf("average of length and width:%0.1f\n", avg);
	   printf("length=%d\nwidth=%d\narea=%d", length, width, area);

	   return 0;
}
 // end function main 



/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
