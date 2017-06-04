// Stack top to bottom is array from the last (from index n-1 to 0)
#include <iostream>
#include<vector>
using namespace std;

int main() 
{
    
    int n,i,q,j;
    
    printf("Enter the no. of curtain cloth pieces: ");
    scanf("%d",&n);
    
	vector<int> a(n) ;
	vector<int> b(n) ;
	vector<int> c(n) ;
	vector<int> d(n) ;
	
	printf("Enter the lengths: ");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	    b[i]=a[i];
	    c[i]=a[i];
	    d[i]=a[i];
	}
	
	
	printf("Enter the number of queries: ");
	scanf("%d",&q);
	
	int m;
	int max=a[n-1];
	int min,min2;
	int count=1,count1=1;
			
   for(j=0;j<q;j++)
   {
   	 printf("Enter query %d: ",j+1);
	 scanf("%d",&m);
	 
	 for(i=0;i<n;i++)
	 {
	 	a[i]=b[i]=c[i]=d[i];
	 }
	 
	 min=min2=m;
	 
	for(i=n-1;i>=0;i--)
	{
	    if(a[i]>=m && count==1)
	    {
	        a[i]-=m;
	        count=0;
	    }
	    
	    if(c[i]==m && count1==1)
	    {
	       b[i]-=m;
	       count1=0;
	    }
	    
	    
	    if(c[i]>max && j==0)
	    {
	        max=c[i];
	    }
	    
	    if(c[i]>min)
	    {
	    	min2=min;
	    	min=c[i];
		}
		else if(c[i]<=min && c[i]>min2)
		min=c[i];
	    
	    
	    
	}
	
	
	if(count1==1)
	for(i=n-1;i>=0;i--)
	{
	
	        if(b[i]==min)
	       {
			 b[i]-=m;
	        break;
	       }
	    
	}
	
	for(i=n-1;i>=0;i--)
	{
	    if(c[i]==max)
	    {
	        c[i]-=m;
	        break;
	    }
	}

	
	if(m<=max)
	for(i=0;i<n;i++)
	printf("%d ",a[i]);

	else 
	printf("Unavailable");
	
	cout<<"\n";
	
	if(m<=max)
	for(i=0;i<n;i++)
	printf("%d ",b[i]);
	
	else
	printf("Unavailable");
	
	cout<<"\n";
	
	if(m<=max)
	for(i=0;i<n;i++)
	printf("%d ",c[i]);

    else
	printf("Unavailable");	
	cout<<"\n\n";
	
   }
   
   
	return 0;
}

