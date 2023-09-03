#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=1010,M=2000010;
int vist[N],vish[N];
bool em[N];
int T,n,m,k,a[M],head[N],tail[N],g,st[N][N],ansl,ans[N][3];

int main(){
	freopen("meow.in","r",stdin);freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(vish,false,sizeof(vish));
		memset(vist,false,sizeof(vist));
		memset(st,0,sizeof(st));
		memset(head,0,sizeof(head));
		memset(tail,0,sizeof(tail));
		memset(em,true,sizeof(em));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++){scanf("%d",&a[i]);}
		int g=0;
		for(int i=1;i<=m;i++){
			if(vist[a[i]]){
				int id=vist[a[i]];
				ansl++;
				ans[ansl][0]=1;
				ans[ansl][1]=id;
				vist[a[i]]=0;
				tail[id]--;
				if(tail[id]==head[id]){vish[a[i]]=0;em[id]=true;}
				else vist[st[id][tail[id]]]=id;
			}else{
				if(vish[a[i]]){
					int id=vish[a[i]];
					ansl++;
					ans[ansl][0]=1;
					ans[ansl][1]=n;
					ansl++;
					ans[ansl][0]=2;
					ans[ansl][1]=id;
					ans[ansl][2]=n;
					vish[a[i]]=0;
					head[id]++;
					if(head[id]==tail[id]){vist[a[i]]=0;em[id]=true;}
					else vish[st[id][head[id]]]=id;
				}else if(g<n-1){
					int E=0;
					for(int j=1;j<n;j++){
						if(em[j]){E=j;break;}
					}
					ansl++;
					ans[ansl][0]=1;
					ans[ansl][1]=E;
					g++;
					st[E][++tail[E]]=a[i];
					vist[a[i]]=E;vish[a[i]]=E;
				}else{
					ansl++;
					ans[ansl][0]=1;
					ans[ansl][1]=1;
					vist[st[1][tail[1]]]=0;
					st[1][++tail[1]]=a[i];
					vist[st[1][tail[1]]]=1;
				}
			}
		}
		printf("%d\n",ansl);
		for(int i=1;i<=ansl;i++){
			if(ans[i][0]==1){
				printf("%d %d\n",ans[i][0],ans[i][1]);
			}else{
				printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
			}
		}
	}
	return 0;
}
