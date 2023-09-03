#include <bits/stdc++.h>
using namespace std;
long long t,id,n,m,c,f;
long long tot_c=0,tot_f=0;
char grass[1005][1005];
const long long p=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&t,&id);
	while(t--){
	scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
	if(c==0&&f==0){
		printf("0 0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%c",&grass[i][j]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(grass[i][j]=='0'){
				for(int k1=i+1;k1<=n;k1++){
					if(grass[k1-1][j]=='1'){
						break;
					}
					if(grass[k1][j]=='0'){
						if(grass[i][j+1]=='0'&&grass[k1][j+1]=='0'){
							tot_c++;
						}
						for(int k2=j+1;k2<=m;j++){
							if(grass[k1][k2]=='0'||grass[j][k2]=='0'){
								tot_c++;
							}
						}
					}
				}
			}
		}
	}//ÅÐ¶ÏC
	memset(grass,0,sizeof(grass));
}
    if(c!=0&&p!=0){
    printf("%lld%lld",(tot_c*c)%p,(tot_f*f)%p);
}else if(f==0&&c==1){
	printf("%lld ",(tot_c*c)%p);
	printf("0");
}
	return 0;
}
