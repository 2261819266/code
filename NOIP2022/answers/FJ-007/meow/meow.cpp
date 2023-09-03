#include<bits/stdc++.h>
using namespace std;
const int Q=2e6+10;
int em,T,n,m,k,col[1010],to[Q],a[Q],pos,col1[1010],col0[1010],st0[1010],st1[1010],sta0[1010],sta1[1010],v,sta3[1010],st3[1010],col3[1010];
int op[Q][5],all;
vector <int> g1,g0,wait;
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=m; i++) {
			scanf("%d",&a[i]);
			to[i]=m+1;
		}
		for(int i=1; i<=k; i++)
			col[i]=m+1;
		for(int i=m; i>=1; i--) {
			to[i]=col[a[i]];
			col[a[i]]=i;
		}
		for(int i=1; i<=n-1; i++)
			g0.push_back(i);
		pos=0;
		while(++pos<=m) {
			if(a[pos]==em)
			{
				em=0;
				all++;
				op[all][0]=1;
				op[all][1]=n;
			}
			if(col3[a[pos]]!=0) {
				v=col3[a[pos]];
				all++;
				op[all][0]=1;
				op[all][1]=v;
				st3[v]=sta3[v]=0;
				col3[a[pos]]=0;
				continue;
			}
			if(col1[a[pos]]!=0 and st3[col1[a[pos]]]==0) {
				v=col1[a[pos]];
				all++;
				op[all][0]=1;
				op[all][1]=v;
				g1.push_back(v);
				sta1[v]=0;
				st1[v]=0;
				col1[a[pos]]=0;
				continue;
			}
			if(col0[a[pos]]!=0 and st1[col0[a[pos]]]==0) {
				all++;
				op[all][0]=1;
				op[all][1]=col0[a[pos]];
				g0.push_back(col0[a[pos]]);
				sta0[col0[a[pos]]]=0;
				st0[col0[a[pos]]]=0;
				col0[a[pos]]=0;
				continue;
			}
			if(g0.size()) {
				v=g0[g0.size()-1];
				all++;
				op[all][0]=1;
				op[all][1]=v;
				sta0[v]=pos;
				col0[a[pos]]=v;
				st0[v]=a[pos];
				g1.push_back(v);
				g0.pop_back();
				continue;
			}
			if(g1.size()) {
				v=g1[g1.size()-1];
				all++;
				op[all][0]=1;
				op[all][1]=v;
				sta1[v]=pos;
				col1[a[pos]]=v;
				st1[v]=a[pos];
				g1.pop_back();
				continue;
			}
			if(col0[a[pos]]!=0) {
//				printf("%d %d %d\n",all,op[all][0],op[all][1]);
				v=col0[a[pos]];
				all++;
				op[all][0]=1;
				op[all][1]=n;
				all++;
				op[all][0]=2;
				op[all][1]=n;
				op[all][2]=v;
//				printf("%d\n",all);
				if(st3[v]==0)
					g1.push_back(v);
				sta0[v]=sta1[v];
				sta1[v]=sta3[v];
				sta3[v]=0;
				col3[st3[v]]=0;
				col0[a[pos]]=0;
				col0[st1[v]]=v;
				col1[st3[v]]=v;
				col1[st1[v]]=0;
				st0[v]=st1[v];
				st1[v]=st3[v];
				st3[v]=0;
				continue;
			}
			for(int i=1; i<=n; i++) {
				if(to[sta0[i]]<to[pos] and i!=n) {
					all++;
					op[all][0]=1;
					op[all][1]=i;
					sta3[i]=pos;
					st3[i]=a[pos];
					col3[a[pos]]=i;
					wait.clear();
					break;
				}
				all++;
				op[all][0]=1;
				op[all][1]=n;
				em=a[pos];
			}
		}
		printf("%d\n",all);
		for(int i=1; i<=all; i++) {
			printf("%d ",op[i][0]);
			for(int j=1; j<=op[i][0]; j++)
				printf("%d ",op[i][j]);
			printf("\n");
		}
		all=0;
		g0.clear();
		g1.clear();
	}
	return 0;
}
/*
1
3 10 5
1 2 3 4 5 2 3 4 5 1

15
1 1
1 1
1 1
1 1
1 1
1 2
1 2
1 2
1 2
1 3
2 1 3
2 1 2
2 1 2
2 1 2
2 1 2

*/
