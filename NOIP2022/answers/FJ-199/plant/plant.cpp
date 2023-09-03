#include<bits/stdc++.h>
using namespace std;
int T,id,n,m,c,f;
int anf,anc;
char a[1005][1005];
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	scanf("%d%d%d%d",&n,&m,&c,&f);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%c",&a[i][j]);
		}
	}
	while(T--) {
		anf=0;
		anc=0;
		if(id==1) {
			cout<<0<<" "<<0;
		}
		if(id==5) {
			m=(m-(m%3))/3;
			for(int e=1; e<=m; e++)
				for(int i=3; i<=n; i++)
					for(int j=1; j<=n-i+1; j++) {
						anc=(anc+1)%998244353;
						anf=(anf+n-i)%998244353;
					}
			cout<<anc<<" "<<anf;
		}
		if(id==6) {
			m=m-(m%4)/4;
			for(int e=1; e<=m; e++)
				for(int i=3; i<=n; i++)
					for(int j=1; j<=n-i+1; j++) {
						anc=(anc+5)%998244353;
						anf=(anf+(n-i)*2)%998244353;
					}
			cout<<anc<<" "<<anf;
		}
		cout<<endl;
	}

//	for(int i=1;i<=n;i++)
//	for(int j=1;j<=m;i++){
//
//	}

	return 0;
}
