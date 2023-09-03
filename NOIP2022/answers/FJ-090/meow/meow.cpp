#include<iostream>
#include<queue>
using namespace std;

int a[10000];
bool pd(queue s[301],int n){
	for(int i=1;i<=n;i++){
		if(s[n].size()!=0){
			return false;
		}
	}
	return true;
}
void js(int m,int b,queue s[301],int n,int c,int op){
	if(c==m&&pd(s,n)){
		cout<<op<<endl;
	}
	if(b==1){
		for(int i=1;i<=n;i++){
			s[i].push(a[m]);
		}
	}
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n,m,k;
		queue s[301];
		cin>>n>>m>>k;
		for(int j=1;j<=m;j++){
			cin>>a[j];
		}
	}
	return 0;
}
