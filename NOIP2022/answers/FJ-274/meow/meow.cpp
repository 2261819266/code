#include<bits/stdc++.h>
using namespace std;
vector<int> v[4],op[4];
int t,n,m,k,a[1050],vp[4]={0};
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i];
	if(n==2){
		v[1].push_back(a[1]);
		op[1].push_back(1);
		op[2].push_back(1);
		op[3].push_back(0);
		vp[1]++;
		for(int i=2;i<=m;i++){
			if(vp[2]>0){
				if(v[1][vp[1]-1]==v[2][vp[2]-1]){
					op[1].push_back(2);
					op[2].push_back(1);
					op[3].push_back(2);
					vp[1]++,vp[2]++;
				}
			}
			else{
				op[1].push_back(1);
				op[2].push_back(2);
				op[3].push_back(0);
				vp[2]++;
			}
			if(a[i]==v[1][vp[1]]){
				op[1].push_back(1);
				op[2].push_back(1);
				op[3].push_back(0);
				vp[1]++;
			}
			if(a[i]==v[2][vp[2]]){
				op[1].push_back(1);
				op[2].push_back(2);
				op[3].push_back(0);
				vp[1]++;
			}
		}
		cout<<op[1].size()<<endl;
		for(int i=0;i<op[1].size();i++){
			cout<<op[1][i]<<" "<<op[2][i];
			if(op[3][i]!=0) cout<<" "<<op[3][i];
			cout<<endl;
		}
	}
	}
	return 0;
}
