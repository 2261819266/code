#include <iostream>
#include <cstdio>
using namespace std;
long long ans=0;
int T,n,a[250001],b[250001],Q;
long long LONGM (){
	long long sdf=2;
	return sdf*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2*2;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin >> T >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];
	cin >> Q;
	for (int i=1;i<=Q;i++){
		int l,r;
		cin >> l >> r;
		for (int p=l;p<=r;p++){
			for (int q=p;q<=r;q++){
				int max1=-1,max2=-1;
				for (int j=p;j<=q;j++){
					if (a[j]>max1) max1=a[j];
					if (b[j]>max2) max2=b[j];
				}
				ans+=max1*max2;
				if (ans<0||ans==LONGM()){
					ans-=LONGM();
				}
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
