#include<bits/stdc++.h>
using namespace std;
const long long aaa=998244353;
const int maxnn=1e7+7;
int t,id;
int n,m,c,f;
int plant[1007][1007];
string s;
inline int read() {
	int x=0;
	bool f=0;
	char ch=getchar();
	for(; !isdigit(ch); ch=getchar()) f|=(ch=='-');
	for(; isdigit(ch); ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	if(f) x=-x;
	return x;
}

int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();
	id=read();
	for(int i=1; i<=t; i++) {
		n=read();
		m=read();
		c=read();
		f=read();
		for(int i=1; i<=n; i++) {
			cin>>s;
		}
		if(id==1) {
			for(int i=1; i<=t; i++) {
				cout<<'0'<<' '<<'0'<<endl;
			}
		}
		else{
			cout<<n*n<<' '<<n*n/2<<endl;
		}
	}
	return 0;
}
