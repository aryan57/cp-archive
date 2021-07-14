//https://codeforces.com/contest/1294/problem/B

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
typedef struct 
{
    int x,y;
} point;
 
 void swap(point *x, point *y)
{
point tmp = *x;
*x = *y;
*y = tmp;
}
 
 
int main() {
 
	
	int t,x,y,n,i,j,u,r,flag;
 
    
	scanf("%d",&t);
	
	while(t--)
	{
	   
	    scanf("%d",&n);
        point arr[n+1];
 
        for(i=1;i<n+1;i++)scanf("%d %d",&arr[i].x,&arr[i].y);
 
        arr[0].x=0;arr[0].y=0;
 
        for (i=n+1-1; i>1; i--)
        {
            flag = 0;
            for (j=1; j<i; j++)
            if (arr[j].x > arr[j+1].x || arr[j].y > arr[j+1].y)
            {
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
            if (flag == 0) break;
        }
 
 
        
        flag=0;
        for(i=1;i<n+1;i++)
        {
            r=arr[i].x-arr[i-1].x; u=arr[i].y-arr[i-1].y;
            if(r<0 || u<0){printf("NO\n");flag=1;break;}
        }
 
        if(flag)continue;
 
        
        printf("YES\n");
        for(i=1;i<n+1;i++)
        {
            r=arr[i].x-arr[i-1].x; u=arr[i].y-arr[i-1].y;
            
            while(r--)printf("R");
            while(u--)printf("U");
        }
 
        printf("\n");
            
        
    }
	
	return 0;
}