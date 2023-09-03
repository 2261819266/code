#include<bits/stdc++.h>
using namespace std;
#define maxn 250009
typedef unsigned long long ull;
int t,n,a[maxn],b[maxn];
int lta[maxn],rta[maxn],nla[maxn],nra[maxn],fa[maxn];
int ltb[maxn],rtb[maxn],nlb[maxn],nrb[maxn],fb[maxn];
ull sums[3009][3009];
inline int read(){
	int sum=0,d=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')d=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*d;
}
void dfsa(int now,int l,int r){
	if(!now)return ;
	nla[now]=l;nra[now]=r;
	dfsa(lta[now],l,now-1);
	dfsa(rta[now],now+1,r);
	return ;
}
void dfsb(int now,int l,int r){
	if(!now)return ;
	nlb[now]=l;nrb[now]=r;
	for(int i=l;i<=now;i++)for(int j=now;j<=r;j++){
		sums[i][j]+=(ull)b[now]; 
	}
	dfsb(ltb[now],l,now-1);
	dfsb(rtb[now],now+1,r);
	return ;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();n=read();
	a[0]=b[0]=1e9;
	for(int i=1;i<=n;i++){
		a[i]=read();
		int j=i-1,lj=0;
		while(a[j]<a[i]){
			lj=j;j=fa[j];
			rta[lj]=lta[i];fa[lta[i]]=lj;
			lta[i]=lj;fa[lj]=i;
		}
		rta[j]=i;fa[i]=j;
	}
	for(int i=1;i<=n;i++){
		b[i]=read();
		int j=i-1,lj=0;
		while(b[j]<b[i]){
			lj=j;j=fb[j];
			rtb[lj]=ltb[i];fb[ltb[i]]=lj;
			ltb[i]=lj;fb[lj]=i;
		}
		rtb[j]=i;fb[i]=j;
	}
	dfsa(rta[0],1,n);
	dfsb(rtb[0],1,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sums[i][j]+=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
		}
	}
	int q=read();
	while(q--){
		int l=read(),r=read();
		ull ans=0;
		for(int i=l;i<=r;i++){
			int ls=max(l,nla[i]),rs=min(nra[i],r);
			ans+=a[i]*(sums[i][rs]+sums[ls-1][i-1]-sums[ls-1][rs]-sums[i][i-1]);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

