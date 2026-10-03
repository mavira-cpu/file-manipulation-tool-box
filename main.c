// to compile this program the command is gcc main.c library.c /(to include the other file with the function) then ./a.out
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "library.h"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
int main(){
 int choice;
    while(1){

    printf(CYAN"  ___________________________________________________\n");
    printf(" |                                                   |\n");
    printf(" |  _____ ___   ___  _       ____   _____  __        |\n");
    printf(" | |_   _/ _ \\ / _ \\| |     | __ ) / _ \\ \\/ /        |\n");
    printf(" |   | || | | | | | | |     |  _ \\| | | \\  /         |\n");
    printf(" |   | || |_| | |_| | |___  | |_) | |_| /  \\         | \n");
    printf(" |   |_| \\___/ \\___/|_____| |____/ \\___/_/\\_\\        |\n");
    printf(" |                                                   |\n");
    printf(" |  please enter a number between 1 and 9 to perform |\n");
    printf(" |       the chosen operation.                       |\n");
    printf(" |                                                   |\n");
    printf(" |    1. create a and write in file.                 |\n");
    printf(" |    2. read and Display File Contents.             |\n");
    printf(" |    3. copy the contents of a file                 |\n");
    printf(" |    4. count the number of lines in a file.        |\n");
    printf(" |    5. find the longest line in the chosen file.   |\n");
    printf(" |    6. reverse the contents of the chosen file.    |\n");
    printf(" |    7. merge the contents of two files into a      |\n");
    printf(" |        third one.                                 |\n");
    printf(" |    8. find number of occurrences of a given word  |\n");
    printf(" |        in the file.                               |\n");
    printf(" |    9. replace all occurrences of a given word     |\n");
    printf(" |          in a file with another word.             |\n");
    printf(" |    0. Exit.                                       |\n");
    printf(" |                                                   |\n");
    printf(" |___________________________________________________|\n" RESET);
    
    scanf("%d",&choice);

  switch (choice) {

case 1: createAndWriteToFile(); break;
case 2: readAndDisplayFile(); break;
case 3: copyFile(); break;
case 4: countLinesInFile(); break;
case 5: findLongestLine(); break;
case 6: reverseFile(); break;
case 7: mergeFiles(); break;
case 8: findWordOccurrences(); break;
case 9: replaceWordInFile(); break;
case 0: exit(0); break;
default: printf("Invalid choice. Please try again.\n");
}
}}
