#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
bool flag1=0;
deque<int> q[310],pd;
deque<pair<int,pair<int,int> > > dis;

void print(){
	while(!dis.empty()){
		if(dis.front().first==1)
			cout<<1<<" "<<dis.front().second.first<<endl;
		else
			cout<<2<<" "<<dis.front().second.first<<" "<<dis.front().second.second<<endl;
		dis.pop_front();
	}
}

void dfs(int step){
	if(flag1) return;
	if(pd.empty()){
		bool flag=0;
		for(int i=1;i<=n;i++) 
			if(!q[i].empty()){
				flag=1;
				break;
			}
		if(flag==0){
			flag1=1;
			cout<<step<<endl;
			print();
			return;
		}
	}
	for(int i=1,tmp;i<=n;i++){
		if(!pd.empty()){
			bool bj=0;
			tmp=pd.front();
			pd.pop_front();
			if(q[i].front()==tmp) q[i].pop_front(),bj=1;
			else q[i].push_front(tmp);
			dis.push_back(make_pair(1,make_pair(i,0)));
			dfs(step+1);
			dis.pop_back();
			pd.push_front(tmp);
			if(bj==1) q[i].push_front(tmp);
			else q[i].pop_front();
		}
		if(!q[i].empty())
		for(int j=1;j<=n;j++){
			if(!q[j].empty())
			if(i!=j&&q[i].back()==q[j].back()){
				tmp=q[i].back();
				q[i].pop_back(); q[j].pop_back();
				dis.push_back(make_pair(2,make_pair(i,j)));
				dfs(step+1);
				dis.pop_back();
				q[i].push_back(tmp);
				q[j].push_back(tmp);
			}
		}
	}
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		flag1=0;
		cin>>n>>m>>k;
		for(int i=1,f;i<=m;i++){
			cin>>f;
			pd.push_back(f);
		}
		dfs(1);
	}
	return 0;
}

