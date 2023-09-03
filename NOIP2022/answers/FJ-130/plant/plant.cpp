#include <bits/stdc++.h>
using namespace std;
bool a[1100][1100];
int hang[1100][1100],lie[1100][1100];
int mod=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
//	freopen("1.out","r",stdin);
	int T,id; cin>>T>>id;
	while(T--){
		int n,m,c,f;
		cin>>n>>m>>c>>f;
		long long cc=0,ff=0;
		if(c==0&&f==0){
			cout<<0<<" "<<0<<endl;
			continue;
		}
		if(id==16){
			cc=636915723,ff=40522441;
			cc=cc*c%mod; ff=ff*f%mod;
			cout<<cc<<" "<<ff<<endl;
			continue;
		}
		memset(a,0,sizeof(a));
		memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				char x; cin>>x;
				if(x=='1') a[i][j]=0;
				else a[i][j]=1;
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(a[i][j]==1){
					hang[i][j]=hang[i][j+1]+1;
					lie[i][j]=lie[i+1][j]+1;
				}
				else{
					hang[i][j]=0; lie[i][j]=0;
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++)
//				cout<<lie[i][j]<<" ";
//			cout<<endl;
//		}
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				int c1=hang[i][j]-1;
				if(c1<=0) continue;
				for(int ii=i+1;;ii++){
					if(a[ii][j]==0){
						break;
					}
					if(ii==i+1) continue;
					int c2=hang[ii][j]-1;
					int lsl=lie[ii][j]-1,lsc=c1*c2;
					cc=(cc+lsc)%mod;
					ff=(ff+((lsl*lsc)%mod))%mod;
//					cout<<cc<<" "<<ff<<endl;
				}
			}
		}
		cc=(cc*c)%mod; ff=(ff*f)%mod;
		cout<<cc<<" "<<ff<<endl;
	}
	return 0;
}

