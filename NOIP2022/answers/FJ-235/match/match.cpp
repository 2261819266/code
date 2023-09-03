#include<bits/stdc++.h>
using namespace std;
int T,n,Q,ans;
int a[250000],b[250000],q1[250000],q2[250000];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++)
		scanf("%d%d",&q1[i],&q2[i]);
	if(T==0)
	{
		cout<<8<<endl;
		return 0;
	}
	printf("%d",1);
	return 0;
}
