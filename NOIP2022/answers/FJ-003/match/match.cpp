#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
streambuf* inbuf; 
ll qr(){
	char ch=inbuf->sbumpc();
	ll abs=0,sgn=1;
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			sgn=-sgn;
		}
		ch=inbuf->sbumpc();
	}
	while(ch<='9'&&ch>='0'){
		abs*=10;
		abs+=ch^48;
		ch=inbuf->sbumpc(); 
	}
	return sgn*abs; 
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	inbuf=cin.rdbuf();
	ll id=qr(),n=qr();
	vector<int>N;
	vector<int>O;
	for(register int i=0;i<n;i++){
		N.push_back(int(qr()));
	}
	for(register int i=0;i<n;i++){
		O.push_back(int(qr()));
	}
	int Q=qr();
	int o_max=0;
	int n_max=0;
	for(register int i=0;i<Q;i++){
		register ll ans=0;
		int l=qr()-1,r=qr()-1;
		for(register int p=l;p<=r;p++){
			for(register int q=p;q<=r;q++){
				o_max=max(o_max,O[q]);
				n_max=max(n_max,N[q]);
				ans+=o_max*n_max;
			}
			o_max=0;
			n_max=0;
		} 
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
