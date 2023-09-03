#include<bits/stdc++.h>
using namespace std;
deque<int> q[309];
int siz[309];
int sheng[309];
int T,n,m,k,id,x,f,cnt,rcd,bi,sum;
int read(){
	int out=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=0;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		out=(out<<3)+(out<<1)+(c^48);
		c=getchar();
	}
	if(f) return out;
	return ~(out-1);
}
struct oh{
	int cz,id1,id2;//caozuobianhao
}ans[4000006];
set<int> s;
bool cmp(int a,int b){return a>b;}
int check(int cnt){
	int out=cnt;
	for(int i=1;i<=cnt;i++)
		if(q[i].empty()) sheng[i]=0,out--;
	sort(sheng+1,sheng+cnt,cmp);
	reverse(sheng+1,sheng+out+1);
	return out;
}
void find(int t,int v){
	for(int o=1;o<=sum;o++){
		int i=sheng[o];
		if(q[i].back()==v){
			++cnt;
			ans[cnt].cz=2;ans[cnt].id1=i;ans[cnt].id2=t;
			q[i].pop_back();q[t].pop_back();
			siz[i]--;siz[t]--;
			break;
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();id=T&7;
	while(T--){
		n=read();m=read();k=read();sum=cnt=0;
		for(int i=1;i<=m;i++){
			x=read();f=0;
			rcd=0;bi=2000006;
			for(int j=1;j<=n;j++){
				if(q[j].empty()){if(!f){f=1;rcd=j;bi=0;}continue;}
				if(bi>siz[j]) rcd=j,bi=siz[j];
				if(q[j].front()==x){
					q[j].pop_front();f=2;
					cnt++;
					ans[cnt].cz=1;ans[cnt].id1=j;
					siz[j]--;
					break;
				}
			}
			if(f==2) continue;
			if(f==1)
				for(int j=1;j<=n;j++){
					if(q[j].empty()) continue;
					if(q[j].back()==x){
						q[j].pop_back();f=3;
						cnt+=2;
						ans[cnt-1].cz=1;ans[cnt-1].id1=rcd;
						ans[cnt].cz=2;ans[cnt].id1=rcd;ans[cnt].id2=j;
						siz[j]--;
						break;
					}
				}
			if(f==0||f==1){
				siz[rcd]++;q[rcd].push_front(x);
				cnt++;
				ans[cnt].cz=1;ans[cnt].id1=rcd;
			}
		}
		for(int j=1;j<=n;j++) if(!q[j].empty()) sheng[++sum]=j;
		while(sum){
			s.clear();
			for(int j=1;j<=sum;j++){
				int p=sheng[j];int r=s.size();
				s.insert(q[p].back());
				if(s.size()==r){
					find(p,q[p].back());
					break;
				}
			}
			sum=check(sum);
		}
		printf("%d\n",cnt);
		for(int j=1;j<=cnt;j++)
			if(ans[j].cz==1) printf("1 %d\n",ans[j].id1);
			else printf("2 %d %d\n",ans[j].id1,ans[j].id2);
	}
	return 0;
}
