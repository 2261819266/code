#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
int t,n,m,k;

void add(int x,int s){
	sta[x]=s;
	fnext[head[s]]=x;
	Next[x]=head[s];
	head[s]=x;
	num[s]++;
	if(num[s]==1){
		b[s]=x;
	}
	else if(num[s]==2){
		b1[s]=x;
	}
}
void delfront(int s){
	sta[head[s]]=0;
	head[s]=Next[head[s]];
	Next[head[s]]=0;
	num[s]--;
	if(num[s]==0){
		b[s]=0;
	}
	else if(num[s]==1){
		b1[s]=0;
	}
}
void delback(int s){
	sta[b[s]]==0;
	num[s]--;
	if(num[s]){
		b[s]=b1[s];
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		n=read(),m=read(),k=read();
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
