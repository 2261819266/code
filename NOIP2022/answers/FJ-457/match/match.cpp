#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int read(){
	int x=0,f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	while(isdigit(c))x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return x*f;
}
const int N=3010;
int a[N],b[N],fa[N][25],fb[N][25];
int T,n,q;
int Maxa(int l,int r){
	int s=log(r-l+1)/log(2);
	return max(fa[l][s],fa[r-(1<<s)+1][s]);
}
int Maxb(int l,int r){
	int s=log(r-l+1)/log(2);
	return max(fb[l][s],fb[r-(1<<s)+1][s]);
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=n;i++)a[i]=fa[i][0]=read();
	for(int i=1;i<=n;i++)b[i]=fb[i][0]=read();
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]);
			fb[i][j]=max(fb[i][j-1],fb[i+(1<<(j-1))][j-1]);
		}
	}
	q=read();
	while(q--){
		int l=read(),r=read(),ans=0;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				ans+=Maxa(i,j)*Maxb(i,j);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

