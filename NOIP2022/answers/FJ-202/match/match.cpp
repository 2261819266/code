#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
#define ull unsigned long long
struct ST{
	ull c[300090][21];
	int n;
	void begin(int nn){
		n=nn;
		for(int k=1;k<21;k++){
			int len=1<<k;
			for(int i=1;i+len<=n;i++){
				c[i][k]=max(c[i][k-1],c[i+(len>>1)][k-1]);
			}
		}
	}
	ull ask(int l,int r){
		int d=log2(r-l+1);
		//out<<c[l][d]<<endl;
		return max(c[l][d],c[r-(1<<d)+1][d]);
	}
}a,b;
ull x;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T>>n;
	for(int i=1;i<=n;i++){
		cin>>x;a.c[i][0]=x;
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		b.c[i][0]=x;
	}
	a.begin(n),b.begin(n);
	int q;
	cin>>q;
	ull ans=0;
	while(q--){
		int l,r;
		cin>>l>>r;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				ans+=a.ask(i,j)*b.ask(i,j);
				cout<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

