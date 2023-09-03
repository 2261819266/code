#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5+5;
int t,n,q,a[N],b[N],logg[N],maxa[2*N][21],maxb[2*N][21];
unsigned long long ans;
int qqqa(int l,int r){
	int t=logg[r-l+1];
	return max(maxa[l][t],maxa[r-(1<<t)+1][t]);
}
int qqqb(int l,int r){
	int t=logg[r-l+1];
	return max(maxb[l][t],maxb[r-(1<<t)+1][t]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t>>n;
	for(int i=1;i<=n;++i){
		logg[i]=log(i)/log(2);
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxa[i][0]=a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		maxb[i][0]=b[i];
	}
//	cout<<logg[n]<<endl;
	for(int i=1;i<=int(logg[n]);++i){
		for(int j=1;j<=n;++j){
			
			maxa[j][i]=max(maxa[j][i-1],maxa[j+(1<<i)-(1<<(i-1))][i-1]);
			maxb[j][i]=max(maxb[j][i-1],maxb[j+(1<<i)-(1<<(i-1))][i-1]);
		}
	}
	
	cin>>q;
	while(q--){
		int l,r;
//		dd(l),dd(r);
		ans=0;
		cin>>l>>r;
		for(int p=l;p<=r;++p){
			for(int q=p;q<=r;++q){
//				cout<<p<<q<<endl;
//				cout<<qqqa(p,q)<<" "<<qqqb(p,q)<<endl;;
				ans+=(unsigned long long)qqqa(p,q)*(unsigned long long)qqqb(p,q);
			}
		}
//		printf("%Ld",ans);
		cout<<ans<<endl;
	}
}
