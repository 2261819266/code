#include<bits/stdc++.h>
using namespace std;
int T,n,a[250050],b[250050],q,l,r,maxn1,maxn2;
unsigned long long x,tt;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&l,&r);
		tt=0;
		for(int j=l;j<=r;j++)
		{
			maxn1=a[j];
			maxn2=b[j];
			for(int k=j;k<=r;k++)
			{
				maxn1=max(maxn1,a[k]);
				maxn2=max(maxn2,b[k]);
				x=maxn1*maxn2;
				if(18446744073709551610-tt<x-6)
				{
					tt=x-18446744073709551610+tt-6;
				}
				else
				{
					tt=tt+x;
				}
			}
		}
		cout<<tt<<endl;
	}
	return 0;
}
