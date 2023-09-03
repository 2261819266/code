#include<cstdio>
#include<vector>
#include<ctime>
using namespace std;
struct Oper
{
	int k,x,y;
};
vector<Oper> ans;
vector<int> z[310];
int T,n,m,k,t[310],a[2000010];
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans.clear();
		for(int i=1;i<=300;i++) t[i]=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++) scanf("%d",a[i]);
//		solve(1,n,k);
//		for(int i=1;i<=m;i++) 
	}
}
