#include<bits/stdc++.h>
using namespace std;
unsigned long long l,r,n,T,a[2500005],b[2500005],maxx1,maxx2,ans,Q;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		{
			for(int z=j;z<=r;z++)
			{
				if(maxx1<a[z]) maxx1=a[z];
				if(maxx2<b[z]) maxx2=b[z];
			}
			ans+=maxx1*maxx2;
			maxx1=0;
			maxx2=0;
			for(int z=r;z>=j+1;z--)
			{
				if(maxx1<a[z]) maxx1=a[z];
				if(maxx2<b[z]) maxx2=b[z];
			}
			ans+=maxx1*maxx2;
			maxx1=0;
			maxx2=0;
		}
	}
	cout<<ans;
	return 0;
}
