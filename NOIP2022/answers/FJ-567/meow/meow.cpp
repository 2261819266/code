#include<bits/stdc++.h>
using namespace std;
int t,n,k,m;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0);
	cin>>t;
	if(t==1001){
		int cc=1;
		int a[600][2];
		memset(a,0,sizeof(a));
		map<int,int>ma;
		while(cc<=t){
			cin>>n>>m>>k;
			int cnt=0;
			int ma[300];
			map<int,int>map_;
			for(int i=1;i<=m;i++){
				cin>>ma[i];
				map_[ma[i]]=0;
			}
			cout<<m<<endl;
			for(int i=1;i<=m;i++){
				int temp=map_[ma[i]];
				cnt%=n;
				cnt++;
				if(temp==0){
					cout<<1<<" "<<cnt<<endl;
					map_[ma[i]]=cnt;
				}
				else{
					cnt--;
					cout<<1<<" "<<temp<<endl;
					map_[ma[i]]=0;
				}
			}
			cc++;
		}
	}
	if(t==1002){
		for(int i=1;i<=t;i++){
			
		}
	}
	if(t==3){
		for(int i=1;i<=t;i++){
			
		}
	}
	if(t==1004){
		for(int i=1;i<=t;i++){
			
		}
	}
	if(t==1005){
		for(int i=1;i<=t;i++){
			
		}
	}
	return 0;
}