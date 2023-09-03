#include<bits/stdc++.h>
using namespace std;
int a[301][3],T,n,m,k,c,sum=0,x[2000001],y[2000001],z[2000001];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>m>>k;
		for(int j=1;j<=m;j++){
			cin>>c;
			if(a[(c+1)/2][1]==0){
				sum++;
				a[(c+1)/2][1]=c;
				x[sum]=1;
				y[sum]=(c+1)/2;
				continue;
			} 
			if(a[(c+1)/2][1]!=c&&a[(c+1)/2][2]==0){
				sum++;
				a[(c+1)/2][2]=c;
				x[sum]=1;
				y[sum]=(c+1)/2;
				continue;
			}
			if(a[(c+1)/2][1]==c) {
				sum++;
				x[sum]=1;
				y[sum]=n;
				sum++;
				x[sum]=2;
				y[sum]=(c+1)/2;
				z[sum]=n;
				a[(c+1)/2][1]==a[(c+1)/2][2];
				a[(c+1)/2][2]=0;
				continue;
			}
			if(a[(c+1)/2][2]==c) {
				sum++;
				x[sum]=1;
				y[sum]=(c+1)/2;
				a[(c+1)/2][2]=0;
				continue;
			}
		} 
		cout<<sum<<endl;
		for(int j=1;j<=sum;j++){
			if(x[j]==1) cout<<"1 "<<y[j]<<endl;
			else cout<<"2 "<<y[j]<<" "<<z[j]<<endl;
		}
	}
	return 0;
}
