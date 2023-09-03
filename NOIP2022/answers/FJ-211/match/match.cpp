#include<bits/stdc++.h>
using namespace std;
const int maxn=	250005;
int a[maxn];
int b[maxn];
long long pow1(int a,int b)
{
	long long cnt=1;
	for(int i=1;i<=b;i++)
	{
		cnt=cnt*a;
	}
	return cnt;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	cin>>T>>n;
	long long mod=pow1(2,62);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		long long sum=0;
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		{
			for(int k=j;k<=r;k++)
			{
				int maxa=0;
				int maxb=0;
				for(int p=j;p<=k;p++)
				{
					if(a[p]>maxa)
					{
						maxa=a[p];
					}
					if(b[p]>maxb)
					{
						maxb=b[p];
					}
				}
				sum=sum+(maxa*maxb)%mod;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
