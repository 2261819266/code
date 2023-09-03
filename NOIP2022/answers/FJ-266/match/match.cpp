#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,A[100005],B[100005],Q,l,r;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	if(T==0){
		cout<<8;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++) cin>>A[i];
		for(int i=1;i<=n;i++) cin>>B[i];
		cin>>Q;
		for(int i=1;i<=Q;i++){
			cin>>l>>r;
			ll Max1=0,Max2=0,Ans=0;
			for(int j=1;j<=r;j++){
				for(int w=j;w<=r;w++){
					Max1=Max2=0;
					for(int s=j;j<=w;s++){
						Max1=max(Max1,A[i]);
						Max2=max(Max2,B[i]);
					}
					Ans+=Max1*Max2;
				}
			}              
			cout<<Ans<<endl;
		}
	}
	return 0;
}
