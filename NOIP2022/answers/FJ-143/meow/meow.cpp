#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
int T,n,m,a[2000005],b[305][2],sta[605],pos[605],t[605];
int op[4000005],ax[4000005],ay[4000005],cnt;
set<int> s0,s1;
inline void oper1(int x){
	op[++cnt]=1,ax[cnt]=x;
}
inline void oper2(int x,int y){
	op[++cnt]=2,ax[cnt]=x,ay[cnt]=y;
}
inline void ins2(int x,int y){
	if(b[x][1]){
		b[x][1]=sta[y]=pos[y]=0;
		s1.insert(x);
		return;
	}
	if(b[x][0]){
		if(b[x][0]!=y){
			b[x][1]=y,sta[y]=2,pos[y]=x;
			s1.erase(x);
		}
		else{
			b[x][0]=sta[y]=pos[y]=0;
			s1.erase(x),s0.insert(x);
		}
	}
	else{
		b[x][0]=y,sta[y]=1,pos[y]=x;
		s0.erase(x),s1.insert(x);
	}
}
inline void ins(int x,int y){
	oper1(x);
	ins2(x,y);
}
inline void del(int x){
	if(!b[x][1]){
		sta[b[x][0]]=pos[b[x][0]]=0;
		b[x][0]=0;
		s1.erase(x),s0.insert(x);
		return;
	}
	sta[b[x][0]]=pos[b[x][0]]=0;
	b[x][0]=b[x][1],b[x][1]=0;
	sta[b[x][0]]=1;
	s1.insert(x);
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%*d",&n,&m);
		for(int i=1;i<=m;++i)scanf("%d",a+i);
		cnt=0,s0.clear(),s1.clear();
		for(int i=1;i<=n;++i)s0.insert(i);
		for(int i=1,u,id,j,ps,tt;i<=m;i=j){
			u=a[i],id=*s0.begin(),j=i+1;
			if(sta[u]){
				if(sta[u]==2)ins(pos[u],u);
				else oper1(id),oper2(pos[u],id),del(pos[u]);
				continue;
			}
			if(!s1.empty()){
				ins(*s1.begin(),u);
				continue;
			}
			if(s0.size()>=2){
				ins(id,u);
				continue;
			}
			while(j<=m && sta[a[j]]==2)++j;
			if(sta[a[j]]==0){
				for(int k=i+1;k<j;++k)t[a[k]]=pos[a[k]];
				oper1(id);
				for(int k=i+1;k<j;++k)ins(t[a[k]],a[k]);
				oper1(id);
				++j;
				continue;
			}
			ps=pos[a[j]],tt=0;
			for(int k=i+1;k<j;++k){
				t[a[k]]=pos[a[k]];
				if(pos[a[k]]==ps)tt^=1;
			}
			if(tt){
				ins(id,u);
				for(int k=i+1;k<j;++k)ins(t[a[k]],a[k]);
				ins(ps,a[j]);
			}
			else{
				oper1(ps);
				for(int k=i+1;k<j;++k){
					if(pos[a[k]]==ps)oper1(ps);
					else ins(t[a[k]],a[k]);
				}
				oper1(id),oper2(ps,id),del(ps),ins2(ps,u);
			}
			++j;
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i){
			if(op[i]==1)printf("1 %d\n",ax[i]);
			else printf("2 %d %d\n",ax[i],ay[i]);
		}
	}
	return 0;
}
