#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0,ex2[65];
const long long Mod1=1000000007;
int ksm(int x){
	long long sum=1;
	for(int i=1;x>0;i++){
		if(x%2==1){
			sum*=ex2[i];
			sum%=Mod1;
		}
		x/=2;
	}
	return sum;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	ex2[1]=2;
	for(int i=2;i<=64;i++){
		ex2[i]=ex2[i-1]*ex2[i-1];
		ex2[i]%=Mod1;
	}
	int x,y;
	for(int i=1;i<=m;i++) cin>>x>>y;
	for(int i=1;i<=n;i++){
		long long sum,a,b;
		sum=ksm(i)-1;
		a=2*sum;
		a%=Mod1;
		a*=ksm(m-i);
		a%=Mod1;
		b=sum*(n-i-1);
		b%=Mod1;
		b*=ksm(m-i-1);
		b%=Mod1;
		sum=a+b;
		sum%=Mod1;
		ans+=sum;
		ans%=Mod1;
	}
	cout<<ans;
	return 0;
}
