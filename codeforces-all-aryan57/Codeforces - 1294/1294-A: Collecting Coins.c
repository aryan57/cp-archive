//https://codeforces.com/contest/1294/problem/A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define s(n)                        scanf("%lld",&n)
#define p(n)                        printf("%lld",n)
#define s2(a,b)                     scanf("%lld %lld",&a,&b)
#define s3(a,b,c)                   scanf("%lld %lld %lld",&a,&b,&c)
 
#define rep(i,a,b)               for(ll i=a;i<b;i++)
 
#define pfy                      printf("YES")
#define pfn                      printf("NO")
#define nl                       printf("\n")
 
typedef long long int ll;
typedef long double ld;
 

#define int ll
#define prime_m 1e9+7

int main() 
{
// FILE *fptr;fptr=freopen("c.txt","r",stdin);

ll t,a,b,c,n;
s(t);

while (t--)
{
    s3(a,b,c);s(n);
    if((a+b+c+n)%3==0 && ((a+b+c+n)/3)>=a && ((a+b+c+n)/3)>=b && ((a+b+c+n)/3)>=c){pfy;nl;}
	else {pfn;nl;}
}
	
return 0;
}