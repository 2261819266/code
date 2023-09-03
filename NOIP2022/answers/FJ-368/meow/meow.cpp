//NOIP2022 RP++!
//in:meow.in
//out:meow.out
//Let us go!
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	int x,y,z;
	node(int xx,int xxx,int xxxx){
		x=xx;
		y=xxx;
		z=xxxx;
	}
};
vector<node> v;
deque<int> q1,q2;
int vis[600];
int n,m,k;
int a;
int t;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=1;i<=k;i++) vis[k]=0;
		v.clear();
		q1.clear();
		q2.clear();
		for(int i=1;i<=m;i++){
			cin>>a;
			if(!vis[a]){
				q1.push_back(a);
				v.push_back(node(1,1,0));
				vis[a]++;
			}
			else{
				if(q1.back()==a){
					q1.pop_back();
					v.push_back(node(1,1,0));
					vis[a]--;
				}
				else if(q1.front()==a){
					q1.pop_front();
					vis[a]--;
					v.push_back(node(1,2,0));
					v.push_back(node(2,1,2));
				}
				else{
					q1.push_back(a);
					v.push_back(node(1,1,0));
					vis[a]++;
				}
			}
		}
		int vsize=v.size();
		cout<<vsize<<endl;
		for(int i=0;i<vsize;i++){
			if(v[i].x==1) cout<<v[i].x<<" "<<v[i].y<<endl;
			else cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].z<<endl;
		}
	}
	return 0;
}
//15pts
