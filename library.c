#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1st function this code creates a file and asks the user whether he/she writes in it or not 
void createAndWriteToFile(){
    printf("what would like to name your file:\n");
    char name_of_file[50];
    scanf("%s",name_of_file);
    FILE* filepointer= fopen(name_of_file,"w");
    if(filepointer==NULL){printf("error opening the file of writing\n");}else{
    int x=1;
    while (x==1)
    {
        
    printf("do you want to write in this file?\n please with yes or no \n");
    char answer[10];
    scanf("%s",answer);
    
    if (strcmp(answer,"yes")==0){
    
        printf("what would you like to write in the file:\n");
        char buffer[1000];
        scanf(" %[^\n]s",buffer);
        fprintf(filepointer,"%s\n",buffer);
        x=0;
        fclose(filepointer);
    }else if (strcmp(answer,"no")==0)
    {
        fclose(filepointer);
     x=0;
    }else{
     printf("please awnser with yes or no\n");
    }
    }}}


//2nd function this code reads the  contents of a file and displays them in the screen.
void readAndDisplayFile(){
    printf("enter the name of the file:\n");
    char name_of_file [50];
    scanf("%s",name_of_file);
    FILE* filepointer;
    filepointer= fopen(name_of_file,"r");
    if(filepointer==NULL)
    {
        printf("error opening the file\n");
        
    }else{
    fseek(filepointer,0,SEEK_END);
    int filesize=ftell(filepointer);
    fseek(filepointer,0,SEEK_SET);
    char buffer[filesize+1];
    fread(buffer,sizeof(char),filesize,filepointer);
    buffer[filesize]='\0';
    printf("%s\n",buffer);
    fclose(filepointer);
}}


//3rd function this code copys the contents of one file to another file with the code asks the user for their names.
void copyFile(){
    printf("enter the name of the file copied \n");
    char name1[50];
    scanf("%s",name1);
    printf("enter the name of the file copied into \n");
    char name2[50];
    scanf("%s",name2);
    FILE* filepointer = fopen(name1,"r");
    if (filepointer==NULL)
    {
        printf("error opening the 1st file.\n");
    }else{
    fseek(filepointer,0,SEEK_END);
    int filesize=ftell(filepointer);
    fseek(filepointer,0,SEEK_SET);
    char buffer[filesize];
   size_t bytes_read_from_file1=fread(buffer,sizeof(char),sizeof(buffer)-1,filepointer);
    fclose(filepointer);
    filepointer=fopen(name2,"w");
    if (filepointer==NULL)
    {
        printf("error opening the 2nd file.\n");
        
    }else{
    fwrite(buffer,sizeof(char),bytes_read_from_file1,filepointer);
    fclose(filepointer);
}}}


//4th function this code counts the number of line in a file that it asks the name of it 
void countLinesInFile(){
     char name_of_file [50];
    int number_of_lines=0;
    printf("enter the name of the file :\n");
    scanf("%s",name_of_file);
    FILE* filepointer = fopen(name_of_file,"r");
    if(filepointer!=NULL){
    char words[2050];
   
    while(fgets(words,2050,filepointer)){
        number_of_lines++;
    }
    fclose(filepointer);
    printf("the number of lines is :\n %d\n",number_of_lines);}
    else{
        printf("error opening the file.\n");
    }
}



// 5th function this code finds the longest line in a file.

void findLongestLine(){
    char name_of_file[50];
printf("enter the name of the file \n");
scanf("%s",name_of_file);
 FILE* filepointer=fopen(name_of_file,"r");
 if (filepointer==NULL)
 {
    printf("error opening the file for reading.\n");
 }else{
 
char buffer[1000];
int longest_line=0;
int longest_line_index=0;
int line_index=1;
while(fgets(buffer,1000,filepointer)){
    int line=0;
    int i=0;
    while(buffer[i]!='\n' &&buffer[i]!='\0'){
        line++;
        i++;
    }
    if(line>longest_line){
        longest_line=line;
        longest_line_index=line_index;
    }
  line_index++;
}
fclose(filepointer);
printf("the longest line in the file is %d\n",longest_line_index);
}}


//6th function this code reverses the contents of a file 
void reverseFile(){
        FILE* filepointer;
    char name_of_file[50];
    printf("enter the name of the file \n");
    scanf("%s",name_of_file);
    filepointer=fopen(name_of_file,"r");
    if(filepointer!= NULL){
        fseek(filepointer,0,SEEK_END);
        int filesize=ftell(filepointer);
        fseek(filepointer,0,SEEK_SET);
     char* buffer=malloc(filesize);
    size_t byteread=fread(buffer,sizeof(char),filesize,filepointer);
    
    char  tem;
    for(int i = 0;i<byteread/2;i++){
        tem = buffer[i];
        buffer[i]=buffer[filesize-1-i];
        buffer[filesize-1-i]=tem;
    }
    fclose(filepointer);
    filepointer=fopen(name_of_file,"w");
    if (filepointer==NULL)
    {
        printf("error opening the file for writing \n");
        
    }else{
    
    fwrite(buffer,sizeof(char),byteread,filepointer);
    fclose(filepointer);
    printf("please check your chosen file for results. \n");}}else{
        printf("there is no file with this name \n");
    }

}

//7th functoin this code merges two file into a new one.
 void mergeFiles()
 {
     FILE* filepointer1 ;
    printf("enter the name of the first file you want to merge\n");
    char name1[50];
    scanf("%s",name1);
    printf("enter the name of the second file you want to merge\n");
    char name2[50];
    scanf("%s",name2);
    FILE* fp1=fopen(name1,"r");
    if(fp1==NULL){
        printf("error opening the first file. \n");
        
    }else{
    char buffer1[250000];
    size_t bytesread =fread(buffer1,sizeof(char),sizeof(buffer1)-1,fp1);

    fclose(fp1);
    fp1=fopen(name2,"r");
    if (fp1==NULL)
    {
        printf("error opening the second file! \n");
        
    }else{
    
    char buffer2[250000];
    size_t bytesread2 =fread(buffer2,sizeof(char),sizeof(buffer2)-1,fp1);
    fclose(fp1);
    filepointer1=fopen("mergefile.txt","w");
    if (filepointer1==NULL)
    {
        printf("error opening the new file! \n");
        
    }else{
    
    fwrite(buffer1,sizeof(char),bytesread,filepointer1);
    fprintf(filepointer1,"\n\n");
    fseek(filepointer1,0,SEEK_END);
    fwrite(buffer2,sizeof(char),bytesread2,filepointer1);
    fclose(filepointer1);
    printf("merge done please check mergefile.txt for results ");
    
}}}}

// 8th function this code finds the number of the occurences of a given  word in a file whitch it prompts the user for the name of the file and
// the word to search for.
void findWordOccurrences(){
     char filename[100];
    char word[100];
    FILE *filepointer;
    char buffer[2500];
    int number_occurrences = 0;
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the word to search for \(this program is sensitive please write the word with the correct uper or lower case): ");
    scanf("%s", word);
    filepointer = fopen(filename, "r");
    if (filepointer == NULL) {
        printf("Error opening file.\n");
        
    }else{
    while (fgets(buffer, sizeof(buffer), filepointer)) {
        char *positoin = buffer;
        //strstr looks for the word in the file if it finds it returns a pointer to the start of the word 
        while ((positoin = strstr(positoin, word)) != NULL) {
            number_occurrences++;
            positoin++;  // Move past the last found word
        }
    }
    fclose(filepointer);
    printf("The word '%s' occurred %d times in the file '%s'.\n", word, number_occurrences, filename);
}}
//9th and last function this a code replayces every occurrences of a word with another one whitch it prompts the user for the name of the file, the
//word to search for, and the word to replace it with.
void replaceWordInFile(){
    char filename[100];
    char word[100];
    char replaceword[100];
    FILE *file;
    char buffer[2050];

    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the word to search for \(this program is sensitive please write the word with the correct uper or lower case): ");
    scanf("%s", word);
    printf("Enter the word you want to replace it with: ");
    scanf("%s", replaceword);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        
    }else{

    FILE *newfile = fopen("newfile.txt", "w");
    if (newfile == NULL) {
        printf("Error creating output file.\n");
        fclose(file);
    
    }else{
    while (fgets(buffer, sizeof(buffer), file)) {
        char* bufferpointer= buffer; 
        char* wordposistion;

        while ((wordposistion = strstr(bufferpointer, word)) != NULL) {
            fwrite(bufferpointer, sizeof(char), wordposistion-bufferpointer, newfile);
            fputs(replaceword, newfile);
            bufferpointer = wordposistion+ strlen(word);
        }
        fputs(bufferpointer, newfile);
    }
    fclose(file);
    fclose(newfile);
    printf("Replacement done. Please check 'newfile.txt' for results.\n");
}}}