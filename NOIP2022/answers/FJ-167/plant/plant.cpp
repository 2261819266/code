#include<bits/stdc++.h>
//#define int long long
#define rint register int
#define f(X,Y,Z) for(int X=Y;X<=Z;++X)
using namespace std;
const int maxn=1e3+2,mod=998244353;
int T,id,n,m,c,f;
string a[maxn];
int dtu1[maxn][maxn],last1,sumy[maxn][maxn];
int st_,nd_;
int ansc,ansf;
inline void In()
{
	cin>>n>>m>>c>>f;
	f(i,1,n)
	{
//		scanf("%c",&a[i]);
		cin>>a[i];
	}
}
inline void Work()
{
	f(j,1,m)
	{
		last1=n+1;
		for(int i=n;i>=1;--i)
		{
			if(a[i][j-1]-'0')
			{
				last1=i;
			}else
			{
				dtu1[i][j]=last1-i;
			}
		}
//		f(i,1,n) sumy[i][j]=sumy[i-1][j]+(int)(a[i-1][j-1]-'0');
	}
	/*
	f(i,1,n)
	{
		f(j,1,m)
		{
			cout<<dtu1[i][j]<<" ";
		}
		cout<<endl;
	}
	//*/
	f(i,1,n)
	{
		f(j,1,m)
		{
			if(dtu1[i][j]>=3)
			{
				st_=0;
				f(l,j+1,m)
				{
					if(a[i][l-1]-'0') break;
					++st_;
				}
				if(!st_) continue;
				f(k,2,dtu1[i][j]-1)
				{
					nd_=0;
					f(l,j+1,m)
					{
						if(a[i+k][l-1]-'0') break;
						++nd_;
					}
					rint t=st_*nd_%mod;
					ansc=(ansc+t)%mod;
					t=t*(dtu1[i][j]-(k+1))%mod;
					ansf=(ansf+t)%mod;
				}
			}
		}
	}
}
inline void Out()
{
//	printf("%d %d\n",ansc,ansf);
	cout<<c*ansc%mod<<" "<<f*ansf%mod<<"\n";
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T>>id;
	while(T--)
	{
		In();
		Work();
		Out();
	}
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
