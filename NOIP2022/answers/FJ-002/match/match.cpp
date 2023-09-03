#include <bits/stdc++.h>
using namespace std;
int main() {
	int x=pow(2,64);
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	long long T,n,a[250005],b[250005];
	std::cin>>T>>n;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		std::cin>>b[i];
	}
	int q,l,r;
	long long j=0,ll=0;
	std::cin>>q;
	int m1=-100,m2=-100;
	while(q--){
		std::cin>>l>>r;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				for(int k=i;k<=j;k++){
					if(m1<a[k]){
						m1=a[k]%x;
					}
				}
				for(int k=i;k<=j;k++){
					if(m2<b[k]){
						m2=b[k]%x;
					}
				}
				m1=m1*m2;
				ll+=m1;
				m1=-100;
				m2=-100;
			} 
		}
		std::cout<<ll<<endl;
		ll=0;
		j=0;
	}
	return 0;
}
