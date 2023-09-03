#include<iostream>
#include<cstdio>
int n,m;
unsigned long long int a[10000]={},b[10000]={};
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	scanf("%d %d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&m);
	int l,r;
	unsigned long long int A,B,ans=0;
	while(m--)
	{
		scanf("%d %d",&l,&r);
		ans=0;
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)
			{
				A=B=0;
				for(int i=p;i<=q;i++)
				{
					A=std::max(A,a[i]);
					B=std::max(B,b[i]);
				}
				ans+=A*B;
			}
		}
		std::cout<<ans<<"\n";
	}
}
