#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T,n,m,k;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		cout<<m<<endl;
		for(int i=1;i<=m;i++){
			cout<<1<<" "<<1<<endl;
		}
	}
}
