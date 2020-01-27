#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define MAX 100
void gotoxy(int x, int y);
int menu_select();
void adding();
int removing(); 
void test();
int main(){	
int x,y;
while(1){
x=menu_select();
switch(x){
case 1:
adding();	
break;
case 2:
y=removing();
if(y==1){
printf("done\npress any key to continue");
getch();
system("cls");	
}
else{
printf("Not found\npress anay key to continue");
getch();
system("cls");	
}
break;
case 3:
test();
break;
case 4:
printf("dictionary has been closed sucessfully");	
exit(1);
default:
printf("enter a correct number\n");
break;	
}	
}	
}
void gotoxy(int x, int y)                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int menu_select(){
gotoxy(0,2);
printf("Welcome to offline dictionary");
gotoxy(0,5);
printf("you can manage these dictionary by using this options:");	
gotoxy(29,8);	
printf("1)add a word");
gotoxy(29,10);
printf("2)remove a word");
gotoxy(29,12);
printf("3)Take a test");
gotoxy(29,14);
printf("4)exit\n");
gotoxy(0,16);
printf("Enter your command:\n");
char st[10];
gets(st);
return atoi(st);	
}
void adding(){
FILE *p=fopen("c:\\users\\Mirzakhah\\desktop\\dictionary.txt","a");	
printf("Enter a word:");
char st_1[MAX];
gets(st_1);
printf("Enter its synonym:");
char st_2[MAX];
gets(st_2);
fprintf(p,"%s\t%s\n",st_1,st_2);
printf("done\npress any key to continue");
getch();
system("cls");
fclose(p);	
}
int removing(){
printf("Enter your word:");
char st_1[MAX],st_2[MAX],ch;
int linecounter=1,temp=1,flag=1;
FILE *p=fopen("c:\\users\\Mirzakhah\\desktop\\dictionary.txt","r");
FILE *q=fopen("c:\\users\\Mirzakhah\\desktop\\temp.txt","w");		
if (!q) 
{
printf("Unable to open a temporary file to write\npress any key to continue");
getch();
system("cls");
exit(-1);
}
gets(st_1);
while(1){
fscanf(p,"%s",st_2);
if(strcmpi(st_1,st_2)==0)
break;
while(1){
ch=fgetc(p);
if(ch=='\n'||feof(p))
break;}
if(feof(p)){
fclose(p);
fclose(q);	
remove("c:\\users\\Mirzakhah\\desktop\\temp.txt");	
return 0;}	
linecounter++;}
rewind(p);
while(temp!=linecounter){
ch=fgetc(p);
fprintf(q,"%c",ch);
if(ch=='\n')
temp++;	
}
while((ch=fgetc(p))!='\n');
while(1){
ch=fgetc(p);
if(feof(p))
break;
fprintf(q,"%c",ch);	
}
fclose(p);fclose(q);
FILE*m=fopen("c:\\users\\Mirzakhah\\desktop\\dictionary.txt","w");
FILE*n=fopen("c:\\users\\Mirzakhah\\desktop\\temp.txt","r");
while(1){
ch=fgetc(n);
if(feof(n))
break;
fprintf(m,"%c",ch);}
fclose(m);
fclose(n);
remove("c:\\users\\Mirzakhah\\desktop\\temp.txt");
return 1;
}
void test(){
FILE *p=fopen("c:\\users\\Mirzakhah\\desktop\\dictionary.txt","r");	
int x,linecounter=0,i,random,temp=0;
float correct=0,wrong=0;
char st_1[MAX],st_2[MAX],ch;
printf("Enter the number of words that you want to test:");
scanf("%d",&x);
getchar();
while(1){
ch=fgetc(p);
if(feof(p))
break;
if(ch=='\n')
linecounter++;	
}
rewind(p);
srand(time(0));
printf("test has started\n");
for(i=0;i<x;i++){
random=rand()%linecounter+1;
rewind(p);
temp=0;
while(1){
ch=fgetc(p);
if(ch=='\n')
temp++;
if(temp==random-1){
if(temp==0)
fseek(p,-1,1);	
fscanf(p,"%s",st_1);
printf("Enter the synonym of %s:\n",st_1);
while(1){
ch=fgetc(p);
if(ch!=32)
break;	
}
fseek(p,-1,1);
fscanf(p,"%s",st_1);
gets(st_2);
if(strcmp(st_1,st_2)==0){
printf("Correct!\n");
correct++;
}
else{
printf("Wrong!\n");
printf("the correct answer is %s\n",st_1);
wrong++;	
}
break;
}}}
printf("you answered %.0f question correct and %.0f question wrong\nyour total score is %.2f\n",correct,wrong,correct-(wrong/4));
fclose(p);
printf("press any key to continue");
getch();
system("cls");
}
