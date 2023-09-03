#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
int t,n,m,k,a,s1,ans;
deque<int>q[300000];
set<int> at_top[1000],at_back[1000],eq,neq,not_top[1000];
queue<int>ans1[3];
void Push(int x,int y,int z){
	//cout<<x<<' '<<y<<' '<<z<<endl;
	ans1[0].push(x);
	ans1[1].push(y);
	ans1[2].push(z);
}
/*bool print1(){
	cout<<1;
	return 1;
}*/
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m>>k;
		for(int i=1;i<=k;i++){
			at_top[i].clear();
			at_back[i].clear();
			not_top[i].clear();
			for(int j=1;j<=n;j++){
				not_top[i].insert(j);
			}
		}
		neq.clear();
		eq.clear();
		for(int i=1;i<=n;i++)eq.insert(i);
		for(int i=1;i<=m;i++){
			//cout<<"done"<<endl;
			//cout<<'-'<<i<<'-';
			cin>>a;
			//cout<<"good";
			//cout<<'-'<<i<<'-';
			//cout<<a<<' ';
			if(/*print1()&&*/!at_back[a].empty()){
				//cout<<'a';
				s1=*at_back[a].begin();
				at_back[a].erase(s1);
				q[s1].pop_back();
				if(!q[s1].empty()){
					at_back[q[s1].back()].insert(s1);
				}
				else{
					at_top[a].erase(s1);
					not_top[a].insert(s1);
					eq.insert(s1);
					neq.erase(s1);
				}
				Push(1,s1,0);
				ans++;
				//cout<<'d';
			}
			else if(/*print1()&&*/!at_top[a].empty()){
				if(!eq.empty()){
					//cout<<'b';
					s1=*at_top[a].begin();
					at_top[a].erase(s1);
					not_top[a].insert(s1);
					q[s1].pop_front();
					if(!q[s1].empty()){
						at_top[q[s1].front()].insert(s1);
						not_top[q[s1].front()].erase(s1);
					}
					else{
						at_back[a].erase(s1);
						eq.insert(s1);
						neq.erase(s1);
					}
					Push(1,*eq.begin(),0);
					Push(2,s1,*eq.begin());
					ans+=2;
					//cout<<'d';
				}
				else{
					if(!not_top[a].empty())s1=*not_top[a].begin();
					else s1=*neq.begin();
					at_back[a].insert(s1);
					at_back[q[s1].back()].erase(s1);
					q[s1].push_back(a);
					ans++;
					Push(1,s1,0);
				}
			}
			else{
				//cout<<'c';
				if(!eq.empty()){
					s1=*eq.begin();
					at_back[a].insert(s1);
					at_top[a].insert(s1);
					not_top[a].erase(s1);
					q[s1].push_back(a);
					eq.erase(s1);
					neq.insert(s1);
					ans++;
					Push(1,s1,0);
				}
				else{
					if(!not_top[a].empty())s1=*not_top[a].begin();
					else s1=*neq.begin();
					at_back[a].insert(s1);
					q[s1].push_back(a);
					ans++;
					Push(1,s1,0);
				}
				//cout<<'d';
			}
		}
		cout<<ans<<endl;
		while(!ans1[0].empty()){
			if(ans1[0].front()==1){
				cout<<ans1[0].front()<<' '<<ans1[1].front()<<endl;
				ans1[0].pop();
				ans1[1].pop();
				ans1[2].pop();
			}
			if(ans1[0].front()==2){
				cout<<ans1[0].front()<<' '<<ans1[1].front()<<' '<<ans1[2].front()<<endl;
				ans1[0].pop();
				ans1[1].pop();
				ans1[2].pop();
			}
		}
		//cout<<"done"<<endl;
	}
	return 0;
}
/*
2
2 4 2
1 2 1 2
2 4 2
1 2 1 2
*/
