#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+15;
int T,n,a[MAXN],b[MAXN],Q,l,r;
int maxa,maxb;
unsigned long long ans;
int st[MAXN][35][2],lg[MAXN],bz[35];
inline void work_st()
{
	bz[0]=1;
	lg[0]=-1;
	for(int i=1;i<=30;++i) bz[i]=bz[i-1]*2;
	for(int i=1;i<=n;++i)
	{
		lg[i]=lg[i>>1]+1;
		st[i][0][0]=a[i];
		st[i][0][1]=b[i];
	}
	for(int j=1;j<=lg[n];++j)
	{
		for(int i=1;i+bz[j]-1<=n;++i)
		{
			st[i][j][0]=max(st[i][j-1][0],st[i+bz[j-1]][j-1][0]);
			st[i][j][1]=max(st[i][j-1][1],st[i+bz[j-1]][j-1][1]);
		}
	}
}
int query(int totp,int l,int r)
{
	int nlen=lg[r-l+1];
	return max(st[l][nlen][totp],st[r-bz[nlen]+1][nlen][totp]);
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i) cin>>b[i];
	cin>>Q;
	work_st();
	if(T==1||T==2||T==0)
	{
		while(Q--)
		{
			cin>>l>>r;
			ans=0;
			for(int p=l;p<=r;++p)
			{
				for(int q=l;q<=r;++q)
				{
					maxa=0;
					maxb=0;
					for(int pip=p;pip<=q;++pip)
					{
						maxa=max(maxa,a[pip]);
						maxb=max(maxb,b[pip]);
					}
					ans+=maxa*maxb;
				}
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		while(Q--)
		{
			cin>>l>>r;
			ans=0;
			for(int p=l;p<=r;++p)
			{
				for(int q=l;q<=r;++q)
				{
					maxa=query(0,p,q);
					maxb=query(1,p,q);
					ans+=maxa*maxb;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
0 2
2 1
1 2
1
1 2

*/
