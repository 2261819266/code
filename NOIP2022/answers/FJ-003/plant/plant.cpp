#include<bits/stdc++.h>
using namespace std;
constexpr int MOD=998244353;
int rightt[1001][1001];
int down[1001][1001];
int n,m;
void process_c(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(rightt[i][j]&&rightt[i][j]!=-1&&down[i][j]>=2){
				for(int k=i+2;k<=i+down[i][j];k++){
					if(rightt[k][j]){
						ans+=rightt[k][j]*rightt[i][j];
						ans%=MOD;
					}
				}
			}
		}
	}
	cout<<ans<<" ";
}
void process_f(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(rightt[i][j]&&rightt[i][j]!=-1&&down[i][j]>=2){
				for(int k=i+2;k<=i+down[i][j];k++){
					if(rightt[k][j]&&down[k][j]&&down[k][j]!=-1){
						ans+=rightt[k][j]*rightt[i][j]*down[k][j];
						ans%=MOD;
					}
				}
			}
		}
	}
	cout<<ans<<" "; 
}
int search_down(const int& i,const int& j){
	if(down[i][j]){
		return down[i][j];
	}
	if(i>n||j>m){
		return -1;
	}
	down[i][j]=search_down(i+1,j)+1;
	return down[i][j];
}
int search_right(const int&i,const int&j){
	if(rightt[i][j]){
		return rightt[i][j];
	}
	if(i>n||j>m){
		return -1;
	}
	rightt[i][j]=search_right(i,j+1)+1;
	return rightt[i][j];
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T,id;
	cin>>T>>id;
	int c,f;
	for(int i=0;i<T;i++){
		memset(rightt,0,sizeof(rightt));
		memset(down,0,sizeof(down)); 
		cin>>n>>m>>c>>f; 
		if(c==0&&f==0){
			cout<<0<<" "<<0;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char ch;
				cin>>ch; 
				if(ch=='1'){
					down[i][j]=-1;
					rightt[i][j]=-1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				search_down(i,j);
				search_right(i,j);
			}
		}
		if(c){
			process_c();
		}
		if(f){
			process_f();
		}
		cout<<"\n";
	}
	return 0;
} 
