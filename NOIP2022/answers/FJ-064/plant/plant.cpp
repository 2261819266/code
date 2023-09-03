#include<bits/stdc++.h>

#define rep(i,j,k) for(int i=j;i<=k;i++)
#define drp(i,j,k) for(int i=j;i>=k;i--)

using namespace std;
const int N=1010,mod=998244353;
int n,m,h[N][N],l[N][N],T,id;
long long ansc,ansf,C,F;
char s[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		ansf=0,ansc=0;
		scanf("%d%d%lld%lld",&n,&m,&C,&F);
		if(C==0&&F==0) 
		{
			printf("0 0\n");
			continue;
		}
		rep(i,1,n)	scanf("%s",s[i]+1);
		rep(i,1,n)
		{
			int x=m+1;
			while(x>0) 
			{
				if(s[i][x]=='1'||x==m+1)
				{
					int cnt=1;
					while(x>=1&&s[i][x-1]=='0') x--,h[i][x]=cnt,cnt++;
				}
				x--;
			}
		}
			
		rep(i,1,m)
		{
			int y=n+1;
			while(y>0) 
			{
				if(s[y][i]=='1'||y==n+1)
				{
					int cnt=1;
					while(y>=1&&s[y-1][i]=='0') y--,l[y][i]=cnt,cnt++;
				}
				y--;
			}
		}
		rep(i,1,n)
			rep(j,1,m)
			if(s[i][j]=='0'&&h[i][j]>1&&l[i][j]>=3)
			{
				long long e=0;
				for(int k=i+2;k<=n;k++) 
				{
					if(s[k][j]!='1'&&h[k][j]>1)
					{
					e=((h[i][j]-1)*(h[k][j]-1))%mod;
					if(k+1<=n) ansf=(ansf+(l[k+1][j]*e))%mod; 
					ansc=(ansc+e)%mod;
					}
					if(s[k][j]=='1') break; 
				}
				
			}
		printf("%lld %lld\n",(ansc*C)%mod,(ansf*F)%mod);
	}
	
	
	
	return 0;
} 
