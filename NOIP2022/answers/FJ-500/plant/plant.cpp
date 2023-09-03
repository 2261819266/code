#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1050;
const ll Mod=998244353;
int read(){
	int x=0,hhh=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') hhh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*hhh;
}
int n,m,c,f,a[N][N],hh[N][N],cc[N][N];
ll ansc,ansf;
char ch[N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),ID=read();
	while(T--)
	{
		n=read(),m=read(),c=read(),f=read(),ansc=ansf=0ll;
		for(int i=1;i<=n;++i){
			scanf("%s",ch);
			for(int j=0;j<m;++j)
				a[i][j+1]=ch[j]-'0';
		}
		for(int i=n;i;--i){
			int j=m; hh[i][j]=0,--j;
			for(;j;--j)
			{
				if(a[i][j]||a[i][j+1]) hh[i][j]=0;
				else hh[i][j]=hh[i][j+1]+1;
			}
		}
		for(int j=m;j;--j)
		{
			int i=n; cc[i][j]=0,--i;
			for(;i;--i)
			{
				if(a[i][j]||a[i+1][j]) cc[i][j]=0;
				else cc[i][j]=cc[i+1][j]+1;
			}
		}
		for(int j=1;j<m;++j){
			ll zong=0ll,az=0ll;
			for(int wc=0,i=1;i<=n;++i)
			{
				if(a[i][j])
				{
					zong=az=0ll;
					continue;
				}
				ansc=(zong*hh[i][j]%Mod+ansc)%Mod;
				if(wc!=i-1) ansc=(az*hh[i][j]%Mod+ansc)%Mod;	
				zong=(zong+az)%Mod;
				az=(ll)hh[i][j];
				if(hh[i][j]) wc=i;
			}
		}
		for(int j=1;j<m;++j)
		{
			ll zong=0ll,az=0ll,wdf=0ll;
			for(int wc=0,i=1;i<n;++i)
			{
				if(a[i][j]||a[i+1][j])
				{
					zong=az=0ll;
//					cout<<i<<" "<<j<<endl;
					continue;
				}
				wdf=zong*hh[i][j]%Mod;
				if(wc!=i-1) wdf=(az*hh[i][j]%Mod+wdf)%Mod;
				wdf=wdf*cc[i][j]%Mod;
				ansf=(wdf+ansf)%Mod;
				zong=(zong+az)%Mod;
				az=(ll)hh[i][j];
				if(hh[i][j]) wc=i;
//				cout<<i<<" "<<j<<cc[i][j]<<" "<<wdf<<endl;
			}
		}
		printf("%lld %lld\n",ansc*c%Mod,ansf*f%Mod);
	}
	return 0;
}
/*
2 0
16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111
6 6 1 1
000010
011000
000110
010000
011000
000000

*/
