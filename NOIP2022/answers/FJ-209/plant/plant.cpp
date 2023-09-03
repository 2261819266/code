#include<bits/stdc++.h>
#define r(x) x=read()
using namespace std;
const int mo=998244353;
int read(){
	//unsigned
	int num=0;
	char a=getchar();
	while(a<'0'||a>'9') a=getchar();
	while(a>='0'&&a<='9'){
		num=(num*10)+a-'0';
		a=getchar();
	}
	return num;
}
int t,id,m,n,c,f,g[1003][1003];
void f_c(){
	int x1,x2,y1,y2,y3,ans=0;
	for(x1=0;x1<n-2;x1++){
		for(y1=0;y1<m-1;y1++){
			if(g[x1][y1]||g[x1+1][y1]||g[x1][y1+1]) continue;
			for(x2=x1+2;x2<n;x2++){
				if(g[x2][y1]) break;
				int a=0,b=0;
				for(y2=y1+1;y2<m;y2++){
					if(g[x1][y2]) break;
					a++;
				}
				if(a) for(y3=y1+1;y3<m;y3++){
					if(g[x2][y3]) break;
					b++;
				}
				ans+=a*b;
				ans%=mo;
			}
		}
	}
	printf("%d ",ans);
}
void f_f(){
	int x1,x2,x3,y1,y2,y3,ans=0;
	for(x1=0;x1<n-3;x1++){
		for(y1=0;y1<m-1;y1++){
			if(g[x1][y1]||g[x1+1][y1]||g[x1][y1+1]||g[x1+2][y1]) continue;
			for(x3=x1+3;x3<n;x3++)
				if(g[x3][y1]) break;
			x3-=1;
			for(x2=x1+2;x2<x3;x2++){
				int a=0,b=0;
				for(y2=y1+1;y2<m;y2++){
					if(g[x1][y2]) break;
					a++;
				}
				if(a) for(y3=y1+1;y3<m;y3++){
					if(g[x2][y3]) break;
					b++;
				}
				ans+=a*b*(x3-x2);
				ans%=mo;
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	r(t),r(id);
	if(id==1){
		for(int i=0;i<t;i++) printf("0 0\n");
		return 0;
	}
	while(t--){
		r(n),r(m),r(c),r(f);
		for(int i=0;i<n;i++){
			char a=getchar();
			while(a!='0'&&a!='1') a=getchar();
			for(int q=0;q<m;q++){
				g[i][q]=a-'0';
				a=getchar();
			}
		}
		if(c==0) printf("0 ");
		else f_c();
		if(f==0) printf("0\n");
		else f_f();
	}
	return 0;
}
