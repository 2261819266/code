#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000000,p=1e9+7;
int a[N],ans;
int read()
{
	int res=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}
signed main()
{
	int n;
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();
	int s1=0,s2=1;
	for(int i=1;i<=n;i++)
	{
		int x=s1+s2;
		s1+=x,s2*=2;
		s1%=p;s2%=p;
		a[i]=x;
	}
	int s=1;
	for(int i=n;i>=1;i--)ans+=a[i]*s,s=s*2%p,ans%=p;
	cout<<ans<<endl;
}

