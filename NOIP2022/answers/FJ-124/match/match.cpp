#include<bits/stdc++.h>
using namespace std;
const int maxn=250000+5;
#define int long long
typedef unsigned long long ull;
int n,testid,A[maxn],B[maxn];
int L[maxn],R[maxn],L2[maxn];
int abig[maxn][22],bbig[maxn][22];
void pre(){
	L2[0]=-1;
	for(int i=1;i<=n;i++)L2[i]=L2[i>>1]+1;
	for(int i=1;i<=n;i++)abig[i][0]=A[i];
	for(int i=1;i<=n;i++)bbig[i][0]=B[i];
	for(int i=1;i<=22;i++){
		for(int j=1;j+(1<<(i-1))<=n;j++){
			abig[j][i]=max(abig[j][i-1],abig[j+(1<<(i-1))][i-1]);
			bbig[j][i]=max(bbig[j][i-1],bbig[j+(1<<(i-1))][i-1]);
		}
	}
}
inline int qry_a(int l,int r){
	int k=L2[r-l+1];
	return max(abig[l][k],abig[r-(1<<k)+1][k]);
}
inline int qry_b(int l,int r){
	int k=L2[r-l+1];
	return max(bbig[l][k],bbig[r-(1<<k)+1][k]);
}
inline int rd(){
	int x=0,ng=1;char c;
	while((c=getchar())&&(!isdigit(c)&&(c!='-')));
	c=='-'?ng=1:x=c&15;
	while((c=getchar())&&(isdigit(c)))x=(x<<3)+(x<<1)+(c&15);
	return x*ng;
}
inline void wr(int x,char end='\n'){
	if(x==0)return putchar('0'),putchar(end),void();
	static char c[32];int t=0;
	if(x<0)putchar('-'),x=-x;
	while(x)c[++t]=x%10,x/=10;
	while(t)putchar(c[t--]^'0');
	putchar(end);
}
int calc(int x,int y){
	ull ans=0;
	for(int l=x;l<=y;l++){
		for(int r=l;r<=y;r++){
			ans+=1ull*qry_a(l,r)*qry_b(l,r);
		}
	}
	return ans;
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	testid=rd(),n=rd();
	for(int i=1;i<=n;i++)A[i]=rd();
	for(int i=1;i<=n;i++)B[i]=rd();
	pre();
	int q=rd();for(int i=1;i<=q;i++){
		L[i]=rd(),R[i]=rd();
		wr(calc(L[i],R[i]));
	}
	
}
