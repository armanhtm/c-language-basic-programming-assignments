#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define MAX 100
struct address{
char street[15],city[15],state[10],name[10];	
unsigned long int zip;}info[MAX];
void gotoxy(int x, int y)                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void intialize(){
int i;	
for(i=0;i<MAX;i++)
info[i].name[0]='\0';	
}
int menu_select(){	
gotoxy(29,8);	
printf("1.enter new name");
gotoxy(29,10);
printf("2.delete a name");
gotoxy(29,12);
printf("3.show list");
gotoxy(29,14);
printf("4.exit\n");
char st[10];
gets(st);
return atoi(st);	
}
int find_free(){
int i;
for(i=0;i<MAX;i++)
if(info[i].name[0]=='\0')
return i;
return -1;	
}
void enter(){
int x=find_free();
if(x==-1)
printf("list is full\n");
else{	
gets(info[x].name);
gets(info[x].street);
gets(info[x].city);
gets(info[x].state);
char temp[30];
gets(temp);
info[x].zip=strtoul(temp,'\0',10);}}
void deleting(){
printf("enter the passenger number\n");
int x;	
scanf("%d",&x);
info[x-1].name[0]='\0';	
}
void show_list(){
int i;
for(i=0;info[i].name[0];i++)
printf("%c\t%c\t%c\t%c\t%d\n",info[i].name,info[i].street,info[i].city,info[i].state,info[i].zip);	
}
int main(){
int x;	
intialize();
while(1){
x=menu_select();
switch(x){
case 1:
enter();
break;
case 2:
deleting();
break;
case 3:
show_list();
break;
case 4:
return 0;
default:
printf("enter a correct number\n");
break;	
}	
}
return 0;	
}
