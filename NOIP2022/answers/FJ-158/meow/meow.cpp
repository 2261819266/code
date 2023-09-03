#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=2e6+5;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

struct node{
	int opt,x,y;
}ans[M<<1];

int a[M],n,m,k;
int s[N],tot,b[N],c[N],q[N];
vector<int>p[N],st[N];

void insert(int x){
	int f=0;
	if(st[n].size()){
		for(int j=1;j<n;j++)
			if(st[j].size()==1){st[j].push_back(x);ans[++tot].opt=1;ans[tot].x=j;}
		return;
	}for(int j=1;j<n;j++){
		int tp=st[j].size();
		if(tp<2||(c[st[j][0]]<c[st[j][1]]&&tp<=2)){st[j].push_back(x),f=1;ans[++tot].opt=1;ans[tot].x=j;f=1;return;}
	}if(!f){st[n].push_back(x);ans[++tot].opt=2;ans[tot].x=n;}
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();while(T--){tot=0;
		memset(q,0,sizeof(q));
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++)a[i]=read(),p[a[i]].push_back(i);
		if(k==((n-1)<<1)){
			for(int i=1;i<=m;i++){a[i]++;
//				printf("%d %d %d\n",i,s[a[i]],s[a[i]^1]);
				if(!s[a[i]^1]&&!s[a[i]]){ans[++tot].opt=1;ans[tot].x=(a[i]>>1);s[a[i]]=1;}
				else if(!s[a[i]^1]&&s[a[i]]){ans[++tot].opt=1;ans[tot].x=(a[i]>>1);s[a[i]]=0;}
				else if(s[a[i]^1]&&!s[a[i]]){ans[++tot].opt=1;ans[tot].x=(a[i]>>1);s[a[i]]=2;}
				else {
					if(s[a[i]]==2){ans[++tot].opt=1;ans[tot].x=(a[i]>>1);s[a[i]]=0;}
					else {
						ans[++tot].opt=1;ans[tot].x=n;ans[++tot].opt=2;
						ans[tot].x=(a[i]>>1);ans[tot].y=n;
						s[a[i]]=0;s[a[i]^1]=1;
					}
				}
			}
		}else {
			for(int i=1;i<=m;i++){
				++q[a[i]];
				if(!b[i])c[i]=p[a[i]][q[a[i]]],b[p[a[i]][q[a[i]]]]=1;
			}for(int i=1;i<=m;i++){
				if(!b[i])insert(i);
				else {
					if(st[n].size()){
						for(int j=1;j<=n;j++){
							if(st[i].size()&&c[st[i][st[i].size()-1]]==j){
								st[i].erase(--st[i].end());ans[++tot].opt=1;ans[tot].x=j;
							}
						}
					}else {int f=0;
						for(int j=1;j<n;j++){
							if(st[i].size()&&c[st[i][st[i].size()-1]]==j){
								st[i].erase(--st[i].end());ans[++tot].opt=1;ans[tot].x=j;f=1;
							}
						}if(!f){
							for(int j=1;j<n;j++){
								if(c[st[i].size()&&st[i][0]]==j){
									ans[++tot].opt=2;ans[tot].x=j;ans[tot].y=n;
								}
							}
						}
					}
				}
			}
		}printf("%d\n",tot);
		for(int i=1;i<=tot;i++){
			if(ans[i].opt==1){
				printf("1 %d\n",ans[i].x);
			}else printf("2 %d %d\n",ans[i].x,ans[i].y);
		}for(int i=1;i<=k;i++)p[a[i]].clear();
	}
}
