#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull N=3005,Max=0x3f3f3f3f3f3f3f3f;
ull id,n,a[N],b[N],nta[N],ntb[N],ans,mxa[N][N],mxb[N][N],cnt[N][N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
//	memset(nta,0x3f,sizeof(nta));
//	memset(ntb,0x3f,sizeof(ntb));
//	cout << nta[1] << " " << Max << endl;
	cin >> id >> n;
	for(register int i=1;i<=n;++i) cin >> a[i];
	for(register int i=1;i<=n;++i) cin >> b[i];
//	for(int i=1;i<=n;i++) cout << a[i] << endl; 
//	stack<int> st;
//	for(int i=n;i>=1;i--){
//		while(!st.empty() && a[st.top()]<a[i]) st.pop();
//		if(!st.empty()){
//			nta[i]=st.top();
//		}
//		st.push(i);
//		cout << st.size() << endl;
//	}
//	stack<int>().swap(st);
//	for(int i=n;i>=1;i--){
//		while(!st.empty() && b[st.top()]<b[i]) st.pop();
//		if(!st.empty()){
//			ntb[i]=st.top();
//		}
//		st.push(i);
//		cout << st.size() << endl;
//	}
	for(register int i=1;i<=n;++i){
		for(register int j=i;j<=n;++j){
			mxa[i][j]=max(mxa[i][j-1],a[j]);
			mxb[i][j]=max(mxb[i][j-1],b[j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt[i][j]=cnt[i][j-1]+mxa[i][j]*mxb[i][j];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		ull ans=0;
		for(register int i=l;i<=r;++i){
			ans+=cnt[i][r];
		}
		cout << ans << endl;
	}
//	for(int i=1;i<=n;i++) cout << nta[i] << " ";
//	cout << endl;
//	for(int i=1;i<=n;i++) cout << ntb[i] << " ";
//	cout << endl;
	return 0;
}
