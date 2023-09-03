#include<bits/stdc++.h>
using namespace std;
#define M 2000010
#define N 310
struct answer{
	int opt,s1,s2;
}ans[M<<1];
int t,n,m,k,a[M],op,pos,sta[N][M>>4],x[M],y[M],top[N],down[N];
void push1(int s){ans[++op].opt=1,ans[op].s1=s;}
void push2(int s,int ss){ans[++op].opt=2,ans[op].s1=s,ans[op].s2=ss;}
bool ok;
void upd(int now,int res){
	if(y[now]!=0){
		push2(res,y[now]);
		down[res]++;
		upd(sta[res][down[res]],res);
		down[y[now]]++;
		upd(sta[y[now]][down[y[now]]],y[now]);
	}else y[now]=res;
	return;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	srand(1919810);
	scanf("%d",&t);
	while(t--){
		memset(ans,0,sizeof(ans));op=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)x[i]=y[i]=top[i]=down[i]=0;pos=0;
		for(int i=1;i<=m;i++)scanf("%d",a+i);
		for(int i=1,now;i<=m;i++){
			if(x[a[i]]!=0){
				push1(x[a[i]]);
				x[sta[x[a[i]]][--top[x[a[i]]]]]=x[a[i]];x[a[i]]=0;
			}else if(y[a[i]]!=0){
				push1(n);push2(y[a[i]],n);
				now=sta[y[a[i]]][++down[y[a[i]]]];
				upd(now,y[a[i]]);y[a[i]]=0;
			}else if(pos==n-1){
				now=rand()%(n-1)+1;
				push1(now);
				x[a[i]]=now;
				x[sta[now][top[now]]]=0;
				sta[now][++top[now]]=a[i];
			}else{
				push1(++pos);
				x[a[i]]=y[a[i]]=pos;
				sta[pos][++top[pos]]=a[i];
				down[a[i]]++;
			}
		}
		printf("%d\n",op);
		for(int i=1;i<=op;i++)
			if(ans[i].opt==1)printf("1 %d\n",ans[i].s1);
			else printf("2 %d %d\n",ans[i].s1,ans[i].s2);
	}
	return 0;
}
/*
3
2 4 2
1 2 1 2
2 10 5
1 2 3 4 5 1 2 3 4 5
3 10 5
1 2 3 4 5 2 3 4 5 1
*/