#include <bits/stdc++.h>
#define M 20
#define D deque<int>
using namespace std;
struct doing{
	int ty,x,y;
}b[2*M];
int t,n,m,k,a[M],bl;
D q[3],c;
bool en;
void copy(D p,D &o){
	o.clear();
	while(!p.empty()){
		o.push_back(p.front());
		p.pop_front();
	}
}
void check(int x){				//not best
	if(q[x].empty()) return;
	for(int i=0;i<n;i++){
		if(i==x) continue;
		if(q[i].empty()) continue;
		if(q[i].front()==q[x].front()){
			b[bl].ty=2;
			b[bl].x=x;
			b[bl].y=i;
			bl++;
			q[i].pop_front();
			q[x].pop_front();
			check(i);
			check(x);
		}
	}
}
void push(int x,int y){
	b[bl].ty=1;
	b[bl].x=x+1;
	bl++;
	if(q[x].empty()){
		q[x].push_back(y);
		check(x);
		return;
	}
	if(q[x].back()==y){
		q[x].pop_back();
		if(q[x].empty())
			check(x);
		return;
	}
	q[x].push_back(y);
}
void dfs(int d){
	if(d==m){
		bool flag=0;
		for(int i=0;i<n;i++){
			if(!q[i].empty())
				flag=1;
		}
		if(!flag){
			cout<<bl<<endl;
			for(int i=0;i<bl;i++){
				cout<<b[i].ty<<' '<<b[i].x;
				if(b[i].ty==2)
					cout<<' '<<b[i].y;
				cout<<endl;
			}
			en=1;
		}
		return;
	}
	for(int i=0;i<n;i++){
		copy(q[i],c);
		push(i,a[d]);
		dfs(d+1);
		if(en) return;
		copy(c,q[i]);
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--){
		en=0;
		bl=0;
		for(int i=0;i<n;i++)
			q[i].clear();
		cin>>n>>m>>k;
		n=3;
		for(int i=0;i<m;i++)
			cin>>a[i];
		dfs(0);
	}
	return 0;
}
