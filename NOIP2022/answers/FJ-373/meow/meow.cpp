#include<cstdio>
using namespace std;
int n,m,T,a[2000005],c[1000005],s1[2000005],s2[2000005],t1[1000005],t2[1000005],t3[100005],tot1,tot2,tot3,flag,k;
void dfs2(int x){
	if(flag)return;
	if(x>m){
		int head1=1,head2=1,head3=1,num=m;
		while((tot1^(head1-1))||(tot2^(head2-1))){
			if(t1[head1]==t2[head2])++head1,++head2,c[++num]=2,s1[num]=1,s2[num]=2;
			else break;
		}
		if(tot1==head1-1&&tot2==head2-1){
			printf("%d\n",num);
			for(int i=1;i<=num;++i){
				if(c[i]==1)printf("%d %d\n",1,s1[i]);
				else printf("%d %d %d\n",2,s1[i],s2[i]);
			}
			flag=1;
		}
		return;
	}
	int flg=-1;
	c[x]=1,s1[x]=1;
	if(t1[tot1]==a[x])--tot1,flg=1;
	else t1[++tot1]=a[x];
	dfs2(x+1);
	s1[x]=2;
	tot1+=flg;
	flg=-1;
	if(t2[tot2]==a[x])--tot2,flg=1;
	else t2[++tot2]=a[x];
	dfs2(x+1);
	tot2+=flg;
}
void dfs(int x){
	if(flag)return;
	if(x>m){
		int head1=1,head2=1,head3=1,num=m;
		while((tot1^(head1-1))||(tot2^(head2-1))||(tot3^(head3-1))){
			if(t1[head1]==t2[head2])++head1,++head2,c[++num]=2,s1[num]=1,s2[num]=2;
			else if(t2[head2]==t3[head3])++head2,++head3,c[++num]=2,s1[num]=2,s2[num]=3;
			else if(t1[head1]==t3[head3])++head1,++head3,c[++num]=2,s1[num]=1,s2[num]=3;
			else break;
		}
		if(tot1==head1-1&&tot2==head2-1&&tot3==head3-1){
			printf("%d\n",num);
			for(int i=1;i<=num;++i){
				if(c[i]==1)printf("%d %d\n",1,s1[i]);
				else printf("%d %d %d\n",2,s1[i],s2[i]);
			}
			flag=1;
		}
		return;
	}
	int flg=-1;
	c[x]=1,s1[x]=1;
	if(t1[tot1]==a[x])--tot1,flg=1;
	else t1[++tot1]=a[x];
	dfs(x+1);
	s1[x]=2;
	tot1+=flg;
	flg=-1;
	if(t2[tot2]==a[x])--tot2,flg=1;
	else t2[++tot2]=a[x];
	dfs(x+1);
	tot2+=flg;
	s1[x]=3;
	flg=-1;
	if(t3[tot3]==a[x])--tot3,flg=1;
	else t3[++tot3]=a[x];
	dfs(x+1);
	tot3+=flg;
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;++i)scanf("%d",&a[i]);
		tot1=0,tot2=0,tot3=0,flag=0;
		if(n==2)dfs2(1);
		else dfs(1);
	}
	return 0;
}