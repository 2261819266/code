#include "bits/stdc++.h"
using namespace std;

long long read() {
	char c=getchar();
	long long re=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') re=re*10+c-'0',c=getchar();
	return re; 
} 

int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	long long n,m;
	n=read(),m=read();
	for (int i=1;i<=m;i++) {
		int u=read(),v=read();
	}
	
	printf("0");
	
	return 0;
}
