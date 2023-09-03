#include<bits/stdc++.h>

using namespace std;
int zz,ans[10][5];
int cnt;
bool st[10][10];
int h[10],t[10];
vector<int>p[10];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T,n,m,k;
	cin>>T;
	int a;
	bool aaa;
	p[0].push_back(1);
	cout<<p[0].front();
	while(T--){
		zz=0;
		memset(ans,0,sizeof(ans));
		memset(h,0,sizeof(h));
		memset(t,0,sizeof(t));
		cin>>n>>m>>k;
		for(int i=0;i<m;i++){
			cin>>a;
			aaa=true;
			for(int j=0;j<3;j++){
				if(a==p[j].back()){
					ans[zz][0]=1;
					ans[zz++][1]=j;
					aaa=false;
					p[j].pop_back();
					break;
				}else if(a==p[j].back()){
					for(int k=0;k<3;k++){
						if(k!=j&&h[k]==t[k]){
							ans[zz][0]=1;
							ans[zz++][1]=k;
							ans[zz][0]=2;
							ans[zz][1]=j;
							ans[zz++][2]=k;
//							p[j].pop_front();
							aaa=false;
							break;
						}
					}
				}
				if(aaa&&t[j]-h[j]>3&&st[a]==false){
					p[j].push_back(a);
					ans[zz][0]=1;
					ans[zz++][1]=j+1;
				}
			}
		}
		for(int i=0;i<zz;i++){
			cout<<ans[i][0]<<" "<<ans[i][1];
			if(ans[i][0]==2)cout<<" "<<ans[i][3];
			cout<<endl;
		}
	}
}
