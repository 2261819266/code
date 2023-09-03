#include<bits/stdc++.h>
using namespace std;
int T,n,a[250005],b[250005],ans,Q,min_ans=1<<30,min_ansgs;
//long long mod=2<<32;
long long jc(int x,int y){
//	cout<<"x="<<x<<" y="<<y<<endl;
	for(int i=x;i<=y;i++){
		for(int j=x;j<=y;j++){
			int s;
			s=a[i]*b[j];
//			cout<<"a["<<i<<"]="<<a[i]<<" b["<<j<<"]="<<b[j]<<endl;
			ans+=s;
//			cout<<"s="<<s<<" ";
			if(min_ans==s)min_ansgs++;
			if(min_ans>s){
				min_ans=s;
				min_ansgs=1;
			}
		}
	}
	ans=ans-min_ans*min_ansgs;
//	ans%=mod;
	return ans;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdin);	
	cin>>T>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];	
	cin>>Q;
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		cout<<jc(x,y)<<endl;
	}
	return 0;
}
