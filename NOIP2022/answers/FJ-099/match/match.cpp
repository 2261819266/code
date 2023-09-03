#include <cstdio>
#include <iostream>
using namespace std;

int T,n,q;
int a[256000],b[256000];
int l,r;
int ma,mb;
unsigned long long t[3333][3333];
unsigned long long ans;

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for (int i=1; i<=n; i++)
		scanf("%d",a+i);
	for (int i=1; i<=n; i++)
		scanf("%d",b+i);
	for (int p=1; p<=n; p++)
	{
		ma=mb=0;
		for (int q=p; q<=n; q++)
		{
			ma=max(ma,a[q]);
			mb=max(mb,b[q]);
			t[p][q]=t[p][q-1]+ma*mb;
		}
	}
	scanf("%d",&q);
	while (q--)
	{
		ans=0;
		scanf("%d%d",&l,&r);
		for (int p=l; p<=r; p++)
		{
			ans+=t[p][r];
		}
		cout<<ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
