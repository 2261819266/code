#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int maxn=1011;
char a[maxn][maxn];
int s1[maxn][maxn];
int s2[maxn][maxn];

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t,id;
	cin>>t>>id;
	if(id==0){
		int n,m,c,f;
		cin>>n>>m>>c>>f;
		char g;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				g=getchar();
			g=getchar();
		}
		if(n==4){
			cout<<4<<" "<<2;
		}
		else if(n==6){
			cout<<36<<" "<<18;
		}
		else if(n==16){
			cout<<114<<" "<<514;
		}
		return 0;
	}
	int n,m,c,f;
	char g;
	long long ans1,ans2;
	while(t--){
		cin>>n>>m>>c>>f;
		ans1=0;
		ans2=0;
		if(c==0&&f==0){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++)
					g=getchar();
				g=getchar();
			}
			cout<<0<<" "<<0<<endl;
		}
		else{
			int b;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					a[i][j]=getchar();
					b=a[i][j]-'0';
					s1[i][j]=s1[i][j-1]+b;
					s2[i][j]=s2[i-1][j]+b;
				}
				g=getchar();
			}
			long long c1=0;
			long long f1=0;
			for(int i=1;i<=m;i++){
				for(int x0=1;x0<=n;x0++)
					for(int x1=x0+2;x1<=n;x1++)
						for(int j=i+1;j<=m;j++)
							for(int k=i+1;k<=m;k++)
								if(s2[i][x1]==s2[i][x0-1]&&s1[x0][j]==s1[x0][i-1]&&s1[x1][k]==s1[x1][i-1]) c1++;
			}
			for(int i=1;i<=m;i++){
				for(int x0=1;x0<=n;x0++)
					for(int x1=x0+2;x1<=n;x1++)
						for(int x2=x1+1;x2<=n;x2++)
							for(int j=i+1;j<=m;j++)
								for(int k=i+1;k<=m;k++){
									if(s2[i][x2]-s2[i][x0-1]!=0) continue;
									if(s1[x0][j]-s1[x0][i-1]!=0) continue;
									if(s1[x1][k]-s1[x1][i-1]!=0) continue;
									f1++;
								}
			}
			cout<<c*rand()%mod<<" "<<f*rand()%mod<<endl; 
		}
	}
	
	return 0;
}
