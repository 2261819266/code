#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
deque<int> st[310];
struct S{
	int id;
	int x,y;
};
S ans[2000010];
int T,n,m,k;
bool fa;
int a[2000010];
int len;
bool check(){
	for(int i=1;i<=n;i++){
		if(!st[i].empty()){
			return 0;
		}
	}
	return 1;
}
void dfs(int s){
	if(fa) return;
	if(s == m+1){
		if(check()){
			cout<<len<<endl;
			for(int i=1;i<=len;i++){
				if(ans[i].id == 1){
					cout<<1<<" "<<ans[i].x<<endl;
				}
				else{
					cout<<2<<" "<<ans[i].x<<" "<<ans[i].y<<endl;
				}
			}
			fa=1;
		}
		return;
	}
	if(fa) return;
	for(int i=1;i<=n;i++){
		if(fa) return;
		S xx;
		xx.id=1,xx.x=i;
		st[i].push_back(a[s]);
		ans[++len] = xx;
		dfs(s+1);
		len--;
		st[i].pop_back();
		if(!st[i].empty()){
			if(a[s] == st[i].back()){
				xx.id=1,xx.x=i;
				st[i].pop_back();
				ans[++len] = xx;
				dfs(s+1);
				len--;
				st[i].push_back(a[s]);
			}
			if(a[s] == st[i].front()){
				if(st[n].empty()){
					st[i].pop_front();
					xx.id=1,xx.x=n;
					ans[++len]=xx;
					xx.id=2,xx.x=i,xx.y=n;
					ans[++len]=xx;
					dfs(s+1);
					len-=2;
					st[i].push_front(a[s]);
				}
			}
		}
		
	}
}
int main(){
  freopen("meow.in","r",stdin);
  freopen("meow.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		fa=0;
		len=0;
		for(int i=1;i<=n;i++)
			while(!st[i].empty()){
				st[i].pop_back();
			}
		dfs(1);
	}
	return 0;
}

