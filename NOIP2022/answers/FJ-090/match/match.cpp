#include<iostream>
using namespace std;

long long a[1000000],b[1000000],s[1000000];
int da(int s,int m,int d){
	int c=0;
	for(int i=s;i<=m;i++){
		if(a[i]>c&&d==1){
			c=a[i];
		}
		if(b[i]>c&&d==2){
			c=b[i];
		}
	}
	return c;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	long long T,n;
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long Q;
	cin>>Q;
	for(int i=1;i<=Q;i++){
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++){
			for(int k=j;k<=r;k++){
				s[i]=(s[i]+da(j,k,1)*da(j,k,2));
			}
		}
	}
	for(int i=1;i<=Q;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}
