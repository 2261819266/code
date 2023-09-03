#include <bits/stdc++.h>
using namespace std;
const int N=1005;
const long long p=998244353;
int T,n,m,c,f,id,d[N][N],l[N][N],cntg[N][N],cnd[N][N];
string s[N];
long long anc,anf;
inline int read(){
	int x=0; char ch;
	bool bz=0;
	while(((ch=getchar())<'0'||ch>'9')&&ch!='-') ;
	if(ch=='-') bz=1;
	else x=(x<<1)+(x<<3)+(ch^48);
	while((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48);
	return bz?-x:x;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		n=read(),m=read(),c=read(),f=read(),anc=anf=0;
		for(register int i=1;i<=n;i++){
			cin>>s[i];
			s[i]="0"+s[i];
			d[i][m+1]=0;
			for(register int j=m;j>=1;j--) d[i][j]=(s[i][j]=='0'?d[i][j+1]+1:0);
		}
		for(register int i=1;i<=m;i++){
			l[n+1][i]=0;
			for(register int j=n;j>=1;j--) l[j][i]=(s[j][i]=='0'?l[j+1][i]+1:0);
		}
		if(n*n*m<=5000000||(c==0&&f==0)){
			if(c==0) printf("0");
			else{
				for(register int i=1;i<=m;i++){
					for(register int j=1;j<=n-2;j++){
						if(d[j][i]>1&&s[j+1][i]!='1'&&s[j+2][i]!='1'){
							long long g=0;
							for(register int k=j+2;k<=n;k++){
								if(s[k][i]=='1') break;
								g=g+d[k][i]-1;
							}
//							cout<<i<<" "<<j<<" "<<g*(d[j][i]-1)<<"\n";
							anc=(anc+g*(d[j][i]-1)%p)%p;
						}
					}
				}
				printf("%lld",(anc%p+p)%p);
			}
			if(f==0) puts(" 0");
			else{
				for(register int i=1;i<=m;i++){
					for(register int j=1;j<=n-2;j++){
						if(d[j][i]>1&&s[j+1][i]!='1'&&s[j+2][i]!='1'){
							long long g=0;
							for(register int k=j+2;k<=n;k++){
								if(s[k][i]=='1') break;
								g=(g+(d[k][i]-1)*(l[k][i]-1)%p)%p;
							}
							anf=(anf+g*(d[j][i]-1)%p)%p;
						}
					}
				}
				printf(" %lld\n",(anf%p+p)%p);
			}
		}
		else{
			for(register int i=1;i<=m;i++){
				cntg[0][i]=0;
				for(register int j=1;j<=n;j++) cntg[j][i]=cntg[j-1][i]+(s[j][i]=='1');
			}
			for(register int i=1;i<=m;i++){
				cnd[0][i]=0;
				for(register int j=1;j<=n;j++) cnd[j][i]=cnd[j-1][i]+d[j][i];
			}
			if(c==0) printf("0");
			else{
				for(register int i=1;i<=m;i++){
					for(register int j=1;j<=n-2;j++){
						if(d[j][i]>1&&s[j+1][i]!='1'&&s[j+2][i]!='1'){
							int l=j+2,r=n;
							while(l<=r){
								int mid=(l+r)/2;
								if(cntg[mid][i]-cntg[j-1][i]==0) l=mid+1;
								else r=mid-1;
							}
							long long g=(cnd[r][i]-cnd[j+1][i])-r+j+1;
//							cout<<i<<" "<<j<<" "<<g*(d[j][i]-1)<<"\n";
							anc=(anc+g*(d[j][i]-1)%p)%p;
						}
					}
				}
				printf("%lld",(anc%p+p)%p);
			}
			for(register int i=1;i<=m;i++){
				cnd[0][i]=0;
				for(register int j=1;j<=n;j++){
					cnd[j][i]=(cnd[j-1][i]+(d[j][i]-1)*(l[j][i]-1)%p)%p;
				}
			}
			if(f==0) puts(" 0");
			else{
				for(register int i=1;i<=m;i++){
					for(register int j=1;j<=n-2;j++){
						if(d[j][i]>1&&s[j+1][i]!='1'&&s[j+2][i]!='1'){
							int l=j+2,r=n;
							while(l<=r){
								int mid=(l+r)/2;
								if(cntg[mid][i]-cntg[j-1][i]==0) l=mid+1;
								else r=mid-1;
							}
							long long g=cnd[r][i]-cnd[j+1][i];
							anf=(anf+g*(d[j][i]-1)%p)%p;
						}
					}
				}
				printf(" %lld\n",(anf%p+p)%p);
			}
		}
	}
	return 0;
}
