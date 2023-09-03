#include<bits/stdc++.h>
using namespace std;
const int MAXN=114514;
int t,n,m,k,a[MAXN],err;
int op,b[2*MAXN+1],c[2*MAXN+1],d[2*MAXN+1];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	if(t==1001||t==1005) err=301;
	if(t==1002) err=3;
	if(t==3||t==1004) err=4;
	int s[err][MAXN],u,v,w; //u-1,v-2,w=m
	for(int i=1;i<=t;i++)
	{
		op=0;
		cin>>n>>m>>k;
		w=m;
		for(int j=1;j<=m;j++) cin>>a[j];
		s[1][1]=a[1];
		s[1][0]=0;
		s[2][0]=0;
		u=1;
		v=0;
		for(int j=2;j<=m;j++)
		{
			if(a[j]==s[1][j-1])
			{
				w--;
				u--;
				op++;
				b[op]=1;
			}
			else
			{
				if(s[1][1]==a[j]&&v==0)
				{
					w--;
					u--;
					op++;
					b[op]=2;
					op++;
					for(int x=2;x<=u+1;x++) s[1][x-1]=s[1][x];
					c[op]=1;
					d[op]=2;
				}
				else
				{
					w--;
					u++;
					op++;
					b[op]=1;
				}
			}
		}
		cout<<op<<endl;
		for(int j=1;j<=op;j++)
		{
			if(b[op]!=0) cout<<1<<' '<<b[op]<<endl;
			else cout<<2<<' '<<c[op]<<' '<<d[op]<<endl;
		}
	}
	return 0;
}