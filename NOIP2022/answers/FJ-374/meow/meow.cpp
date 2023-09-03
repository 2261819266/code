#include<bits/stdc++.h>
using namespace std;
int a[2000010];
deque<int>q[310];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t,id;
	cin>>t;
	id=t%10;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>a[i];
		if(id==1){
			int op=m;
			for(int i=1;i<=n;i++){
				while(!q[i].empty())q[i].pop_front();
			}
			for(int i=1;i<=m;i++){
				if(q[(a[i]+1)/2].empty()){
					q[(a[i]+1)/2].push_front(a[i]);
				}
				else if(a[i]==q[(a[i]+1)/2].back()){
					q[(a[i]+1)/2].pop_back();
					op++;
				}
				else if(q[(a[i]+1)/2].front()==a[i]){
					q[(a[i]+1)/2].pop_front();
				}
				else{
					q[(a[i]+1)/2].push_front(a[i]);
				}
			}
			for(int i=1;i<=n;i++){
				while(!q[i].empty())q[i].pop_front();
			}
			cout<<op<<'\n';
			for(int i=1;i<=m;i++){
				if(q[(a[i]+1)/2].empty()){
					q[(a[i]+1)/2].push_front(a[i]);
					cout<<"1 "<<(a[i]+1)/2<<'\n';
				}
				else if(a[i]==q[(a[i]+1)/2].back()){
					q[(a[i]+1)/2].pop_back();
					cout<<"1 "<<n<<'\n';
					cout<<"2 "<<(a[i]+1)/2<<" "<<n<<'\n';
				}
				else if(q[(a[i]+1)/2].front()==a[i]){
					q[(a[i]+1)/2].pop_front();
					cout<<"1 "<<(a[i]+1)/2<<'\n';
				}
				else{
					q[(a[i]+1)/2].push_front(a[i]);
					cout<<"1 "<<(a[i]+1)/2<<'\n';
				}
			}
		}
	}
	return 0;
}