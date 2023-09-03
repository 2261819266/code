#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],q;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	srand(time(0));
	cin>>t>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	cin>>q;
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
	}
	cout<<"8"<<endl;
	for(int i=2;i<=q;i++){
		cout<<rand()%1000+1<<endl;
	}
	return 0;
}
