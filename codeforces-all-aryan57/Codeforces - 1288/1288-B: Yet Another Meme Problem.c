//https://codeforces.com/contest/1288/problem/B

#include <stdio.h>

int main()
{
//     FILE *fptr;
// 	char filename[]="c.txt";
// 	fptr = freopen (filename,"r",stdin);
    int t;
    unsigned long long int a,b,helper,count;
    unsigned long long int ans;

    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%llu %llu",&a,&b);

        count=0;

        for(helper=9;helper<=b;helper=helper*10+9,count++){}

        ans=a*count;
        printf("%llu\n",ans);
        
    }
    
    return 0;
}
