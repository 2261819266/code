#include<bits/stdc++.h>//0xnnb2ndsb
#define ll long long
#define db double
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10-'0'+ch;
		ch=getchar();
	}
	return x*f;
}
int T,n,m,k,a[2000005],nxt[2000005],buc[605];
int stk[305][10],top[305],pos[605];
int stk1[305],top1,stk2[305],top2,emptystk;
int vis[305],anscnt,ans[4000005][3];
void init(){
	for(int i=1;i<=n;i++){
		nxt[i]=0;
	}
	memset(buc,0,sizeof(buc));
	memset(top,0,sizeof(top));
	memset(pos,0,sizeof(pos));
	top1=top2=anscnt=0;
	memset(vis,0,sizeof(vis));
}
void push(int i,int j){
	if(stk[i][top[i]]==j){
		pos[j]=0;
		if(top[i]==1)stk1[++top1]=i;
		if(top[i]==2)stk2[++top2]=i;
		top[i]--;
	}
	else{
		stk[i][++top[i]]=j;
		pos[j]=i+n*(top[i]-1);
	}
}
void pop(int i){
	pos[stk[i][1]]=0;
	for(int x=1;x<top[i];x++){
		stk[i][x]=stk[i][x+1];
		pos[stk[i][x]]=i+n*(x-1);
	}
	if(top[i]==1)stk1[++top1]=i;
	if(top[i]==2)stk2[++top2]=i;
	top[i]--;
}
int getstk(){
	while(top1){
		top1--;
		if(stk1[top1+1]!=emptystk){
			return stk1[top1+1];
		}
	}
	while(top2){
		top2--;
		if(stk2[top2+1]!=emptystk){
			return stk2[top2+1];
		}
	}
	return 0;
}
void add(int x,int y,int z){
	ans[++anscnt][0]=x;
	ans[anscnt][1]=y;
	ans[anscnt][2]=z;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--){
		init();
		n=read(),m=read(),k=read();
		for(int i=1;i<=m;i++){
			a[i]=read();
			if(buc[a[i]])nxt[buc[a[i]]]=i;
			buc[a[i]]=i;
		}
		emptystk=n;
		for(int i=1;i<n;i++){
			stk1[++top1]=i;
			stk2[++top2]=i;
		}
		for(int i=1;i<=m;i++){
			if(pos[a[i]]){
				int tmp=pos[a[i]];
				if(tmp<=n){
					add(1,emptystk,0);
					push(emptystk,a[i]);
					if(tmp!=emptystk){
						add(2,tmp,emptystk);
						pop(tmp),pop(emptystk);
					}
				}
				else{
					while(tmp>n)tmp-=n;
					add(1,tmp,0);
					push(tmp,a[i]);
				}
				continue;
			}
			int tmp=getstk();
			if(tmp){
				add(1,tmp,0);
				push(tmp,a[i]);
				continue;
			}
			bool flag=0;
			for(int x=i+1;x<nxt[i];x++){
				int tmp1=pos[a[x]],tmp2=tmp1;
				while(tmp2>n)tmp2-=n;
				if(vis[tmp2]==i)continue;
				if(tmp1>n){
					vis[tmp2]=i;
					continue;
				}
				add(1,tmp2,0);
				push(tmp2,a[i]);
				flag=1;
				break;
			}
			if(flag)continue;
			add(1,emptystk,0);
			push(emptystk,a[i]);
			for(int x=i+1;x<nxt[i];x++){
				int tmp1=pos[a[x]];
				if(tmp1>n){
					while(tmp1>n)tmp1-=n;
					emptystk=tmp1;
					break;
				}
			}
		}
		printf("%d\n",anscnt);
		for(int i=1;i<=anscnt;i++){
			if(ans[i][0]==1){
				printf("1 %d\n",ans[i][1]);
			}
			else{
				printf("2 %d %d\n",ans[i][1],ans[i][2]);
			}
		}
	}
	return 0;
}
