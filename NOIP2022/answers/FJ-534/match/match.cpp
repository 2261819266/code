#include<bits/stdc++.h>
using namespace std;
int x[250020];
int y[250020];
/*
0 2
2 1
1 2
1
1 2

*/
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	cin>>T>>n;
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)scanf("%d",&y[i]);
	int Q;
	cin>>Q;
	for(int ii=1;ii<=Q;ii++){
		unsigned long long ans=0;
		int l,r;
		scanf("%d%d",&l,&r);
		for(unsigned long long i=l;i<=r;i++){
			for(unsigned long long j=i;j<=r;j++){
				unsigned long long maxx1=0,maxx2=0;
				for(int k=i;k<=j;k++){
					if(x[k]>maxx1)maxx1=x[k];
					if(y[k]>maxx2)maxx2=y[k];
				}
				ans=ans+maxx1*maxx2;
			}
		}
		cout<<ans;
	}
	
	
	return 0;
}
