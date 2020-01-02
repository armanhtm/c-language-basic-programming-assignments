#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
char s_1[21];
char s[21]="A1$B2C";
while(1){
gets(s_1);
if(strcmp(s_1,s))
printf("try again:");	
else
break;	
}
printf("enter your new password:");
char s_2[21],s_3[21];
int i,j,k,flag=0,p=0;
while(1){	
gets(s_2);
if(strlen(s_2)>=6)
for(i=0;s_2[i];i++)
if(s_2[i]=='@'||s_2[i]=='#'||s_2[i]=='$'||s_2[i]=='%')
for(j=0;s_2[j];j++)
if(isalpha(s_2[j]))
if(strlen(itoa(atoi(s_2),s_3,10))>0)
flag=1;
if(flag==1)
break;
printf("invalid password\n%d",p);
}
printf("enter your new password again\n");
gets(s);
if(!(strcmp(s_2,s))){
printf("your pass word changed");
s_1[0]='\0';
s_2[0]='\0';
s_3[0]='\0';}
else
printf("your pass word didnot change");
return 0;}


