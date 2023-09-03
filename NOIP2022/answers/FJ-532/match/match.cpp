#include <bits/stdc++.h>
using namespace std;
unsigned long long T,n,Q,l,r,a[250005],b[250005],sum,mx1,mx2;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin >>T>>n;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int j=1;j<=n;j++) cin >>b[j];
	cin >>Q;
	while(Q--){
		cin >>l>>r;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				mx1=0;
				mx2=0;
				for(int k=i;k<=j;k++) mx1=max(mx1,a[k]);
				for(int k=i;k<=j;k++) mx2=max(mx2,b[k]);
				sum+=mx1*mx2;
			}
		}
		cout <<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
