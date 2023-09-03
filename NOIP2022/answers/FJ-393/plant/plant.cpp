#include<bits/stdc++.h>
using namespace std;
int t,id,n,m,c,f;
bool a[1005][1005];
int xx[1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--){
		cin>>n>>m>>c>>f;
		memset(a,0,sizeof(a));
		if(c==0&&f==0){cout<<"0 0"<<endl;}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					char ch;
					cin>>ch;
					if(ch=='1'){
						a[i][j]=1;
					}
				}
			}long long ansc=0,ansf=0,mod=998244353;
			for(int i=1;i<n;i++){
				for(int j=1;j<m;j++){
					int top=0;
					if(a[i][j]||a[i][j+1]||a[i+1][j]||a[i+2][j])	continue;
					for(int y=i;!a[y][j]&&y<=n;y++){
						int x=j;
						while(a[y][x]==0&&x<m)	x++;
						while(a[y][x]||x>m)	x--;
						xx[++top]=x-j;
					}for(int p=1;p+2<=top;p++){
						for(int l=p+2;l<=top;l++){
							ansc=(ansc+xx[p]*xx[l])%mod;
							ansf=(ansf+xx[p]*xx[l]*(top-l))%mod;
						}
					}
				}
			}cout<<ansc*c<<" "<<ansf*f<<endl;
		}
	}
	return 0;
}
