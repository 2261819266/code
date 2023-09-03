#include<cstdio>
#include<cstring>
#define reg register
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int n,m,up[350],down[350],a[350],k;
int read(){
	reg int s=0,f=1;
	reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+ch-'0',ch=getchar());
	return s*f;
}
void opt1(int x){
	printf("1 %d\n",x);
}
void opt2(int x,int y){
	printf("1 %d\n",y);
	printf("2 %d %d\n",x,y);
}
void work1(){
	int g=n-1,p;
	memset(up,0,sizeof(up));
	memset(down,0,sizeof(down));
	for(reg int i=1;i<=m;i++){
		if(a[i]>g)p=a[i]-g;
		else p=a[i];
		if(up[p]==a[i])opt1(p),up[p]=0;
		else if(down[p]==a[i])opt2(p,n),down[p]=0;
		else if(down[p]){
			opt1(p);
			up[p]=a[i];
		}
		else {
			opt1(p);
			down[p]=a[i];
		}
	}
}
int st1[350],st2[350],top1,top2,g1,g2;
void work2(){
	top1=top2=0;g1=g2=1;
	for(reg int i=1;i<=m;i++){
		if(st1[top1]==a[i]){
			opt1(1);top1--;
		}
		else if(st2[top2]==a[i]){
			opt1(2);top2--;
		}
		else{
			if(top1<=g1){
				if(st2[g2]==a[i])opt2(2,1),g2++;
				else opt1(1),st1[++top1]=a[i];
			}
			else if(top2<=g2){
				if(st1[g1]==a[i])opt2(1,2),g1++;
				else opt1(2),st2[++top2]=a[i];
			}
			else if(a[i+1]==st1[top1]){
				opt1(2);
				st2[++top2]=a[i];
			}
			else if(a[i+1]==st2[top2]){
				opt1(1);
				st1[++top1]=a[i];
			}
			
		}
	}
}
void kotori(){
	n=read(),m=read(),k=read();
	for(reg int i=1;i<=m;i++){
		a[i]=read();
	}
	if(k==2*n-2)work1();
	else work2();
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int _=read();
	while(_--)kotori();
}
