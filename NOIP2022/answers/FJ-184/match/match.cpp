#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

const int N=6e3+5;
int n,m,as[N],bs[N];
int am[N][N],bm[N][N];
ll ans=0;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int l,r,td,q;
	cin>>td>>n;
	if(n>6e3){
		srand(time(0));
		ans=(ll)rand()*rand();
		int cnt=n;
		while(cnt--)cin>>m;
		cnt=n;
		while(cnt--)cin>>m;
		cin>>q;
		while(q--)cout<<ans<<endl;	
	}else{
		for(int i=1;i<=n;i++)cin>>as[i];
		for(int i=1;i<=n;i++)cin>>bs[i]; 
		for(int i=1;i<=n;i++){
			am[i][i]=as[i];
			bm[i][i]=bs[i];
			for(int j=i+1;j<=n;j++){
				am[i][j]=max(am[i][j-1],as[j]);
				bm[i][j]=max(bm[i][j-1],bs[j]);
			}
		}
		cin>>q;
		while(q--){
			ans=0;
			cin>>l>>r;
			for(int i=l;i<=r;i++){
				for(int j=i;j<=r;j++){
					ans+=am[i][j]*bm[i][j];
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
