#include<bits/stdc++.h>
//#define int __int128
#define int unsigned long long
using namespace std;

int read(){
	int w=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')w=w*10+ch-48,ch=getchar();
	return w;
}

void put(int x){
	if(x>10)put(x/10);
	putchar(x%10+48);
}

#define MAXN 250003
int id,n,q;
int a[MAXN][2];
//const int mod=18446744073709551616;
const int mod=18446744073709551616-1;

int d[MAXN<<2][2];
int mid[MAXN<<2];

void build(int s,int t,int p){
	if(s==t){
		d[p][0]=a[s][0];
		d[p][1]=a[s][1];
		return;
	}
	mid[p]=s+(t-s)/2;
	build(s,mid[p],p*2);
	build(mid[p]+1,t,p*2+1);
	d[p][0]=max(d[p*2][0],d[p*2+1][0]);
	d[p][1]=max(d[p*2][1],d[p*2+1][1]);
}

int getans(bool gr,int l,int r,int s,int t,int p){
	if(l<=s&&t<=r)return d[p][gr];
	int ans1=0,ans2=0;
	if(l<=mid[p])ans1=getans(gr,l,r,s,mid[p],p*2);
	if(mid[p]<r)ans2=getans(gr,l,r,mid[p]+1,t,p*2+1);
	return max(ans1,ans2)%mod;
}

signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	id=read(),n=read();
	for(int i=1;i<=n;i++)a[i][0]=read();
	for(int i=1;i<=n;i++)a[i][1]=read();
	build(1,n,1);
	q=read();
	while(q--){
		int l=read(),r=read(),ans=0;
		for(int i=l;i<=r;i++)for(int j=l;j<=r;j++){
			ans=(ans+(getans(0,i,j,1,n,1)*getans(1,i,j,1,n,1))%mod)%mod;
		}
		printf("%lld\n",ans);
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
// 1 10:13
