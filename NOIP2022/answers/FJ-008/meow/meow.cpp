#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sum=0,d=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')d=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*d;
}
#define maxn 309
#define maxk 609
#define maxm 2000009
int t,n,m,k,a[maxm],lt[maxk],nt[maxm];
int id[maxk],ids[maxk],cnt[maxn],di[maxn][3];
int op=0,ans[maxm*2][3];
#define mp make_pair
#define fi first
#define se second
set<pair<int ,int > > zs[3];
void add(int i){
	if((!zs[1].empty()&&nt[i]<-(*zs[1].begin()).fi)||zs[0].empty()){
		id[a[i]]=(*zs[1].begin()).se;zs[1].erase(zs[1].begin());zs[2].insert(mp(-nt[i],id[a[i]]));
	}
	else{
		id[a[i]]=(*zs[0].begin()).se;zs[0].erase(zs[0].begin());zs[1].insert(mp(-nt[i],id[a[i]]));
	}
	ids[a[i]]=++cnt[id[a[i]]];
	di[id[a[i]]][cnt[id[a[i]]]]=i;
	op++;ans[op][0]=1;ans[op][1]=id[a[i]];
	return ;
}
void outputans(){
	printf("%d\n",op);
	for(int i=1;i<=op;i++){
		printf("%d",ans[i][0]);
		for(int j=1;j<=ans[i][0];j++)printf(" %d",ans[i][j]);
		printf("\n");
	}
	return ;
}
void work(){
	op=0;
	for(int i=1;i<=k;i++)lt[i]=id[i]=ids[i]=0;
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=0;i<3;i++)zs[i].clear();
	for(int i=1;i<=n;i++)zs[0].insert(mp(0,i));
	for(int i=m;i;i--)nt[i]=lt[a[i]],lt[a[i]]=i;
	for(int i=1;i<=m;i++){
		if(id[a[i]]){
			if(ids[a[i]]==cnt[id[a[i]]]){
				op++;ans[op][0]=1;ans[op][1]=id[a[i]];
				zs[cnt[id[a[i]]]].erase(mp(-i,id[a[i]]));
				zs[cnt[id[a[i]]]-1].insert(mp(-nt[di[id[a[i]]][cnt[id[a[i]]]-1]],id[a[i]]));
				cnt[id[a[i]]]--;id[a[i]]=0;
			}
			else{
//				if(zs[0].empty()){
//					puts("I cant slove it QAQ");
//					outputans();
//					exit(0);
//				}
				op++;ans[op][0]=1;ans[op][1]=(*zs[0].begin()).se;
				op++;ans[op][0]=2;ans[op][1]=(*zs[0].begin()).se;ans[op][2]=id[a[i]];
				ids[a[di[id[a[i]]][2]]]=1;di[id[a[i]]][1]=di[id[a[i]]][2];
				zs[cnt[id[a[i]]]].erase(mp(-i,id[a[i]]));
				zs[cnt[id[a[i]]]-1].insert(mp(-nt[di[id[a[i]]][cnt[id[a[i]]]-1]],id[a[i]]));
				cnt[id[a[i]]]--;id[a[i]]=0;
			}
		}
		else{
			add(i);
		}
	}
	outputans();
	return ;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--){
		n=read();m=read();k=read();
		for(int i=1;i<=m;i++)a[i]=read();
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

