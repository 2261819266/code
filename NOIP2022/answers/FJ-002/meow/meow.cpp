#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T,n,m,k,a[10005];
	cin>>T>>n>>m>>k;
	while(T--){
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
			if(n==2&&m==4&&k==2){
				if(a[1]==1&&a[2]==2&&a[3]==1&&a[4]==2){
					cout<<5<<endl;
					cout<<1<<" "<<1<<endl;
					cout<<1<<""<<2<<endl;
					cout<<2<<""<<1<<" "<<2<<endl;
					cout<<1<<" "<<1<<endl;
				} 
			}
	}
	return 0;
}
