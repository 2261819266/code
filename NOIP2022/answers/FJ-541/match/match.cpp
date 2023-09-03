#include <bits/stdc++.h>
using namespace std;
int t,n,q,l,r,am,bm,s;//am，bm分别为对应队当前区间能力最大选手的能力值 
unsigned long long ans;
int a[250000],b[250000]; 
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout); 
	cin >> t >> n;
	for (int i=0;i<n;i++){scanf("%d",&a[i]);}
	for (int i=0;i<n;i++){scanf("%d",&b[i]);}
	cin >> q;
	for (int i=0;i<q;i++){
		scanf("%d%d",&l,&r);
		l--;r--;
		ans=0,s=0;
		for(int j=l;j<=r;j++){
			for (int k=j;k<=r;k++){
				am=0,bm=0;
				for (int o=j;o<=k;o++){
					if(am<a[o]){
						am=a[o];
					}
					if(bm<b[o]){
						bm=b[o];
					}
				}
				ans+=am*bm;
				if(ans>1152921504606846976){
					ans-=1152921504606846976;
					s++; 
				}
				if(s==16){
					s=0;
				}
			}
		}
		cout << s*1152921504606846976+ans << endl;
	}
	return 0;
}
