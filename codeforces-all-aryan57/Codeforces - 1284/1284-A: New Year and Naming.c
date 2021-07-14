//https://codeforces.com/contest/1284/problem/A

#include <stdio.h>
#include <stdlib.h> //for dynamic allocation
#include <string.h>

int main () {

int n,m,q,*y,j,k,i;
char s[20][11],t[20][11];

scanf("%d %d",&n,&m);

// s=(char**)malloc(n*sizeof(char*));
// for(i=0;i<n;i++)s[i]=(char*)malloc(10*sizeof(char));

// t=(char**)malloc(m*sizeof(char*));
// for(i=0;i<m;i++)t[i]=(char*)malloc(10*sizeof(char));

for(i=0;i<n;i++)scanf("%s",&s[i]);
for(i=0;i<m;i++)scanf("%s",&t[i]);

scanf("%d",&q);
y=(int*)malloc(q*sizeof(int));
for(i=0;i<q;i++)scanf("%d",&y[i]);

for(i=0;i<q;i++){

    j=y[i]%n-1;
    if(j<0)j=n-1;

    k=y[i]%m-1;
    if(k<0)k=m-1;
    printf("%s%s",s[j],t[k]);
    if(i<q-1)printf("\n");
}

return 0;
}