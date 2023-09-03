#include<bits/stdc++.h>
using namespace std;
const long long N=30,P=1e9+7;
vector<long long> d[N][N];
vector<pair<long long,long long> > e[N];
bool flag[N];
long long n,m,mi[N],ans;
long long gn[N],rn;
long long chosen[N];
void init(){
	cin>>n>>m;
	for(long long i=1;i<=m;i++){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		e[x].push_back(make_pair(i,y));
		e[y].push_back(make_pair(i,x));
	}
}
void mig(){
	mi[0]=1;
	for(long long i=1;i<=m;i++)	mi[i]=mi[i-1]*2%P;
}
bool dfs(long long p,long long ed){
	if(p==ed){
		rn++;
		return true;
	}
	if(flag[p])	return false;
	flag[p]=true;
	bool ret=false;
	for(long long i=0;i<e[p].size();i++){
		long long y=e[p][i].second;
		if(dfs(y,ed))	gn[e[p][i].first]++,ret=true;
	}
	flag[p]=false;
	return ret;
}
void choose(long long k){
	if(k>n){
		if(chosen[0]==0)	return;
		memset(gn,0,sizeof gn);
		for(long long i=1;i<=chosen[0];i++)
			for(long long j=1;j<=chosen[0];j++){
				long long st=chosen[i],ed=chosen[j];
				for(long long k=0;k<d[st][ed].size();k++){
					gn[d[st][ed][k]]=1;
				}
			}
		long long minum=m;
		for(long long i=1;i<=m;i++)	if(gn[i]==1)	minum--;
		ans=(ans+mi[minum])%P;
		return;
	}
	choose(k+1);
	chosen[++chosen[0]]=k;
	choose(k+1);
	chosen[0]--;
}
void Barrack(){
	init();
	mig();
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			memset(gn,0,sizeof gn);
			rn=0;
			dfs(i,j);
			d[i][j].clear();
			for(long long k=1;k<=m;k++)
				if(gn[k]==rn)
					d[i][j].push_back(k);
		}
	}
	choose(1);
	cout<<ans<<endl;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	Barrack();
	return 0;
}
