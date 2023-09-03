#include<bits/stdc++.h>
using namespace std;
int t,n;
long long a[250010],b[250010];
int Q;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	scanf("%d",&Q);
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		unsigned long long ans=0;
		for(int p=l;p<=r;p++)
		{
			unsigned long long maxx1=0,maxx2=0;
			for(int q=p;q<=r;q++) 
			{
				if(a[q]>maxx1) maxx1=a[q];
				if(b[q]>maxx2) maxx2=b[q];
				//cout<<a[p]<<' '<<b[p]<<endl;
				ans+=(unsigned long long)maxx1*(unsigned long long)maxx2;
			}
		}
		printf("%llu\n",ans);
	}
 	return 0;
}
