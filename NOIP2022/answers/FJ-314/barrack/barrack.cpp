#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int mod = 1000000007;
vector<pair<int,int> > edge_list;
int n,m,fa[500010],res;
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
inline bool check(int nod,int edg){
	for(int i=1;i<=n;i++)	fa[i] = i;
	for(int i=0;edg;edg>>=1,i++)
		if(edg&1)	fa[get(edge_list[i].first)] = get(edge_list[i].second);
	int u = 0;
	bool flag = false;
	for(int i=1;nod;nod>>=1,i++)
		if(nod&1){
			flag = true;
			if(u==0||get(i)==u)	u = get(i);
			else return false;
		}
	return flag;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d %d",&u,&v);
		edge_list.emplace_back(u,v);
	}
	if(false){
		
	}else{
		int sta_n = (1 << n) - 1,sta_e = (1 << m) - 1;
		for(int i=0;i<=sta_n;i++)
			for(int j=0;j<=sta_e;j++)
				if(check(i,j))	res++;
	}
	printf("%d\n",res);
	return 0;
}
/* I love zxl forever */

