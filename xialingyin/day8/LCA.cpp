#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
struct TREE
{
    int pre;
    int to;
}tree[1000010];
int edge_sum,head[500010];
int N,M,S,U,V,parent[500010][20],depth[500010];
void add_edge(int from,int to)
{
    edge_sum++;
    tree[edge_sum].pre=head[from];
    tree[edge_sum].to=to;
    head[from]=edge_sum;
}
void dfs(int dep,int cur,int fa)
{
    depth[cur]=dep；
    parent[cur][0]=fa;
    for(int i=head[cur];i!=0;i=tree[i].pre)
    {
        int u=tree[i].to;
        if(u!=fa)dfs(dep+1,u,cur);
    }
}
int query(int u,int v)
{
    if
}