#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
int n,m,c,f;
int t,id;
char mapp[1010][1010];
int cnt[1010][1010];
int x[1010][1010];
int ar1iv[1010][1010];
inline int rea()
{
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void wr(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=rea(),id=rea();
	while(t--)
	{
		long long ans=0,ans_f=0;
		n=rea();m=rea();c=rea();f=rea();
		memset(cnt,0,sizeof(cnt));
		memset(x,0,sizeof(x));
		memset(ar1iv,0,sizeof(ar1iv));
		for(int i=1;i<=1000;i++)
		{
			for(int j=1;j<=1000;j++) mapp[i][j]='1';
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) cin>>mapp[i][j];
		}
		if(c==0&&f==0) 
		{
			wr(0),putchar(' '),wr(0),putchar('\n');
			continue;	
		}
		for(int j=1;j<m;j++)
		{
			int p=1;
			while(p<n&&mapp[p][j]!='1') p++;
			for(int i=1;i<=n;i++) 
			{
				ar1iv[i][j]=p-i;
				if(i==p) 
				{
					p++;
					while(p<n&&mapp[p][j]=='0') p++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			int last_j=0,j=1;
			while(j<=m)
			{
				if(mapp[i][j]=='1') 
				{
					for(;last_j<j;last_j++) cnt[i][last_j]=j-last_j;
					last_j=j+1;	
				}
				j++;	
			}
			for(;last_j<j;last_j++) cnt[i][last_j]=j-last_j;
		}	
		for(int j=1;j<=m;j++)
		{
			for(int i=n;i>=1;i--)
			{
				x[i][j]=x[i+1][j]+(cnt[i][j]>1?(cnt[i][j]-1):0);
			}
		}
		for(int j=1;j<m;j++)
		{
			for(int i=1;i<n-1;i++) 
			{
				if(ar1iv[i][j]>1)
				ans=(ans+(long long)(cnt[i][j]>1?cnt[i][j]-1:0)*(long long)((long long)x[i+2][j]-(long long)x[i+ar1iv[i][j]+1][j])%p)%p;	
			}
		}
		if(f!=0)
		{
			memset(x,0,sizeof(x));
			for(int j=1;j<=m;j++)
			{
				for(int i=n;i>=1;i--)
				{
					x[i][j]=x[i+1][j]+(ar1iv[i][j])*(cnt[i][j]>1?(cnt[i][j]-1):0);
				}
			}
			for(int j=1;j<m;j++)
			{
				for(int i=1;i<n-2;i++)
				{
					if(ar1iv[i][j]>2&&cnt[i][j]>1) ans_f=(ans_f+(long long)(cnt[i][j]-1)*(long long)((long long)x[i+2][j]-(long long)x[i+ar1iv[i][j]][j])%p)%p;	//(long long)((long long)(ar1iv[i][j]-2)*(x[i+2][j])%p-(long long)(db_x[i+3][j]-db_x[i+ar1iv[i][j]+1][j])%p)%p)
				}	
			}
		}
		wr(ans*c),putchar(' '),wr(ans_f*f),putchar('\n');
	}
 	return 0;
}
