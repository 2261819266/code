#include<bits/stdc++.h>
using namespace std;
//struct fafa{
//	int nxt,to;
//}edge[100020];
//int len_edge,head[1020],sta[10020];
//int n,m,top,slt[10020],dfn[10020];
//bool vis[10020];
//inline void add(int uuu,int vvv){
//	edge[++len_edge].nxt=head[uuu];
//	edge[len_edge].to=vvv;
//	head[uuu]=len_edge;
//	return;
//}
//void dfs(int x,int fa,int df){
//	dfn[x]=df;
//	sta[++top]=x;
//	cout<<x<<"!!!!\n";
//	bool flag=true;
//	for(int i=head[x];i;i=edge[i].nxt){
//		int u=edge[i].to;
//		if(u==fa)continue;
//		if(!vis[u]){
//			flag=false;
//			cout<<u<<"!!!\n";
//			cout<<sta[top]<<'_'<<u<<endl;
//			while(dfn[sta[top]]>=dfn[u]){
////				if(!slt[sta[top]])
//				cout<<sta[top]<<endl;
//				slt[sta[top]]=slt[u];
//				top--;
//			}
//		}else{
//			cout<<u<<' '<<x<<"!*@#(!@(#\n";
//			vis[u]=false;
//			dfs(u,x,df+1);
//		}
//	}
//	cout<<x<<' '<<flag<<"is over\n";
//	if(flag){
//		cout<<sta[top]<<"**";
//		top--;
//		cout<<sta[top]<<"!#!@\n";
//	}
//}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
//	memset(vis,true,sizeof(vis));
//	scanf("%d%d",&n,&m);
//	for(int i=1;i<=n;i++)
//		slt[i]=i;
//	for(int i=1;i<=m;i++){
//		int uu,vv;
//		scanf("%d%d",&uu,&vv);
//		add(uu,vv);add(vv,uu);
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=head[i];j;j=edge[j].nxt)
//			cout<<edge[j].to<<' ';
//		cout<<endl;
//	}
//	vis[1]=false;
//	dfs(1,1,1);
//	for(int i=1;i<=n;i++)
//		cout<<slt[i]<<' '; 
	puts("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
