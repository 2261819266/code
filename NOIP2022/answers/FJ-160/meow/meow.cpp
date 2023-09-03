#include "bits/stdc++.h"
using namespace std;

int T;
int sta[310][4]; //栈  1->栈底 0->栈内元素数量 元素是牌序 
int nxt[2000010]; //每一张牌下一张出现的位置 
int now[310]; //当下每一张牌在哪个栈
int op;
int stp[4000010][3]; //行动记录 
int a[310]; //临时记录牌组 
int b[2000010]; //真牌组 
int kon; //哪个栈要留空 
int use0,use2;

int read() {
	char c=getchar();
	long long re=0;
	while (c<'0' || c>'9') c=getchar();
	while (c>='0' && c<='9') re=re*10+c-'0',c=getchar();
	return re; 
}

void delup(int p) { //删除栈顶元素 
	sta[p][0]--;
	if (stp[p][0]==0 && kon==-1) kon=p;
}

void deldown (int p) { //删除栈底元素 
	sta[p][1]=sta[p][2];
	if (sta[p][0]==3) sta[p][2]=sta[p][3];
	sta[p][0]--;
}

void add(int p,int i) {
	sta[p][++sta[p][0]]=i;
	now[b[i]]=p;
}


int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	T=read();
	while (T--) {
		int n=read(),m=read(),k=read();
		op=0;
		memset(a,0,sizeof(a));
		memset(now,0,sizeof(now));
		memset(sta,0,sizeof(sta));
		for (int i=1;i<=m;i++) {
			b[i]=read();
			if (a[b[i]]==0) {
				a[b[i]]=i;
			} else {
				nxt[a[b[i]]]=i;
				nxt[i]=0;
				a[b[i]]=0;
			}
		}
		
		kon=n; 
		for (int i=1;i<=m;i++) {
			if (now[b[i]]!=0) { //这张牌有在栈内，那么直接消除 
				int p=now[b[i]];
				now[b[i]]=0;
				if (b[sta[p][sta[p][0]]]==b[i]) { //在栈顶 
					stp[++op][0]=1,stp[op][1]=p;
					delup(p); 
				} else { //栈底 
					stp[++op][0]=1,stp[op][1]=kon;
					stp[++op][0]=2,stp[op][1]=p,stp[op][2]=kon;
					deldown(p);
				}
				continue;
			} 
			//不在栈内 
			if (kon==-1) { //现在没有预留空位 
				int tmp=-1;
				for (int j=1;j<=n;j++) {
					if (sta[j][0]==1) {
						if (tmp==-1) {
							tmp=j;
						} else {
							if (nxt[sta[j][1]]>nxt[sta[tmp][1]]) tmp=j;
							break;
						}
 					}
				}
				stp[++op][0]=1,stp[op][1]=tmp;
				add(tmp,i);
			} else {
				int tmp=-1;
				for (int j=n;j>=1;j--) {
					if (j==kon) continue;
					if (sta[j][0]==0 || sta[j][0]==1) {
						tmp=j;
						stp[++op][0]=1,stp[op][1]=tmp;
						add(tmp,i);
						break;
					}
				}
				if (tmp==-1) {
					for (int j=n;j>=1;j--) {
						if (nxt[sta[j][1]]<nxt[sta[j][2]]) {
							tmp=j;
							stp[++op][0]=1,stp[op][1]=tmp;
							add(tmp,i);
							break;
						} 
					}
					if (tmp==-1) {
						stp[++op][0]=1,stp[op][1]=tmp;
						add(tmp,kon);
						kon=-1;
					}
				}
			}
		}
		printf("%d\n",op);
		for (int i=1;i<=op;i++) {
			printf("%d ",stp[i][0]);
			for (int j=1;j<=stp[i][0];j++) printf("%d ",stp[i][j]);
			printf("\n");
		}
	}

	return 0;
}
