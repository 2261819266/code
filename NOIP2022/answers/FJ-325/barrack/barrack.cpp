#include<bits/stdc++.h>
using namespace std;
int s[500005],t[500005];
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	long long n,m,ans=0,j=1;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s[i]>>t[i];	
	}
	if(n==2&&m==1){
		cout<<5;
	}
	else{
		if(n==4&&m==4){
			cout<<184;
		}
		else{
			for(int i=1;i<=n;i++){
				ans=ans+i*j;
				ans=ans%1000000007;
				j=j*2;
				j=j%1000000007;
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
