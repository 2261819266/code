#include<bits/stdc++.h>
using namespace std;
ifstream fin("plant.in",ios::in);
ofstream fout("plant.out",ios::out);
#define int long long 
#define rep(i,l,r) for(int i=l;i<=r;i++) 
#define drp(i,r,l) for(int i=r;i>=l;i--) 
#define MAXNM  1100
#define MOD 998244353
inline int read()
{
	int x=0,f=1;char c=fin.get();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=fin.get();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=fin.get();}
	return x*f;
}
inline bool read_b()
{
	char c=fin.get();
	while(c<'0'||c>'9'){c=fin.get();}
	while(c>='0'&&c<='9'){return (bool)(c-'0');}
}
using namespace std;
int T,id,n,m;bool c,f;
int num_c;
int num_f;
bool a[MAXNM][MAXNM];
int num[MAXNM][MAXNM];//
int num_y[MAXNM][MAXNM];//
int sum[MAXNM][MAXNM];//
int sum_num[MAXNM][MAXNM];
void initi_num()
{
	rep(i,1,n)
	{
		int ct=0;
		drp(j,m,1)
		{
			if(a[i][j]==1)
			{
				num[i][j]=0;ct=0;
			}
			else
			{
			
			num[i][j]=ct;
			ct++;
			}
		}
	}
	rep(j,1,m)
	{
		int ct=0;
		drp(i,n,1)
		{
			if(a[i][j]==1)
			{
				num_y[i][j]=0;ct=0;
			}
			else
			{
			
			num_y[i][j]=ct;
			ct++;
			}
		}
	}
	
}
void initi_sum()//n^2
{
	memset(sum_num[0],0,sizeof(sum_num[0]));
	rep(j,1,m)
	{
		
		int ct=0;
		rep(i,1,n)
		{
			if(a[i][j]==1)
			{
				ct++;
			}
			sum[i][j]=ct;
			sum_num[i][j]=sum_num[i-1][j]+num[i][j];
		}
	
	}
	
	
}
void count_0() //n^3
{
	num_c=0;num_f=0;
	rep(j,1,m-1){
	
	rep(x2,3,n)
		{
			rep(x1,1,x2-2)
			{
				if(sum[x1][j]==sum[x2][j])
				{
						if(c!=0)num_c=(num_c+num[x1][j]*num[x2][j])%MOD;
						if(f!=0)num_f=(num_f+num[x1][j]*num[x2][j]*num_y[x2][j])%MOD;
					}
				
			}
		}
//		cout<<num_c<<'	';
		
	}
		
}
//sum_j[j] ==n-sum[n][j]
int g[MAXNM];
void count_1()//n^2
{
//	cout<<'\n';
	g[m]=0;
	drp(j,m-1,1)
	{
		g[j]=g[j+1]+(n-sum[n][j])*sum_num[n][j];
//		cout<<j<<'*'<<n-sum[n][j]<<' '<<sum_num[n][j+1]<<'\n';
		rep(i,1,n)
		{
			g[j]-=(1-a[i][j])*num[i][j];
			g[j]-=(1-a[i][j])*num[i-1][j];
			g[j]-=(1-a[i][j])*num[i+1][j];
		}
//		cout<<g[j]<<'\n';
	}
} 
signed main() 
{
	T=read();
	id=read();
	while(T--)
	{
		n=read();m=read();c=read();f=read();
		
		rep(i,1,n)
		{
			rep(j,1,m)
			{
				a[i][j]=read_b();
//				cout<<a[i][j];
			}
		}
		initi_num();
		initi_sum();
		count_0();
//		count_1();
		
		fout<<(num_c*c)%MOD<<' '<<(num_f*f)%MOD<<'\n'; 
		
	}
		rep(i,1,n){
		
//		 rep(j,1,m)cout<<num[i][j]<<" ";
//		 cout<<'\n';
	}
}
