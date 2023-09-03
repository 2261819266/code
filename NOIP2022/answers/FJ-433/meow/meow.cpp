#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ac=getchar();
	while(ac<'0'||ac>'9'){
		if(ac=='-') f=-1;
		ac=getchar();
	}
	while(ac>='0'&&ac<='9'){
		x=(x<<3)+(x<<1)+(ac-'0');
		ac=getchar();
	}
	return x*f;
}
int t,n,m,k,cnt[305],nxt[2000005],now[605],a[2000005];
int vis[605];
struct node{
	int sum,from;
}ac[305][10];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--){
		memset(cnt,0,sizeof(cnt));
		memset(ac,0,sizeof(ac));
		memset(nxt,0,sizeof(nxt));
		memset(now,0,sizeof(now));
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++){
			a[i]=read();
			if(!vis[a[i]]){
				vis[a[i]]=i;
			}
			else{
				nxt[vis[a[i]]]=i;
				vis[a[i]]=0;
			}
		}
		if(n==1){
			for(int i=1;i<=m;i++){
				printf("1 1\n");
			}
			continue;
		}
		nxt[0]=0x3f3f3f3f;
		for(int i=1;i<=m;i++){
			if(!nxt[i]){
				int num=now[a[i]];
				cnt[num]--;
				printf("1 %d\n",num);
			}
			else{
				bool p=false;
				for(int j=1;j<=n;j++){
					if(cnt[j]==0){
						cnt[j]++;
						ac[j][cnt[j]].from=i;
						ac[j][cnt[j]].sum=a[i];
						now[a[i]]=j;
						printf("1 %d\n",j);
						p=true;
						break;
					}
				}
				if(p) continue;
				for(int j=1;j<=n;j++){
					if(nxt[i]<nxt[ac[j][cnt[j]].from]){
						cnt[j]++;
						ac[j][cnt[j]].from=i;
						ac[j][cnt[j]].sum=a[i];
						now[a[i]]=j;
						printf("1 %d\n",j);
						break;
					}
				}
			}
		}
	}
	return 0;
}
