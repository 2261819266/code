/*The truth is with you!*/
# include <bits/stdc++.h>
# define MAX (2000009)
# define ll long long
# define inf (0x3f3f3f3f)
struct Node {
	int val,id;
};
int n,m,k,op,a[MAX],mv[MAX],cl[MAX],nx[MAX];
int st[309],ed[309],tp[620],hd[620],fv[620];
std::vector<Node>v[309];
int read() {
	int f=1,x=0;
	char ch=0;
	while('0'>ch||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main() {

	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);

	int _=read();
	int i,j;
	while(_--) {
		n=read();
		m=read();
		k=read();
		for(i = 1; i <= n; i++)st[i]=-1,ed[i]=0,v[i].clear();
		for(i = 1; i <= k; i++)tp[i]=hd[i]=0,fv[i]=inf;
		for(i = 1; i <= m; i++) {
			a[i]=read();
			mv[i]=1,cl[i]=-1;
			if(tp[a[i]]) {
				mv[i]=n>2?3:2;
				for(j = 1; j <= n; j++) {
					if(st[j]>=ed[j]) {
						if(v[j][ed[j]].val==a[i]) {
							cl[i]=j;
							ed[j]++;
							tp[a[i]]--;
							if(st[j]>=ed[j])tp[v[j][ed[j]].val]++;
							break;
						}
					}
				}
			} else {
				v[1].push_back(Node {a[i],i}),st[1]++;
				if(st[1]==ed[1])tp[v[1][ed[1]].val]++;
			}
		}
		for(i = st[1]; i >= ed[1]; i--) {
			nx[i]=fv[v[1][i].val];
			fv[v[1][i].val]=i;
		}
		for(i = ed[1]; i <= st[1]; i++) {
			if(nx[i]!=inf&&mv[i]==1) {
				if(nx[i]!=i+1) {
					mv[v[1][nx[i]].id]=2;
					cl[v[1][nx[i]].id]=1;
				}
			}
//			printf("\t%d %d\n",v[1][i].val,nx[i]);
		}
		for(i = 1,op = m; i <= m; i++)if(cl[i]!=-1)op++;
		printf("%d\n",op);
		for(i = 1; i <= m; i++) {
			printf("%d %d\n",1,mv[i]);
		}
		for(i = 1; i <= m; i++) {
			if(cl[i]!=-1&&mv[i]==3)printf("%d %d %d\n",2,mv[i],cl[i]);
		}
		for(i = 1; i <= m; i++) {
			if(cl[i]!=-1&&mv[i]==2)printf("%d %d %d\n",2,mv[i],cl[i]);
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
