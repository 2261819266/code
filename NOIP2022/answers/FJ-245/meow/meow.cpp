#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k;
int cnt,ans;
int a[1000007];
int s1[1000007],s2[1000007];
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
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	for(int i=1; i<=t; i++) {
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		n=read();
		m=read();
		k=read();
		for(int i=1; i<=m; i++) a[i]=read();
		if(n==2) {
			int cnt=1;
			cout<<m<<endl;
			for(int i=1; i<=m; i++) {
				if(a[i]==s1[cnt]) {
					cout<<'1'<<' '<<'1'<<endl;
					cnt--;
				} else if(a[i]==s2[cnt]) {
					cout<<'1'<<' '<<'2'<<endl;
					cnt--;
				}
				else if(a[i]!=s1[cnt] && a[i]!=s2[cnt] && a[i+1]!=s1[cnt] && a[i+1]!=s2[cnt]){
					cout<<'1'<<' '<<'2'<<endl;
					s2[cnt++]=a[i];
				} 
				else if(a[i]!=s1[cnt] && a[i]!=s2[cnt] && a[i+1]==s1[cnt]) {
					cout<<'1'<<' '<<'2'<<endl;
					s2[cnt++]=a[i];
				} else if(a[i]!=s1[cnt] && a[i]!=s2[cnt] && a[i+1]==s2[cnt]) {
					cout<<'1'<<' '<<'1'<<endl;
					s1[cnt++]=a[i];
				}
			}
		}
	}
	return 0;
}
