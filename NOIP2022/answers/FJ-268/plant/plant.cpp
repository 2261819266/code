#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int t,idd,n,m,c,f,flg,cnt,w[1005][1005],h[1005][1005],dpc[1005][1005],dpf[1005][1005];
long long ansc,ansf,sum;
char a[1005][1005];
inline int read(){
	int x=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*ff;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();
	idd=read();
	while(t--){
		n=read(),m=read(),c=read(),f=read();
		ansc=ansf=0;
		for(int i=1;i<=n;++i){
			flg=cnt=0;
			scanf("%s",a[i]+1);
			for(int j=1;j<=m;++j){
				if(a[i][j]=='1'){
					if(flg){
						for(int k=flg;k<j;++k){
							w[i][k]=cnt--;
						}
						flg=0;
					}
					w[i][j]=0;
				}else{
					if(!flg){
						flg=j;
					}
					cnt++;
				}
			}
			if(flg){
				for(int k=flg;k<=m;++k){
					w[i][k]=cnt--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			flg=cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i][j]=='1'){
					if(flg){
						for(int k=flg;k<i;++k){
							h[k][j]=cnt--;
						}
						flg=0;
					}
					h[i][j]=0;
				}else{
					if(!flg){
						flg=i;
					}
					cnt++;
				}
			}
			if(flg){
				for(int k=flg;k<=n;++k){
					h[k][j]=cnt--;
				}
			}
		}
		for(int j=1;j<=m;j++){
			cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i][j]=='1'){
					cnt=0;
				}else{
					if(w[i][j]>1){
						if(w[i-1][j]>1){
							sum=1ll*(w[i][j]-1)*(cnt+1-w[i-1][j])%mod;
							ansc=(ansc+sum)%mod;
						}else{
							if(cnt){
								sum=1ll*(w[i][j]-1)*cnt%mod;
								ansc=(ansc+sum)%mod;
							}else{
								sum=0;
							}
						}
						cnt+=w[i][j]-1;
						ansf=(ansf+1ll*h[i+1][j]*sum%mod)%mod;
					}
				}
			}
		}
		printf("%lld %lld\n",1ll*c*ansc,1ll*f*ansf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
