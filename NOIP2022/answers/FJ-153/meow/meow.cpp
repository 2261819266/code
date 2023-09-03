#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
int T;
const int N=2000005;
std::queue<int> q;
struct node{
	int op,x,y;
};
std::vector<node> op;
int pos[N],pos1[N],cnt[N],in[N],stk[N][3];
void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	op.clear();
	if(T%10==2){
		for(int i=1;i<=m;i++){
			int x;scanf("%d",&x);
			if(!q.size()||q.front()!=x) q.push(x),op.emplace_back((node){1,1,0});
			else {
				op.emplace_back((node){1,2,0});
				if(q.size()>1) op.emplace_back((node){2,1,2});
				q.pop();
			}
		}
		for(auto y:op){
			if(y.op==1) printf("%d %d\n",1,y.x);
			else printf("%d %d %d\n",2,y.x,y.y); 
		}
	}
	else{
		while(q.size()) q.pop();
		for(int i=1;i<=k;i++) pos[i]=pos1[i]=0;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n-1;i++) in[i]=1,q.push(i); 
		for(int i=1;i<=m;i++){
			int x;scanf("%d",&x);
			if(pos[x]){
				if(pos1[x]==2) {
					op.emplace_back((node){1,n,0});
					cnt[pos[x]]--;
					if(!in[pos[x]]) in[pos[x]]=1,q.push(pos[x]);
				}
				else{
					int y=stk[pos[x]][2];
					stk[pos[x]][1]=y;cnt[pos[x]]--;
					in[pos[x]]=1,q.push(pos[x]);
					op.emplace_back((node){1,n,0});op.emplace_back((node){2,n,pos[x]});
				}
				pos[x]=0;pos1[x]=0;
			}
			else{
				int p=q.front();q.pop();in[p]=0;
				op.emplace_back((node){1,p,0});
				stk[p][++cnt[p]]=x,pos[x]=p,pos1[x]=2;
				if(cnt[p]<=1) in[p]=1,q.push(p);
				else pos1[stk[p][1]]=1;
			}
		}
		printf("%d\n",op.size());
		for(auto y:op){
			if(y.op==1) printf("%d %d\n",1,y.x);
			else printf("%d %d %d\n",2,y.x,y.y); 
		}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		solve();
	} 
}
