#include<bits/stdc++.h>
using namespace std;
int read()
{
	int c=0;
	char ch=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9')
	{
		c=(c<<3)+(c<<1)+(ch-'0');
		ch=getchar();
	}
	return c;
}
const int N=1e3+8,Mod=998244353;
int T,id,n,m,C,F,pren=0,prem=0;
int totx[N][N],toty[N][N],mid;
char opt;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--)
	{
		n=read(),m=read(),C=read(),F=read();
		for(int i=1;i<=n;i++) totx[0][i]=totx[i][0]=toty[0][i]=toty[i][0]=0;
		for(int i=1;i<=m;i++) totx[0][i]=totx[i][0]=toty[0][i]=toty[i][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>opt;
				totx[i][j]=totx[i][j-1],toty[i][j]=toty[i-1][j];
				if(opt=='1') totx[i][j]++,toty[i][j]++;
			}
		}
		if(C==0 && F==0)
		{
			printf("0 0\n");
			continue;
		}
		int res=0,res1=0;
		for(int i=1;i<=n-2;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(totx[i][j+1]>totx[i][j-1] || toty[i+2][j]>toty[i-1][j]) continue;
				int l=j+1,r=m;
				while(l<r)
				{
					if(l+1==r)
					{
						if(totx[i][r]>totx[i][j]) r--;
						else l++;
						continue;
					}
					mid=(l+r)>>1;
					if(totx[i][mid]>totx[i][j]) r=mid-1;
					else l=mid;
				}
				for(int k=i+2;k<=n;k++)
				{
					if(toty[k][j]>toty[i][j]) break;
					if(totx[k][j+1]>totx[k][j]) continue;
					int l1=j+1,r1=m;
					while(l1<r1)
					{
						if(l1+1==r1)
						{
							if(totx[k][r1]>totx[k][j]) r1--;
							else l1++;
							continue;
						}
						mid=(l1+r1)>>1;
						if(totx[k][mid]>totx[k][j]) r1=mid-1;
						else l1=mid;
					}
					res=(res+(r-j)*(r1-j))%Mod;
					if(F==0) continue;
					int l2=k,r2=n;
					while(l2<r2)
					{
						if(l2+1==r2)
						{
							if(toty[r2][j]>toty[k][j]) r2--;
							else l2++;
							continue;
						}
						mid=(l2+r2)>>1;
						if(toty[mid][j]>toty[k][j]) r2=mid-1;
						else l2=mid;
					}
					res1=(res1+(r-j)*(r1-j)*(r2-k))%Mod;
				}
			}
		}
		res=(res*C)%Mod;
		res1=(res1*F)%Mod;
		if(res<0) res+=Mod;
		if(res1<0) res1+=Mod;
		printf("%d %d\n",res,res1);
	}
	return 0;
}
