#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
int T,n,m,k,a,at[N][N];
bool have[N];
struct ansNode{int op,s1,s2;};
struct Node{int id;bool use;};
deque<int> q[N];
queue<ansNode> ans;
priority_queue<Node> res;
bool operator <(Node a,Node b){
	return a.use>b.use;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){
//			cout<<"*"<<i<<endl;
			scanf("%d",&a);
			bool f1=0,f2=0;
			for(int j=1;j<=n;j++){
				if(q[j].size()&&q[j].front()==a){
					f1=1;
					q[j].pop_front();
					at[j][a]--;
					ans.push((ansNode){1,j,0});
					if(q[j].empty()){
						have[j]=0;
					}
					break;
				}
			}
			if(!f1) for(int j=1;j<=n;j++){
				if(q[j].size()&&q[j].back()==a){
					for(int o=1;o<=n;o++){
						f2=1;
						if(o==j) continue;
						if(!have[o]){
							at[j][a]--;
							q[j].pop_back();
							ans.push((ansNode){1,o,0});
							ans.push((ansNode){2,j,o});
							break;
						}
					}
					break;
				}
			}
			if(!f1&&!f2){
				for(int j=1;j<=n;j++){
					if(!at[j][a]){
						q[j].push_front(a);
						have[j]=1;
						at[j][a]++;
						ans.push((ansNode){1,j,0});
						break;
					}
				}
			}
//			if(q[pos].size()&&q[pos].front()==a){
//				q[pos].pop_front();
//				
//				ans.push((ansNode){1,pos,0});
//				if(q[pos].empty()){
//					have[pos]=0;
//					res.push((Node){pos,0});
//				}
//			}
//			else if(q[pos].size()&&q[pos].back()==a){
//				while(have[res.top().id]) res.pop();
//				Node t=res.top();res.pop();
//				bool use=t.use;
//				int id=t.id;
//				if(!use){
//					q[pos].pop_back();
//					ans.push((ansNode){1,id,0});
//					ans.push((ansNode){2,pos,id});
//					res.push(t);
//					if(q[pos].empty()){
//						have[pos]=0;
//						res.push((Node){pos,0});
//					}
//				}
//				else{
//					q[pos].push_front(a);
//					have[pos]=1;
//					ans.push((ansNode){1,pos,0});
//					at[a][]=1;
//				}
//			}
//			else{
//				q[pos].push_front(a);
//				have[pos]=1;
//				ans.push((ansNode){1,pos,0});
//			}
		}
//		cout<<q[1].size()<<" "<<q[2].size()<<" "<<q[3].size()<<endl;
		for(int j=1;j<=n;j++){
			while(q[j].size()){
//				cout<<"%%"<<q[j].size()<<endl;
				for(int p=j+1;p<=n;p++){
					if(q[p].size()&&q[j].back()==q[p].back()){
						q[j].pop_back();q[p].pop_back();
						at[j][q[j].back()]--;at[p][q[p].back()]--;
						ans.push((ansNode){2,j,p});
					}
				}
			}
		}
	
		printf("%d\n",ans.size());
		while(ans.size()){
			ansNode aa=ans.front();ans.pop();
			int op=aa.op,s1=aa.s1,s2=aa.s2;
			if(op==1){
				printf("%d %d\n",op,s1);
			}
			else printf("%d %d %d\n",op,s1,s2);
		}
	}
	return 0;
}
