# include <bits/stdc++.h>
# define S 2000010
# define N 610
int a[S],to[S],buc[N],wh[S];
struct pair{
	int id,x;
};
struct three{
	int op,x,y;
}ans[S<<1];
int ansn;
std::set<pair> st;
std::set<int> emp;
bool operator <(const pair &i,const pair &j) {return i.x<j.x || i.x==j.x && i.id<j.id;}
std::deque<int> dq[N];
void answ(int op,int x,int y) {
	ans[++ansn]=(three){op,x,y};
	// printf("answer %d %d %d\n",op,x,y);
}
int getemp() {
	if(emp.empty()) return -1;
	return *emp.begin();
}
pair getone() {
	return *(--st.end());
}
void push(int pos,int id) {
	// printf("push %d %d\n",pos,id);
	wh[id]=pos;
	answ(1,pos,0);
	dq[pos].push_back(id);
	// printf("(%d,%d)\n",pos,to[id]);
	st.insert((pair){pos,to[id]});
	emp.erase(pos);
	// printf("popemp %d %d\n",pos,dq[pos].size());
}
void push2(int pos,int id) {
	// printf("push2 %d %d\n",pos,id);
	wh[id]=pos;
	answ(1,pos,0);
	dq[pos].push_back(id);
	st.erase((pair){pos,to[dq[pos].front()]});
}
void del2(int pos,int id) {
	// printf("del2 %d %d\n",pos,id);
	answ(1,pos,0);
	int lsto=to[dq[pos].front()];
	dq[pos].pop_back();
	if(dq[pos].size()==1) st.insert((pair){pos,to[dq[pos].front()]});
	else emp.insert(pos),st.erase((pair){pos,lsto});
}
void del(int pos,int u,int id) {
	// printf("del %d %d %d\n",pos,u,id);
	answ(1,u,0); answ(2,pos,u);
	int lsto=to[dq[pos].front()];
	dq[pos].pop_front();
	if(dq[pos].size()==1) st.insert((pair){pos,to[dq[pos].front()]});
	else emp.insert(pos),st.erase((pair){pos,lsto});
}
void prt() {
	int i;
	printf("%d\n",ansn);
	for(i=1;i<=ansn;i++) {
		if(ans[i].op==1) printf("1 %d\n",ans[i].x);
		else printf("2 %d %d\n",ans[i].x,ans[i].y);
	}
}
void _() {
	int n,m,k,i; ansn=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++) scanf("%d",a+i);
	st.clear(); emp.clear();
	for(i=1;i<=k;i++) buc[i]=0;
	for(i=1;i<=m;i++) {
		if(!buc[a[i]]) buc[a[i]]=i;
		else to[buc[a[i]]]=i, buc[a[i]]=0;
	}
	// for(i=1;i<=m;i++) printf("%d:%d\n",i,to[i]);
	for(i=1;i<=n;i++) dq[i].clear();
	for(i=1;i<=n;i++) emp.insert(i);
	for(i=1;i<=k;i++) buc[i]=0;
	for(i=1;i<=m;i++) {
		// printf("%d:\n",i);
		if(!buc[a[i]]) {
			buc[a[i]]=i;
			if(st.size()<=1) {
				int u=getemp();
				push(u,i);
			}
			else {
				pair pr=getone();
				if(pr.x<a[i]) {
					int u=getemp();
					if(u!=-1) {push(u,i); continue;}
				}
				push2(pr.id,i);
			}
		} else {
			int pos=wh[buc[a[i]]];
			if(dq[pos].back()==buc[a[i]]) del2(pos,i);
			else {
				int u=getemp();
				if(u==-1);
				else {
					del(pos,u,i);
				}
			}
			buc[a[i]]=0;
		}
	}
	prt();
}
int main() {
	int T=1;
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	 scanf("%d",&T);
	while(T--) _();
	return 0;
}
