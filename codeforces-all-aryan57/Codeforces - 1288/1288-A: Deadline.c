//https://codeforces.com/contest/1288/problem/A

#include <stdio.h>
#include <math.h>
 
int main()
{
    // FILE *fptr;
	// char filename[]="c.txt";
	// fptr = freopen (filename,"r",stdin);
    
    int t,flag;
    unsigned long long int n,d,x;
 
    scanf("%d",&t);
    
    while(t--)
    {
        flag=0;
        scanf("%llu %llu",&n,&d);
        if(d<=n) {printf("YES\n");continue;}
        else
        {
            for(x=1;x<n;x++)
            {
                
                if((unsigned long long int)ceil((1.0)*d/(x+1))<=n-x)
                {
                    printf("YES\n");
                    flag=1;
                    break;
                }
            }
            
            if(!flag)printf("NO\n");
            
            
        }
        
    }
    
    return 0;
}