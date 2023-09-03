#include<bits/stdc++.h>
#define maxn 500005
using namespace std;

typedef long long ll;
const int mo=1e9+7;

void FR(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
}

struct Edge{
	int v;
	int to;
}e[maxn*4];
int tote,head[maxn];
int n,m;
void ae(int u,int v){
	e[tote].to=head[u];
	e[tote].v=v;
	head[u]=tote;
	tote++;
}

pair<int,int> edge[50];

bool vis[maxn];

int pc(int x){//popcount
	int ret=0;
	while(x){
		if(x&1) ret++;
		x>>=1;
	}
	return ret;
}

int dfs1(int V){
	ll ret=0;
	for(int k=0;k<(1<<m);++k){
		bool flag=1;
		tote=0;
		memset(head,-1,sizeof(head));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;++i) if(k&(1<<i-1)) ae(edge[i].first,edge[i].second),ae(edge[i].second,edge[i].first);
		queue<int> qu;
		for(int i=0;(1<<i)<=V;++i){
			if(V&(1<<i)){
				 qu.push(i+1);
				 break;
			}
		}
		while(!qu.empty()){
			int top=qu.front();
			qu.pop();
			if(vis[top]) continue;
			vis[top]=1;
			for(int i=head[top];i!=-1;i=e[i].to){
				if(!vis[e[i].v]) qu.push(e[i].v);
			}
		}
		for(int i=0;(1<<i)<=V;++i){
			if(V&(1<<i)){
				 if(!vis[i+1]){
				 	flag=0;
				 	break;
				 }
			}
		}
		if(flag){
			//ret+=(1<<m-pc(k))%mo;
			ret++;
		}
//		for(int i=1;i<=n;++i){
//			if((1<<i-1)&V==0) continue;
//			for(int j=1;j<=n;++j){
//				if((1<<j-1)&V==0) continue;
//				
//			}
//		}
	}
	return ret;
}

int dfs(){
	ll ans=0;
	for(int i=1;i<(1<<n);++i){
		ans+=dfs1(i);
		ans%=mo;
	}
	return ans;
}

ll me[maxn],pro[maxn],sum1[maxn],jc[maxn];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	FR();
	//cerr<<(1<<25)<<endl;
	//scanf("%d%d",&n,&m);
	cin>>n>>m;
	memset(head,-1,sizeof(head));
	for(int i=1,u,v;i<=m;++i){
		//scanf("%d%d",&u,&v);
		cin>>u>>v;
		edge[i]=make_pair(u,v);
		//ae(u,v),ae(v,u);
	}
	cout<<dfs()<<endl;
//	if(n==m+1){
//		me[0]=jc[0]=1;
//		for(int i=1;i<=n;++i){
//			me[i]=(me[i-1]%mo*2)%mo;
//			pro[i]=(i+1)%mo*me[i]%mo;
//			jc[i]=jc[i-1]*i%mo;
//			jc[i]%=mo;
//		}
//		for(int i=n;n>=2;--i){
//			sum1[i]=sum1[i+1]%mo+pro[n-i]%mo*jc[];
//			sum1[i]%=mo;
//		}
//	}
	return 0;
}

