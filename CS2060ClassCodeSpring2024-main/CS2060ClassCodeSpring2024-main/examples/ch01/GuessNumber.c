// Randomly generate numbers between a min and max for user to guess.


//allows for certain code to be used by allowing the use of other programs.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//setting the min and max to switch
#define MIN 1
#define MAX 1000

//activating the two functions.
void guessGame(void); 
bool isCorrect(int guess, int answer); 

int main(void) {
    //seeds the random generator rand() 
   //srand(time(0)); 

   //calling the Method so it starts the game 
   guessGame();
} // end main



// function with the code for the game
void guessGame(void) {
    
    //setting 0 to two variables and displaying Hello Deb
   int response =0;
   int guess = 0;
   printf("Hello Deb\n");
   // do while loop for the guessing of the random number
   do {

      //
      int answer = 1 + rand() % MAX;
      
      //explanation
      printf("I have a number between %d and %d.\n", MIN, MAX);

      // instructions for the game
      puts("Can you guess my number?\n" 
           "Please type your first guess.");

      //prompting the user to enter their guess
      printf("%s", "? ");
      

      //read from the keyboard and store it as guess
      scanf("%d", &guess);

      // sends the two values to the isCorrect function if it returns false the code repeats.
      while (!isCorrect(guess, answer)) {
         scanf("%d", &guess);
      }


      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");
      printf("%s", "Please type (1=yes, 2=no)? ");
      scanf("%d", &response);
      puts("");

   } while (response == 1);
} // end function guessGame

// isCorrect function to use booleans to check the answers.
bool isCorrect(int guess, int answer) {

    // sets the boolean correct to false.
    bool correct = false;

   // if guess and answer are equal then it sets correct to true
   if (guess == answer) {
      correct = true;
   }

   // when guess is to low and when its to high
   if (guess < answer) {
      printf( "%s", "Too low. Try again.\n? " );
   }
   else {
      printf( "%s", "Too high. Try again.\n? " );
   }

   return correct;
} // end function isCorrect



/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
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
 **************************************************************************/
