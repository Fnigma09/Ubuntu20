#include<stdio.h>
#include<math.h>

int prime(int x);

int nextprime(int x);

int main(void)
{
	int a[4][4]={{3,6,4,17},{8,5,9,10},{9,19,7,20},{4,14,21,23}},count=0,i,j,x;
	for(i=0;i<4;i++)
	{
		for(j=0;j<i+1;j++)
		   {
			   x=a[i][j];
			   if(prime(x))
			   {	a[i][j]=nextprime(x);
		            count++;
		       }
			   else
			        a[i][j]=0;
		   }
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
	printf("count=%d\n",count);
	return 0;
}

int prime(int x)
{
	int k;
	double t;
    t=sqrt(x*1.0);
	if(x<2)
		return 0;
	else
		for(k=2;k<=t;k++)
			if(x%k==0)
				return 0;
	return 1;

}

int nextprime(int x)
{
	if(x==2)
		return x=3;
	else
	{
	   do
	   {
		  x+=2;
	     }while(prime(x)==0);
	    return x;
	}
}
