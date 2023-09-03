#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void read(int &x){
	static char c;
	static int f;
	f=1;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
	x*=f;
}

void read(ll &x){
	static char c;
	static int f;
	f=1;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
	x*=f;
}

void read(ull &x){
	static char c;
	while(!isdigit(c=getchar()));x=c^48;
	while(isdigit(c=getchar())) x=(x*10)+(c^48);
}

void chkmax(int &x,int y){if(y>x)x=y;}
void chkmin(int &x,int y){if(y<x)x=y;}
void chkmax(ll &x,ll y){if(y>x)x=y;}
void chkmin(ll &x,ll y){if(y<x)x=y;}
void chkmax(ull &x,ull y){if(y>x)x=y;}
void chkmin(ull &x,ull y){if(y<x)x=y;}

void Work(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n,Q;read(T),read(n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;++i) read(a[i]);
	for(int i=0;i<n;++i) read(b[i]);

	vector< vector<ull> > r(n);
	for(int i=0;i<n;++i){
		r[i].resize(n);
		ull ma=0,mb=0;
		for(int j=i;j<n;++j)
			chkmax(ma,a[j]),chkmax(mb,b[j]),r[i][j]=ma*mb;
		for(int j=1;j<n;++j) r[i][j]+=r[i][j-1];
	}

	read(Q);
	for(int i=1;i<=Q;++i){
		int L,R;read(L),read(R),--L,--R;
		ull ans=0;
		for(int p=L;p<=R;++p) ans+=r[p][R];
		printf("%llu\n",ans);
	}
}

int main(){Work();}

