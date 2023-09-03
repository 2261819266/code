#include<bits/stdc++.h>
using namespace std;
inline void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;	
}
const int N=2000101;
int t,n,m,k,a,wei[N];
int l,r,kong[N];
int who[N];
int ans,op[N],s[N],sx[N];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	dd(t);
	if(t==1001||t==2){
		while(t--){
			dd(n),dd(m),dd(k);
			l=r=ans=0;
			for(int i=1;i<=k;++i)wei[i]=who[i]=0;
			for(int i=1;i<n*2-1;++i)
			kong[++r]=i+1;
			for(int i=1;i<=m;++i){
				dd(a);
				if(wei[a]==0){
					op[++ans]=1;
					s[ans]=kong[++l]/2;
					wei[a]=kong[l];
					who[kong[l]]=a;
				}
				else if(wei[a]&1){
					op[++ans]=1;
					s[ans]=wei[a]/2;
					kong[++r]=wei[a];
					who[wei[a]]=0;
					wei[a]=0;
				}
				else{
					op[++ans]=1;
					s[ans]=n;
					op[++ans]=2;
					s[ans]=n;
					sx[ans]=wei[a]/2;
					int sh=who[wei[a]-1];
					who[wei[a]-1]=0;
					who[wei[a]]=1;
					kong[++r]=wei[a]-1;
					wei[a]=0;
				}
			}
			printf("%d\n",ans);
			for(int i=1;i<=ans;++i){
				printf("%d %d",op[i],s[i]);
				if(op[i]==2)printf(" %d\n",sx[i]);
				else puts("");
			}
		}
		return 0;
	}
	if(n==2){
		int zuo[2],you[2];
		while(t--){
			dd(n),dd(m),dd(k);
			ans=0,zuo[0]=zuo[1]=you[0]=you[1]=0;
			for(int i=1;i<=m;++i){
				dd(a);
				if(zuo[1]==a){
					op[++ans]=1;
					s[ans]=1;
					zuo[1]=0;
				}
				else if(you[1]==a){
					op[++ans]=1;
					s[ans]=2;
					you[1]=0;
				}
				else if(you[1]==0&&zuo[0]==a){
					op[++ans]=1;
					s[ans]=2;
					op[++ans]=2;
					s[ans]=1;
					sx[ans]=2;
					zuo[0]=zuo[1];
					zuo[1]=0;
				}
				else if(zuo[1]==0&&you[0]==a){
					op[++ans]=1;
					s[ans]=1;
					op[++ans]=2;
					s[ans]=1;
					sx[ans]=2;
					you[0]=you[1];
					you[1]=0;
				}
				else
				op[++ans]=1,s[ans]=1,zuo[0]=a;
			}
			printf("%d\n",ans);
			for(int i=1;i<=ans;++i){
				printf("%d %d",op[i],s[i]);
				if(op[i]==2)printf(" %d\n",sx[i]);
				else puts("");
			}
		}
		return 0;
	}
	while(t--){
		int jc=0;
		dd(n),dd(m),dd(k);
		l=r=ans=0;
		for(int i=1;i<=k;++i)wei[i]=who[i]=0;
		for(int i=1;i<n*2-1;++i)
		kong[++r]=i+1;
		for(int i=1;i<=m;++i){
			dd(a);
			if(wei[a]==0){
				if(l>=r){
					if(jc==a){
						op[++ans]=1;
						s[ans]=1;
						op[++ans]=1;
						s[ans]=1;
						jc=0;
					}
					else jc=a;
				}
				else{
					op[++ans]=1;
					s[ans]=kong[++l]/2;
					wei[a]=kong[l];
					who[kong[l]]=a;
				}
			}
			else if(wei[a]&1){
				if(jc){
					op[++ans]=1;
					s[ans]=n;
					wei[jc]=n*2;
					who[n*2]=jc;
					jc=0;
				}
				op[++ans]=1;
				s[ans]=wei[a]/2;
				kong[++r]=wei[a];
				who[wei[a]]=0;
				wei[a]=0;
			}
			else{
				if(jc){
					op[++ans]=1;
					s[ans]=wei[a]-1;
				}
				op[++ans]=1;
				s[ans]=n;
				op[++ans]=2;
				s[ans]=n;
				sx[ans]=wei[a]/2;
				int sh=who[wei[a]-1];
				who[wei[a]-1]=0;
				who[wei[a]]=1;
				if(!jc)
				kong[++r]=wei[a]-1;
				else
				who[wei[a]]=jc,wei[jc]=wei[a],jc=0;
				wei[a]=0;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;++i){
			printf("%d %d",op[i],s[i]);
			if(op[i]==2)printf(" %d\n",sx[i]);
			else puts("");
		}
	}
}
