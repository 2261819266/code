#include<bits/stdc++.h>
#define LL long long
#define Un unsigned
#define For1(i,a,b) for(i=(a);i<=(b);++i)
#define For2(i,a,b) for(i=(a);i<(b);++i)
#define FoR1(i,a,b) for(i=(a);i>=(b);--i)
#define FoR2(i,a,b) for(i=(a);i>(b);--i)
#define For_L(i,x) for(i=ft[x];i;i=nt[i])
#define mkp make_pair
#define fir first
#define sec second
template<class T1>
void cmax(T1 &x,T1 y){if(x<y)x=y;}
template<class T1>
void cmin(T1 &x,T1 y){if(x>y)x=y;}
const int mod=1e9+7;
int add(int x,int y){return (x+=y)<mod?x:x-mod;}
void addd(int &x,int y){if((x+=y)>=mod)x-=mod;}
int sub(int x,int y){return (x-=y)<0?x+mod:x;}
void subb(int &x,int y){if((x-=y)<0)x+=mod;}
int mul(int x,int y){return 1ll*x*y%mod;}
void mull(int &x,int y){x=1ll*x*y%mod;}
Un LL pow(Un LL x,int y){Un LL res=1llu;
	while(y){
		if(y&1)res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
const int N=250111;
int a[N],b[N],dfn[N],low[N],num[N],fro[N],sz[N],t2[N],n,m,q,id,tmp,cnt;
std::bitset<N>bk;
std::vector<int>g[N],g1[N];
std::stack<int>stk;
Un LL ans;
//std::bitset<N>bk;
void dfs0(int x,int pa){
	bk[x]=1;
	dfn[x]=low[x]=++tmp;
	stk.push(x);
	for(int v:g1[x])if(v!=pa){
		if(bk[v]==0){
			dfs0(v,x);
			cmin(low[x],low[v]);
		}
		else{
			cmin(low[x],low[v]);
		}
	}
	if(low[x]>dfn[pa]){++cnt;
		while(!stk.empty()&&stk.top()!=x){
			num[stk.top()]=cnt;
			sz[cnt]++;
		}
		num[x]=cnt;
		sz[cnt]++;
		fro[cnt]=pa;
		
	}
}
Un LL dfs1(int x,int pa){Un LL res=1llu;
	t2[x]++;
	for(int v:g[x])if(v!=pa){
		res*=dfs1(v,x);
		t2[x]+=t2[v];
	}
	if(t2[x]==0||t2[x]==tmp)res*=2llu;
	return 0;
}
void dfs(int x,Un LL res){
	if(x==cnt){int i;
		For1(i,1,cnt)t2[i]=0;
		tmp=bk.count();
		ans+=res*dfs1(1,0);
		return;
	}
	bk[x+1]=1;
	dfs(x+1,res*(pow(2llu,sz[x+1])-1));
	bk[x+1]=0;
	dfs(x+1,res);
}
signed main(){int i,t1,t2;
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	For1(i,1,m)scanf("%d%d",&t1,&t2),g1[t1].push_back(t2),g1[t2].push_back(t1);
	dfs0(1,0);
	For1(i,1,cnt){
		fro[i]=num[fro[i]];
		if(fro[i])g[i].push_back(fro[i]),g[fro[i]].push_back(i);
	}
	bk.reset();
	dfs(0,1llu);
	printf("%llu",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
