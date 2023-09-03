#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;
int id,n,m,q;
ull a[250005],b[250005],ans;
int main ()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&id,&n);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		ans=0;
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++)
			{
				ull maxa=0,maxb=0;
				for(int k=i;k<=j;k++) maxa=max(maxa,a[k]),maxb=max(maxb,b[k]);
				ans+=maxa*maxb;
			}
		cout<<ans<<endl;
	}
}
