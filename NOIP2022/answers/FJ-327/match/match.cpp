#include<bits/stdc++.h>
using namespace std;
typedef long long ull;
const int N=3005;
int T,n,q;
int a[N],b[N];
ull mxa[N][N],mxb[N][N],sum[N][N];
deque<int> zero;
void init()
{
	deque<int> q;
	for(int l=1;l<=n;l++)
	{
		q=zero;
		for(int i=1;i<=n;i++)
		{
			while(!q.empty()&&q.front()<=i-l) q.pop_front();
			while(!q.empty()&&a[q.back()]<=a[i]) q.pop_back();
			q.push_back(i);
			if(i>=l)
			{
				mxa[i-l+1][i]=a[q.front()];
			}
		}
		q=zero;
		for(int i=1;i<=n;i++)
		{
			while(!q.empty()&&q.front()<=i-l) q.pop_front();
			while(!q.empty()&&b[q.back()]<=b[i]) q.pop_back();
			q.push_back(i);
			if(i>=l)
			{
				mxb[i-l+1][i]=b[q.front()];
			}
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mxa[i][j]*mxb[i][j];
//		printf("mxa[%d][%d]=%lld,mxb[%d][%d]=%lld\n",i,j,mxa[i][j],i,j,mxb[i][j]);
	}
}
int main()
{
	freopen("match.in","r",stdin);//!!
	freopen("match.out","w",stdout);//!!
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	init();
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",sum[r][r]-sum[r][l-1]-sum[l-1][r]+sum[l-1][l-1]);
	}

	return 0;
}

