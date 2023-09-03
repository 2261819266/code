#include<bits/stdc++.h>
#define f(i,n,m) for(int i=n;i<=m;i++)
using namespace std;
typedef long long LL;
const int N = 500010,M = 2000100;
const int mods = 1e9 + 7;
int h[N],e[M],ne[M],idx;
int n,m;
int dcc_cnt;
int size[N];
int low[N],dfn[N],tms;
int stk[N],top;
int id[N];
bool is_bridge[N];
void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void tarjan(int u){
	dfn[u] = low[u] = idx;
	stk[++top] = u;
	for(int i=h[u];~i;i=ne[i]){
		int j = e[i];
		if(!dfn[j]){
			tarjan(j);
			low[u] = min(low[u],low[j]);
			if(low[j] <= dfn[u]){
				dcc_cnt ++;
				is_bridge[i] = true;
				int y;
				do{
					y = stk[top--];
					size[dcc_cnt] ++;
					id[y] = dcc_cnt;
				}while(y != j);
			}
		}else{
			low[u] = min(low[u],dfn[j]);
		}
		
	}	
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	memset(h,-1,sizeof h);	
	scanf("%d%d",&n,&m);
	//cout<<n<<" "<<m<<endl;
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b),add(b,a); 
	}
	if(m == n-1){
		LL ans = n-1;
		//cout<<ans<<endl;
		LL res = 0;
		for(int i=(n-2)*2;i>=0;i-=2){
			res = (res + (1 << i)%mods) % mods;
		}
		ans = (ans * res) % mods;
		ans = (ans + n*(1<<m)%mods)%mods;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	return 0;
}
