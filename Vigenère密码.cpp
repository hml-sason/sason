#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#define MAXA 10005
using namespace std;
char k[MAXA],m[MAXA];
int j,klen,mlen;
int main() {

gets(k);	
gets(m);	
klen = strlen(k);	
mlen = strlen(m);		
for(int i=0;i<klen;i++)	    
if(isupper(k[i]))	    	
k[i] = tolower(k[i]);		
for(int i=0;i<mlen;i++) {		
if(islower(m[i])) {			
m[i] = char(m[i] - (k[j++] - 'a'));			
if(m[i] < 'a')			   
m[i] = char(m[i] + 26);		
}		
else {			
m[i] = char(m[i] - (k[j++] - 'a'));			
if(m[i] < 'A')			   
m[i] = char(m[i] + 26);		
}		
if(j >= klen)		   
j = 0;	
}		
printf("%s",m);
}
