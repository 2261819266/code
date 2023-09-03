#include<bits/stdc++.h>
using namespace std;
struct miao{
	int flag,z1,z2;
}e[100];
int n,m,k,t,a[5000000],b[100],c[100],d[100],kb,kc,kd,weib,weic,weid,sum,over,kou;
void dfs(int now){
	if(over){
		return;
	}
	if(m<=sum&&sum<=2*m&&now==m+1){
		if(weib==kb&&weic==kc&&weid==kd){
			over=1;
			printf("%d\n",sum);
			for(int j=1;j<=sum;j++){
				printf("%d ",e[j].flag);
				if(e[j].flag==1){
					printf("%d\n",e[j].z1);
				}
				else{
					printf("%d %d\n",e[j].z1,e[j].z2);
				}
			}
		}
		return;
	}
	if(sum>2*m)return;
	if(b[weib]==c[weic]&&weib){
		weib++;
		weic++;
		e[now].flag=2;
		e[now].z1=1;
		e[now].z2=2;
		sum++;
		dfs(now);
		e[sum].flag=0;
		e[sum].z1=0;
		e[sum].z2=0;
		sum--;
		weib--;
		weic--;
		
	}
	if(n>=2)
	if(b[weib]==d[weid]&&weib){
		weib++;
		weid++;	
		sum++;
		e[sum].flag=2;
		e[sum].z1=1;
		e[sum].z2=3;
		dfs(now);
		e[sum].flag=0;
		e[sum].z1=0;
		e[sum].z2=0;
		sum--;
		weib--;
		weid--;
	
	}
	if(n>=2)
	if(d[weid]==c[weic]&&weid){
		weid++;
		weic++;
		sum++;
		e[sum].flag=2;
		e[sum].z1=2;
		e[sum].z2=3;
		dfs(now);
		e[sum].flag=0;
		e[sum].z1=0;
		e[sum].z2=0;
		sum--;
		weid--;
		weic--;
		
	}
	kou=0;
    kb++;
	b[kb]=a[now];
	sum++;
	e[sum].flag=1;
	e[sum].z1=1;
	if(b[kb]==b[kb-1]){
		kb-=2;
		kou=1;
	}
	dfs(now+1);
	if(kou){
		kb+=2;
		kou=0;
	}
	e[sum].flag=0;
	e[sum].z1=0;
	b[kb]=0;
	kb--;
	sum--;
	kou=0;
	kc++;
	c[kc]=a[now];
	sum++;
	e[sum].flag=1;
	e[sum].z1=2;
	if(c[kc]==c[kc-1]){
		kc-=2;
		kou=1;
	}
	dfs(now+1);
	if(kou){
		kc+=2;
		kou=0;
	}
	e[sum].flag=0;
	e[sum].z1=0;
	c[kc]=0;
	kc--;
	sum--;
	kou=0;
	if(n>=2){
	kd++;
	d[kd]=a[now];
	sum++;
	e[sum].flag=1;
	e[sum].z1=3;
	if(d[kd]==b[kd-1]){
		kb-=2;
		kou=1;
	}
	dfs(now+1);
	if(kou){
		kd+=2;
		kou=0;
	}
	e[sum].flag=0;
	e[sum].z1=0;
	d[kd]=0;
	kd--;
	sum--;
	kou=0;}
	return;
}
long long cans,fans,fshu;
char ch;
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&n,&m,&k);
		for(int j=1;j<=m;j++){
			a[j]=0;
			scanf("%d",&a[j]);
			kb=0;
			kc=0;
			kd=0;
			weib=0;
			weic=0;
			weid=0;
		}
		dfs(1);
	}
	return 0;
}
