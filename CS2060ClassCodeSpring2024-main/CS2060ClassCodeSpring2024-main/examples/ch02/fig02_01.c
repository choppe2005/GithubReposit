// fig02_01.c
// A first program in C.
#include <stdio.h>
int length = 0 ;
int width = 0;
int area = 0;
int scanfReturn = 0;
// function main begins program execution 
int main(void) {
   printf("Welcome to C!\n");

   puts("enter the length");

   scanf("%d", &length);

   puts("enter the Width");

   scanf("%d", &width);

	area = length * width;

	//scanfReturn = scanf();

	printf("length=%d\nwidth=%d\narea=%d",length,width,area);

	return 0;
} // end function main 



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
