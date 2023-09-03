#include<bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define GC c=getchar()
#define IG isdigit(c)
using namespace std;
const int N=1e3+5;
template <class T=int>T qread(T x=0,char GC,bool f=1)
{
	for(;!IG;GC) f=c!='-';
	for(;IG;GC) x=x*10+(c^48);
	return f?x:-x;
}
char b[N];
bool a[N][N];
int n,m,k,T,id;
int moc,mof;
long long numc=0,numf=0;
int is=2,ao=1,bo=1,sec=2;
void findd(int nx,int ny)
{
	if(a[nx+1][ny]==0&&a[nx][ny]==0)
	{
		is=2;
		while(a[nx+is][ny]==0) is++;
		sec=is-1,is=2;
		while(a[nx+is][ny]==0)
		{
			ao=1,bo=1;
			while(a[nx][ny+ao]==0) ao++;
			while(a[nx+is][ny+bo]==0) bo++;
			numc+=(ao-1)*(bo-1);
			numf+=(ao-1)*(bo-1)*(sec-is);
			is++;
		}
	}
	return ;
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=qread(),id=qread();
	while(T--)
	{
		memset(a,1,sizeof(a));
		if(id==1) 
		{
			cout<<0<<" "<<0<<endl;
			continue; 
		}
		n=qread(),m=qread(),moc=qread(),mof=qread();
		f(i,1,n,1)
		{
			cin>>b;
			f(j,0,m-1,1) 
			{ 
				if(b[j]=='0') a[i][j+1]=0;
				else a[i][j+1]=1;
			}
		}
		f(i,1,n-2,1)
		{
			f(j,1,m-1,1)
			{
				findd(i,j);
			}
			numc%=998244353;
			numf%=998244353;
		}
		if(moc==0) cout<<0<<" ";
		else cout<<numc<<" ";
		
		if(mof==0) cout<<0<<endl;
		else cout<<numf<<endl;	
	}
	return 0;
}
