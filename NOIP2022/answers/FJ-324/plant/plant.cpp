#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int T,id;
int n,m,f,c;
bool mp[1010][1010];
char ch;

int lst;
long long rig[1010][1010];
long long rigd[1010][1010];
long long dow[1010][1010];
long long ans_c=0,ans_f=0;

int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		ans_c=0,ans_f=0;
		scanf("%d %d %d %d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ch=getchar();
				while(ch!='0' && ch!='1') ch=getchar();
				mp[i][j]=ch-'0';
				rig[i][j]=rigd[i][j]=dow[i][j]=0;
			}
		}
		
		for(int i=1;i<=n;i++){
			lst=m+1;
			for(int j=m;j>=1;j--){
				if(mp[i][j]) lst=j,rig[i][j]=0;
				else rig[i][j]=lst-j-1;
			}
		}
		for(int j=1;j<=m;j++){
			lst=n+1;
			for(int i=n;i>=1;i--){
				if(mp[i][j]) lst=i,dow[i][j]=0;
				else dow[i][j]=lst-i-1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				rigd[i][j]=(rig[i][j]*dow[i][j])%MOD;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				rig[i][j]+=rig[i-1][j];
				rig[i][j]%=MOD;
				rigd[i][j]+=rigd[i-1][j];
				rigd[i][j]%=MOD;
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!mp[i][j] && dow[i][j]>=2)
				{
					ans_c+=((rig[i][j]-rig[i-1][j])%MOD)*((rig[i+dow[i][j]][j]-rig[i+1][j])%MOD)%MOD;
					ans_c%=MOD;
					ans_f+=((rig[i][j]-rig[i-1][j])%MOD)*((rigd[i+dow[i][j]][j]-rigd[i+1][j])%MOD)%MOD;
					ans_f%=MOD;
				}
			}
		}
		printf("%lld %lld\n",(c*ans_c)%MOD,(f*ans_f)%MOD);
	}
	return 0;
}
/*
rp++ 
让我A吧  求求你了 
		by 吴含章 hispy 
		2022.11.26
*/
