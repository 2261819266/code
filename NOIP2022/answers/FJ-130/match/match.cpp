#include <bits/stdc++.h>
using namespace std;
long long f1[250010][20],f2[250010][20];
int lg[250010];
unsigned long long mod=1844674407370955161;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n; cin>>T>>n; lg[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>f1[i][0];
		if((i&(i-1))==0)
			lg[i]=lg[i-1]+1;
		else lg[i]=lg[i-1];
	}
	for(int i=1;i<=n;i++)
		cin>>f2[i][0];
	for(int j=1;j<=lg[n];j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f1[i][j]=max(f1[i][j-1],f1[(i+(1<<(j-1)))][j-1]);
			f2[i][j]=max(f2[i][j-1],f2[(i+(1<<(j-1)))][j-1]);
		}
	}
	int Q; cin>>Q;
	while(Q--){
		int l,r; cin>>l>>r;
		unsigned long long ans=0;
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				int len=lg[q-p+1];
				long long m1,m2;
				m1=max(f1[p][len],f1[q-(1<<len)+1][len]);
				m2=max(f2[p][len],f2[q-(1<<len)+1][len]);
				ans=(ans+((m1*m2)%mod))%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
