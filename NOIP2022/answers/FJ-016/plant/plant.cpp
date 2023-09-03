#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int Mod=998244353;
void Add(int &x,int y){
	x+=y;
	if(x>=Mod) x-=Mod;
}
void Del(int &x,int y){
	x-=y;
	if(x<0) x+=Mod;
}

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

void Solve(){
	int n,m,c,f;read(n),read(m),read(c),read(f);
	vector< vector<char> > g(n);
	for(int i=0;i<n;++i){
		g[i].resize(m);
		for(int j=0;j<m;++j){cin>>g[i][j];g[i][j]-='0';}
	}
	
	vector< vector<int> > nxt(n),pref(n),prefi(n);
	for(int i=0;i<n;++i){
		nxt[i].resize(m),pref[i].resize(m),prefi[i].resize(m);
		int lst=m;
		for(int j=m-1;~j;--j)
			if(g[i][j]) lst=j;
			else nxt[i][j]=lst-j-1;
		for(int j=0;j<m;++j){
			pref[i][j]=nxt[i][j],prefi[i][j]=1ll*i*nxt[i][j]%Mod;
			if(i) Add(pref[i][j],pref[i-1][j]),Add(prefi[i][j],prefi[i-1][j]);
		}
	}
	
	int cAns=0,fAns=0;
	
	if(c) cAns=[&]()->int{
		int res=0;
		for(int j=0;j<m-1;++j){
			int lst=n;
			for(int i=n-1;~i;--i){
				if(g[i][j]) lst=i;
				else if(i+2<lst){
					int tmp=0;
					Add(tmp,pref[lst-1][j]);
					Del(tmp,pref[i+1][j]);
					Add(res,1ll*tmp*nxt[i][j]%Mod);
				}
			}
		}
		return res;
	}();
	if(f) fAns=[&]()->int{
		int res=0;
		for(int j=0;j<m-1;++j){
			int lst=n;
			for(int i=n-1;~i;--i){
				if(g[i][j]) lst=i;
				else if(i+3<lst){
					int tmp=0;
					Add(tmp,pref[lst-1][j]);
					Del(tmp,pref[i+1][j]);
					tmp=1ll*tmp*(lst-1)%Mod;
					Del(tmp,prefi[lst-1][j]);
					Add(tmp,prefi[i+1][j]);
//					printf(" i : %d , j : %d , tmp : %d , nxt : %d \n",i,j,tmp,nxt[i][j]);
					Add(res,1ll*tmp*nxt[i][j]%Mod);
				}
			}
		}
		return res;
	}();
	printf("%d %d\n",cAns,fAns);
}

void Work(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;read(T),read(id);
	while(T--) Solve();
}

int main(){Work();}

