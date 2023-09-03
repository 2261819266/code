#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
int n,m,k;
const int N=4e6+10;
int a[N];
bool in[N];
int pos[N];
int stk[3][N/2],s[3],t[3];
int ans[N],op[N],a2[N];
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T=read();
	if(T%10!=2){
	
	   while(T--){
	   	    n=read();m=read();k=read();
			for(int i=1;i<=m;i++) a[i]=read();
			for(int i=1;i<=k;i++) in[i]=0;
			queue<int>q;
			for(int i=1;i<=2*(n-1);i++) q.push(i);
			int siz=0;
			for(int i=1;i<=m;i++){
				if(!in[a[i]]){
				   if(!q.size()) q.push(1);
				   int u=q.front();q.pop();	
				   in[a[i]]=1;
				   pos[a[i]]=u;
				   if(u>n-1) u-=n-1;
				   siz++;
				   op[siz]=1;ans[siz]=u;
				   //printf("1 %d\n",u);
				}
				else{
					int u=pos[a[i]];
					in[a[i]]=0;
					q.push(u);
					if(u>n-1){
						siz++;
				        op[siz]=1;ans[siz]=u-n+1;
						//siz++,printf("1 %d\n",u-n+1);
					}
					else{
				        op[++siz]=1;ans[siz]=n;
				        op[++siz]=2;ans[siz]=u;
						//printf("1 %d\n",n);
						//printf("2 %d %d\n",u,n);
					}
				}
			}
			printf("%d\n",siz);
			for(int i=1;i<=siz;i++){
				printf("%d %d ",op[i],ans[i]);
				if(op[i]==2) printf("%d\n",n);
				else puts("");
			}	   
	   }
	   return 0;
	}
	if(T%10==2){
		while(T--){
			n=read();m=read();k=read();
			for(int i=1;i<=m;i++) a[i]=read();
			for(int i=1;i<=k;i++) in[i]=0;
			int siz=0;
			s[0]=t[1]=s[1]=t[0]=0;
			for(int i=1;i<=m;i++){
				if(a[i]==a[i+1]){
				   op[++siz]=1;ans[siz]=1;
				   op[++siz]=1;ans[siz]=1;	
				   i++;
				   continue;
				}
				if(in[a[i]]){
				   int u=pos[a[i]];
				   if(stk[u][s[u]]==a[i]){
				   	  op[++siz]=1;ans[siz]=u+1;
				   	  s[u]--;
				   	  in[a[i]]=0;
				   }
				   if(stk[u][t[u]]==a[i]){
				   	  op[++siz]=1;ans[siz]=n;
				   	  in[a[i]]=0;
				   	  op[++siz]=2;
				   	  ans[siz]=u+1;
				   	  t[u]++;
				   }
				}
				else{
					if(!in[a[i+1]]){
					   in[a[i]]=1;
					   pos[a[i]]=n-1;
					   s[n]++;
					}
					else{
					  int u=pos[a[i+1]];
				   if(stk[u][s[u]]==a[i+1]){
				      int p=u^1;
				   	  op[++siz]=1;ans[siz]=p+1;
				   	  s[p]++;
				   	  in[a[i]]=1;
				   }
				   if(stk[u][t[u]]==a[i+1]){
				   	  op[++siz]=1;ans[siz]=u+1;
				   	  in[a[i]]=1;
				   	  s[u]++;
				   }	
					}
				}
			}
			printf("%d\n",siz);
			for(int i=1;i<=siz;i++){
				printf("%d %d ",op[i],ans[i]);
				if(op[i]==2) printf("%d\n",n);
				else puts("");
			}	   
		}
		return 0;
	}
}
