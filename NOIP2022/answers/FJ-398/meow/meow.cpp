#include<bits/stdc++.h>
using namespace std;
const int MAX=3*1e6;
int t,n,m,k,tot,a[MAX],z1[MAX],l1,r1,ans[2*MAX];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	for(int s=1;s<=t;s++){
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++)cin>>a[i];
		tot=0;
		if(n==2){
			z1[1]=a[1];
			l1=1,r1=1;
			for(int i=2;i<=m;i++){
				ans[++tot]=1;
				if(a[i]==z1[l1]){
					l1++;
					ans[++tot]=2;
				}
				else {
					if(a[i]==z1[r1])r1--;
					else z1[++r1]=a[i];
				}
			}
			cout<<tot+1<<endl<<"1 1\n";
			for(int i=1;i<=tot;i++){
				cout<<ans[i]<<' ';
				if(ans[i]==1){
					cout<<ans[i+1]<<endl;
				}
				else cout<<"1 2\n";
			}
		}
	}
	return 0;
}
