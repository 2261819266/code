#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=300;
const int M=2e6;
int n,m,k,a[M+5],ans[2*M+5][3],tot;
void record1(int s){
	ans[++tot][0]=1;
	ans[tot][1]=s;
}
void record2(int s1,int s2){
	ans[++tot][0]=2;
	ans[tot][1]=s1;
	ans[tot][2]=s2;
}
int num[2*N+5],lnk[M+5];
struct Stack{
	int s[N+5][3],sum,flag,emp,id[2*N+5];
	void mem(){
		memset(s,0,sizeof s);
		sum=flag=0;
	}
	int cnt(){
		for(int i=1;i<=n;i++)
			if(!s[i][0]&&!s[i][1]&&!s[i][2])
				return emp=i;
		return emp=0;
	}
	void run(int x){
		if(s[x][2]){
			id[s[x][0]]=0;
			s[x][0]=s[x][1];
			s[x][1]=s[x][2];
		}else{
			id[s[x][0]]=0;
			s[x][0]=s[x][1];
		}
	}
	bool Delete(int x){
		for(int i=1;i<=n;i++)
			if(s[i][0]==x&&emp){
				record1(emp);
				record2(i,emp);
				run(i);
				run(emp);
				return true;
			}
		for(int i=1;i<=n;i++)
			if(s[i][0]==x&&!s[i][1]){
				record1(i);
				id[s[i][0]]=0;
				s[i][0]=0;
				if(i==flag)
					flag=0;
				return true;
			}
		for(int i=1;i<=n;i++)
			if(s[i][1]==x&&!s[i][2]){
				record1(i);
				id[s[i][1]]=0;
				s[i][1]=0;
				return true;
			}
		for(int i=1;i<=n;i++)
			if(s[i][2]==x){
				record1(i);
				id[s[i][2]]=0;
				s[i][2]=0;
				return true;
			}
		return false;
	}
	bool Insert(int x){
		for(int i=1;i<=n;i++)
			if(i!=emp&&i!=flag&&!s[i][0]){
				record1(i);
				id[x]=i;
				s[i][0]=x;
				return true;
			}
		for(int i=1;i<=n;i++)
			if(i!=emp&&i!=flag&&!s[i][1]){
				record1(i);
				id[x]=i;
				s[i][1]=x;
				return true;
			}
		return false;
	}
	void pushTop(int x,int nxt){
		record1(id[nxt]);
		id[x]=id[nxt];
		s[id[nxt]][2]=x;
	}
	bool Late(int x){
		for(int i=1;i<=n;i++)
			if(s[i][1]&&!s[i][2]&&lnk[s[i][0]]<lnk[s[i][1]]){
				record1(i);
				id[x]=i;
				s[i][2]=x;
				return true;
			}
		return false;
	}
	void Dig(int x){
		int res=0;
		for(int i=1;i<=n;i++)
			if(res==0||lnk[s[i][0]]<lnk[s[res][0]])
				res=i;
		flag=res;
		record1(emp);
		id[x]=emp;
		s[emp][0]=x;
	}
};
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		Stack S;
		S.mem();
		tot=0;
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		memset(num,0,sizeof num);
		memset(lnk,0,sizeof lnk);
		for(int i=m;i;i--){
			lnk[i]=num[a[i]];
			num[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			int emp=S.cnt();
			num[a[i]]=lnk[i];
			if(S.Delete(a[i]))
				continue;
			if(S.Insert(a[i]))
				continue;
			if(S.s[S.id[a[i+1]]][0]==a[i+1]){
				S.pushTop(a[i],a[i+1]);
				continue;
			}
			if(S.Late(a[i]))
				continue;
			S.Dig(a[i]);
		}
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++){
			if(ans[i][0]==1)
				printf("%d %d\n",ans[i][0],ans[i][1]);
			else
				printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
		}
	}
	return 0;
}
