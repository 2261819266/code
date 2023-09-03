#include<bits/stdc++.h>
using namespace std;
template<typename T>void rd(T&x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
	x*=f;
}
typedef unsigned long long ull;
const int N=2.5e5+10,L=20;
int t,n,q,lg[N],st[2][L][N];
ull a[2][N],s;
int maxp(bool k,int l,int r){
	++r;
	int d=lg[r-l],p=st[k][d][l],q=st[k][d][r-(1<<d)];
	return a[k][p]>a[k][q]?p:q;
}
ull calc(bool k,int l,int m,int r){
	if(l>m||m>r)return 0;
	int p=maxp(k,l,r);
	if(p>m)return calc(k,l,m,p-1)+a[k][p]*(m-l+1)*(r-p+1);
	return calc(k,p+1,m,r)+a[k][p]*(r-m+1)*(p-l+1);
}
void solve(ull l,ull r){
	if(l>r)return;
	ull p=maxp(0,l,r),q=maxp(1,l,r);bool k;
	if(p>q)k=1,swap(p,q);
	else k=0;
	s+=a[k][p]*a[k^1][q]*(p-l+1)*(r-q+1);
	s+=a[k][p]*calc(k^1,l,p,q-1)+a[k^1][q]*calc(k,p+1,q,r);
	solve(l,p-1);solve(p+1,q-1);solve(q+1,r);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	for(int i=2;i<N;++i)lg[i]=lg[i>>1]+1;
	rd(t);rd(n);
	for(int k=0;k<=1;++k){ 
		for(int i=1;i<=n;++i)rd(a[k][i]),st[k][0][i]=i;
		for(int j=1;j<L;++j){
			for(int i=1;i<=n+1-(1<<j);++i){
				int p=st[k][j-1][i],q=st[k][j-1][i+(1<<(j-1))];
				st[k][j][i]=a[k][p]>a[k][q]?p:q;
			}
		}
//		for(int l=1;l<=n;++l){
//			for(int r=l;r<=n;++r){
//				printf("%d",maxp(k,l,r));
//			}
//			puts("");
//		}
	}
	rd(q);
	while(q--){
		ull l,r;
		rd(l);rd(r);s=0;
		solve(l,r);
		printf("%llu\n",s);
	}
}

