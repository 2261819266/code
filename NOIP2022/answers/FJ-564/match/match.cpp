//小菜狗的记忆化模拟(doge： 
#include<bits/stdc++.h>
#define maxn 250005
using namespace std;
int t,n,l,r,q1,a[maxn],b[maxn],maxa,maxb;
long long MOD,ans,sum,f[maxn][maxn];
int match(int l,int r)
{
	for(int p=l;p<=r;p++)
	{	
		maxa=-114514;
		maxb=-114514;
		sum=0;
		for(int q=p;q<=r;q++)
		{	
			if(f[p][q]!=-1) sum=f[p][q];
			else
			{
				if(maxa<a[q]) maxa=a[q];
				if(maxb<b[q]) maxb=b[q];
				sum+=(maxa*maxb)%MOD;
				f[p][q]=sum;
			}
		}
		ans+=sum;
		ans%=MOD;
	}
	return 0;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>t>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	cin>>q1;
	MOD=1;
	for(int i=1;i<=64;i++) MOD*=2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=-1;
	for(int i=1;i<=q1;i++)
	{
		cin>>l>>r;
		if(f[l][r]!=-1) cout<<f[l][r];
		else
		{
			ans=0;
			match(l,r);
			f[l][r]=ans;
			cout<<ans<<endl;
		}
	}
	return 0;
}
//555嘉然你让我AC罢嘉然555
