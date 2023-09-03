#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,t,id,c,f,c1,f1,cntc,cntc1,cntf,cntf1,cntf2;
char a[1005][1005];
int bp(int x,int y)
{
	int cnt=0;
	if(a[x][y]=='1') return -1;
	for(int i=y+1;i<=m;i++)
		if(a[x][i]=='0')	cnt++;
		else break;
	return cnt;
}
bool check(int x,int y,int r,int c)
{
	for(int i=x;i<=r;i++)
		if(a[i][y]=='1')	return false;
	return true;
}
int bp1(int x,int y)
{
	int cnt=0;
	if(a[x][y]=='1') return -1;
	for(int i=x+1;i<=n;i++)
		if(a[i][y]=='0')	cnt++;
		else break;
	return cnt;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)	
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<n;i++)
			for(int j=i+2;j<=n;j++)
				for(int k=1;k<=m;k++)
				{
					cntf=bp(i,k),cntf1=bp(j,k),cntf2=bp1(i,k)-(j-i);
					if(cntf<1||cntf1<1)	continue;
					if(check(i,k,j,k))	
						c1=(c1+cntf*cntf1)%mod;
					if(cntf2<1)continue;
					f1=(f1+cntf*cntf1*cntf2)%mod;
				}
		cout<<(c1*c)%mod<<" "<<(f1*f)%mod<<" ";
	}
	return 0;	
}
