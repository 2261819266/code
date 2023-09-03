#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e6+1;
int tg,n,m,k;
int a[N];
inline int rad(){
	int res=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res*w;
}
int b[N/2],c[N/2],sum=1e9,r1[N/2],r2[N/2],topp,g1[N/2],g2[N/2];
inline void jay(int x,int top1,int top2,int bot1,int bot2,int st)
{
	if(x==5&&top1==3&&top2==1&&bot1==2&&bot2==4&&st==5)cout<<1;
//	if(x==4&&top1==2&&top2==1&&bot1==2&&bot2==2&&st==4)cout<<1;
	//cout<<b[bot1]<<" "<<c[bot2]<<endl;
	//if(st==5)cout<<5; 
	//if(st>=sum)return ;
	if(x==m+1){
		if(bot1>top1&&bot2>top2)
		{
			if(st<sum)
			{
				for(int i=1;i<=st;++i)
				{
					g1[i]=r1[i];
					g2[i]=r2[i];
				 } 
				 sum=st;
				 //cout<<st<<endl;
			}
			
		}
	//	cout<<st<<endl;
		return ;
	}
	if(a[b[bot1]]==a[c[bot2]]&&bot1<=top1&&bot2<=top2)
	{
		r1[st+1]=2;
		//cout<<a[b[bot1]]<<" "<<a[c[bot2]]<<endl;
		//cout<<1;
		jay(x,top1,top2,bot1+1,bot2+1,st+1);
		}
		//if(x==4&&top1==2&&top2==1&&bot1==2&&bot2==2&&st==4)cout<<a[b[bot1]];
	b[++top1]=x;
	//if(x==4&&top1==3&&top2==1&&bot1==2&&bot2==2&&st==4)cout<<a[b[bot1+1]];
	r1[st+1]=1;
	r2[st+1]=1;
	if(a[b[top1]]==a[b[top1-1]])
		jay(x+1,top1-2,top2,bot1,bot2,st+1);
	else jay(x+1,top1,top2,bot1,bot2,st+1);
	top1--;
	c[++top2]=x;
	r2[st+1]=2;
	if(a[c[top2]]==a[c[top2-1]])
	jay(x+1,top1,top2-2,bot1,bot2,st+1);
	else jay(x+1,top1,top2,bot1,bot2,st+1);
	
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	tg=rad();
	for(int i=1;i<=tg;++i)
	{
		n=rad(),m=rad(),k=rad();//n为栈 m为卡牌数量 k为种类 
		for(int j=1;j<=m;++j)
		   a[j]=rad();
			    jay(1,0,0,1,1,0);
		printf("%d\n",sum);
		for(int i=1;i<=sum;++i)
		{
			if(g1[i]==1)
			printf("%d %d\n",g1[i],g2[i]);
			else if(g1[i]==2) printf("%d %d %d\n",g1[i],1,2);
		}
		
	}
	return 0;
}

