#include<bits/stdc++.h>
#define ll long long
#define fs(i,x,y,z) for(int i=x;i<=y;i+=z)
#define ft(i,x,y,z) for(int i=x;i>=y;i+=z)
const ll N=1001,inf=998244353ll;
inline int read(){
	int v=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){v=v*10+(c-'0');c=getchar();}
	return v*w;
}
using namespace std;
int n,m,c,f,a[N][N],heng[N][N],shu[N][N];
ll presum[N];//heng[i][j]是a横向的前缀和，shu[i][j]是a竖向的前缀和 
char s[N];
void mian(){
	n=read(),m=read(),c=read(),f=read();
	//考虑枚举初始列，然后记录有多少行能因此配对完成？
	//你枚举了初始列，还有了每一行从这一列开始的延伸情况，还得分段 
	//则答案就是\sum_{i=1}^m \prod 每一段的方式，这个可以Onm求出来 
	//这个是C类，那么F类怎么做？
	//假设我们现在从上往下遍历到这个，则答案就是(i为左下角的C)\times (到i下面的第一个1-1) 
	if(c==0&&f==0){
		puts("0 0");
		return;
	}
	fs(i,1,n,1) fs(j,1,m,1) heng[i][j]=shu[i][j]=a[i][j]=0; 
	fs(i,1,n,1) presum[i]=0;
	fs(i,1,n,1){
		//scanf("%s",s+1);
		fs(j,1,m,1){
			char ch=getchar();
			a[i][j]=ch-'0',heng[i][j]=heng[i][j-1]+a[i][j],shu[j][i]=shu[j][i-1]+a[i][j];//本列的情况 
		}
		getchar();
	}
	ll ans=0;//总的答案 
	//枚举C类
	if(c){
		fs(col,1,m,1){//那左边的一列在哪里 
			//=sumpre*ai，然后这个再加到sumpre上面去
			ll res=0,curline=1;//sigma是前面ai的和，res是我们要求的东西 
			fs(cur,1,n,1){
				if(a[cur][col]){curline=1;continue;}//有一个段，要重开了 
				int pos=upper_bound(heng[cur]+1,heng[cur]+m+1,heng[cur][col])-heng[cur];//我后面的第一个1 
				int fas=max(pos-col-1,0);//这在哪些列是有用的
		//		printf("for(%d,%d),pos is (%d,%d),place as %d\n",cur,col,cur,pos,fas);
				(res+=presum[max(curline-2,0ll)]*fas%inf)%=inf;
			//	sigma+=fas; 
				presum[curline]=presum[curline-1]+fas;curline++;
			} 
		//	printf("curline at here is %d\n",res);
			(ans+=res)%=inf;//这一列的答案 
		} 
		printf("%lld ",ans);ans=0;
	}else printf("0 ");
	if(f){
		fs(i,1,n,1) presum[i]=0;
		//现在我们考虑F类 
		fs(col,1,m,1){//F也要求了这个的相关内容 
			ll res=0,curline=1;
			fs(cur,1,n,1){//当前行 
				if(a[cur][col]){curline=1;continue;}//碰壁了，重开 
				int posi=upper_bound(shu[col]+1,shu[col]+n+1,shu[col][cur])-shu[col];
				int pos=upper_bound(heng[cur]+1,heng[cur]+m+1,heng[cur][col])-heng[cur];//我后面的第一个1 
				int fas=max(pos-col-1,0);
				//以我这行为结尾
			//	printf("(%d,%d) contributes %d,posi is %d\n",cur,col,presum[max(curline-2,0)]*fas*max(0,posi-cur-1),posi);
				(res+=presum[max(curline-2,0ll)]*fas%inf*max(0,posi-cur-1)%inf)%=inf;
				presum[curline]=presum[curline-1]+fas;curline++; 
			}
		//	printf("curline at here is %d\n",res);
			(ans+=res)%=inf;
		}
		printf("%lld\n",ans);
	}else puts("0");
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int t=read(),id=read();while(t--) mian();
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
//额外要求：x1+1<x2，所以至少得空一行
//要不要上线段树维护？考虑前缀和即可吧 
