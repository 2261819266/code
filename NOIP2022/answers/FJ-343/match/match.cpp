#include<bits/stdc++.h>
#define ll long long
#define fs(i,x,y,z) for(int i=x;i<=y;i+=z)
#define ft(i,x,y,z) for(int i=x;i>=y;i+=z)
#define ull unsigned long long
const int N=3001,inf=998244353;
inline int read(){
	int v=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9'){v=v*10+(c-'0');c=getchar();}
	return v*w;
}
using namespace std;
//struct seg{int val;}tr[];
int n,a[N],b[N],m;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int id=read();n=read();
	fs(i,1,n,1) a[i]=read();fs(i,1,n,1) b[i]=read();
	m=read();while(m--){
		int l=read(),r=read();
		ull res=0;
		fs(p,l,r,1){
			fs(q,p,r,1){
				ull val=0,val2=0;
				fs(x,p,q,1) val=max(val,(ull)a[x]),val2=max(val2,(ull)b[x]);
				res+=val*val2;
			}
		}
		printf("%llu\n",res);
	}
	return 0;
}
//考虑若k=2n-2怎么做
//首先我们观察性质：他一定是满足“每次都能被消掉两张卡”的
//而显而易见地，多余的卡没用
//所以我们对于栈1处理k=1,2，栈2处理k=3,4...？是这样吗
//明显不是
//正难则反，我们倒着思考
//最后一定栈都空了
//则最后一个操作如果是II，说明有2个栈是有一张牌的
//如果最后一个操作是I，则说明一个栈中有一张牌
//换句话说，II操作能让当前在栈中的牌数+2，而I操作能让当前在栈中的牌数-1，也有可能是+1
//那可是这还是与栈顶有关啊
//那么你就把栈顶给记录下来？
//观察到先被放进去的，要么是被另一个人从栈底救出来，要么就是等另一个人和我一起进去
//操作最多2m次，每个人进栈一次，出栈一次
//考虑匹配，匹配谁把这个人给救出来
//怎么救？因为第一个3后面还有A人，所以用II操作
//就不能避免？算了，先开T3
//考虑T3的暴力：先枚举点如何，再枚举边，最后看一下怎样即可
//那么链的分怎么计算？考虑f[i]表示[1,i]连边的方案数
//则我们枚举第一个人是在哪，答案就是(n+1)*n\times ksm(2,n-1)
//25分有了，我们还要再凑出25
//考虑如果在LCA上统计答案会怎样
//算了，先看看D有多少分，然后写完 
//D的话，对于每次询问，考虑最大值的出现次数——开一个l和r用来记录
//那怎么统计？单调栈，while(a[i]>a[s.top()]) s.pop(); 
//写个纯暴力吧 
//不行，回来必须给我搞到20分 
