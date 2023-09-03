#include<bits/stdc++.h>
using namespace std;

int read(){
	int w=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')w=w*10+ch-48,ch=getchar();
	return w;
}

#define MAXN 303
#define MAXM 50003
int n,m,k,c[MAXN];
int s[MAXN][MAXM],stop[MAXN],slst[MAXN];
vector<int>op,x1,x2;

void op2(int x,int y=0){
	if(y){
		printf("2 %d %d\n",x,y);
		slst[x]++,slst[y]++;
		op2(x),op2(y);
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==x)continue;
		if(s[i][slst[i]+1]==s[x][slst[x]+1]&&s[x][slst[x]+1]!=0){
			printf("2 %d %d\n",i,x);
			slst[i]++,slst[x]++;
			op2(i),op2(x);
			break;
		}
	}
}

void op1(int c,int x=0){
	if(x){
		printf("1 %d\n",x);
		s[x][++stop[x]]=c;
		return;
	}
	for(int i=1;i<=n;i++)if(c==s[i][stop[i]]){
		printf("1 %d\n",i);
		stop[i]--;
		if(stop[i]==slst[i]+1)op2(i);
		return;
	}// 可以匹配 1
//	for(int i=1;i<=n;i++)if(c==s[i][slst[i]+1]){
//		for(int j=1;j<=n;j++)if(stop[j]==slst[j]){
//			s[j][++stop[j]]=c;
//			printf("1 %d\n",j);
//			op2(i,j);
//			return;
//		}// 找空位 
//		
//	}// 有空位且可以匹配 2 
//	for(int i=1;i<=n;i++)if(stop[i]==slst[i]){
//		s[i][++stop[i]]=c;
//		printf("1 %d\n",i);
//		return;
//	}// 有空位就占
	for(int i=1;i<=n;i++){
		if(stop[i]==slst[i]){// 找空位 
			for(int j=1;j<=n;j++){// 找同色 
				if(c==s[j][slst[j]+1]){
					s[i][++stop[i]]=c;
					printf("1 %d\n",j);
					op2(i,j);
					return;
				}
			}// 有同色 
			s[i][++stop[i]]=c;
			printf("1 %d\n",i);
			return;
			// 没同色 
		}
	}// 尝试匹配 2 
	int tmp=1+rand()%n;
	s[tmp][++stop[tmp]]=c;
	printf("1 %d\n",tmp);
	if(stop[tmp]==slst[tmp]+1){
		op2(tmp);
	}
	// 没空位随机
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	srand(time(0));
	int t=read();
	while(t--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++)stop[i]=0,slst[i]=0;
		for(int i=1;i<=m;i++)c[i]=read(),op1(c[i]);
	}
	return 0;
}
/*
1
2 4 2
1 2 1 2

1 2 8 3
1 2 3 3 3 2 1 3
*/
// 1 10:42 rand
// 2 12:00 rand
