#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
struct cellphone{
double nationalID,cellphoneID;
int registrationfee;
char cellphonebrand[20];	
};
int main(){
srand(time(0));
const char brandarray[4][20]={"apple","samsung","htc","huawei"};
const int feearray[4]={1000,900,800,700};
int n,i,j;
printf("how many phones do you want to register?:");
scanf("%d",&n);
struct cellphone cellphones[n];
char brand[10];
for(i=0;i<n;i++){
cellphones[i].cellphoneID=fabs(rand());
printf("enter national id and brand\n");
scanf("%lf %s",&cellphones[i].nationalID,cellphones[i].cellphonebrand);
for(j=0;j<4;j++){
if(!(strcmp(cellphones[i].cellphonebrand,brandarray[j]))){
cellphones[i].registrationfee=feearray[j];
}}}
for(i=0;i<n;i++)
printf("%d: registration fee %.lf: cellphone id\n",cellphones[i].registrationfee,cellphones[i].cellphoneID);
return 0;
}
