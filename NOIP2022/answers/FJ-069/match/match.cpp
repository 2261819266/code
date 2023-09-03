#include<bits/stdc++.h>
#define ll long long
const ll MOD=4294967296;
using namespace std;
int Q,T,n,a[250010],b[250010],l[250010],r[250010],ma[3010][3010],mb[3010][3010];
ll sum;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
//	printf("%lld",MOD);
	scanf("%d %d",&T,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ma[i][i]=a[i];
		for(int j=i;j>=1;j--)
		{
			ma[j][i]=max(max(a[i],ma[j][i-1]),max(a[j],ma[j+1][i]));
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		for(int j=i;j>=1;j--)
		{
			mb[j][i]=max(max(b[i],mb[j][i-1]),max(b[j],mb[j+1][i]));
		}
	}
	scanf("%d",&Q);
	while(Q--)
	{
//		cout<<1;
		int L,R;
		sum=0;
		cin>>L>>R;
		for(int i=L;i<=R;i++)
		{
			for(int j=i;j<=R;j++)
			{
				sum+=((ma[i][j]*mb[i][j])%MOD);
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

