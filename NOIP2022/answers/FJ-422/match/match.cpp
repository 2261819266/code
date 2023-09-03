#include<iostream>
#include<stdio.h>
using namespace std;
int T,n,Q,a[250005],b[250005],l,r;
unsigned long long ans;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++)
	    cin>>b[i];
	cin>>Q;
	while(Q--)
	{
		cin>>l>>r;
		ans=0;
		for(int p=l;p<=r;p++)
		{
			for(int q=p;q<=r;q++)
			{
				int maxa=0,maxb=0;
				for(int i=p;i<=q;i++)
				{
				    maxa=max(maxa,a[i]);
				    maxb=max(maxb,b[i]);
				}
				ans+=maxa*maxb;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
