#include "bits/stdc++.h"
using namespace std;

long long read() {
	char c=getchar();
	long long re=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') re=re*10+c-'0',c=getchar();
	return re; 
}

unsigned long long n,q;
unsigned long long a[250010],b[250010];

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	int T=read();
	
	n=read();
	for (int i=1;i<=n;i++) {
		a[i]=read();
	}
	for (int i=1;i<=n;i++) {
		b[i]=read();
	}
	q=read();
	for (int i=1;i<=q;i++) {
		unsigned long long ans=0;
		int l=read(),r=read();
		for (int p=l;p<=r;p++) {
			for (int q=l;q<=r;q++) {
				unsigned long long ma=0,mb=0;
				for (int t=p;t<=q;t++) {
					ma=max(ma,a[t]),mb=max(mb,b[t]);
				}
				ans+=ma*mb;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
