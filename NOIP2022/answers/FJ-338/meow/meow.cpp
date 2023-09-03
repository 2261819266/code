#include <iostream>
#include <deque>
#include <vector>
using namespace std;
const int maxn=2000011;
int a[maxn],b[501],c[maxn];
deque<int> q[501];
vector<string> s;

inline int read(){
	char ch;
	bool flag=false;
	while((ch=getchar())&&(ch<'0'||ch>'9'))
		if(ch=='-') flag=true;
	int res=ch^48;
	while((ch=getchar())&&(ch>='0'&&ch<='9'))
		res=(res<<3)+(res<<1)+(ch^48);
	return flag?~res+1:res;
}

int dfs(int k,int m,int n,bool pos){
	if(k>m) return 0;
	if(c[k]!=0){
		dfs(k+1,m,n,0);
		return c[k];
	}
	else{
		int j=0;
		for(int i=n;i>=1;i--){
			if(b[i]==a[k]){
				c[k]=i;
				b[i]=a[k];
				j=-1;
				break;
			}
			if(b[i]==0) j=i;
		}
		if(j==-1){
			if(pos==0) dfs(k+1,m,n,0);
			return c[k];
		}
		else if(j!=0){
			b[j]=a[k];
			c[k]=j;
			if(pos==0) dfs(k+1,m,n,0);
			return c[k];
		}
		else{
			int x=dfs(k+1,m,n,1);
			int j=0;
			for(int i=n;i>=1;i--){
				if(b[i]==a[k]){
					j=i;
					break;
				}
				if(i!=x) j=i;
			}
			b[j]=a[k];
			c[k]=j;
			dfs(k+1,m,n,0);
			return c[k];
		}
	}
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,m,k,ans,l;
	t=read();
	while(t--){
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=m;i++) a[i]=read();
		l=dfs(1,m,n,0);
		ans=0;
		for(int i=1;i<=m;i++){
			if(q[c[i]].empty()){
				q[c[i]].push_back(a[i]);
				ans++;
				string k="1 ";
				k+=c[i]+'0';
				s.push_back(k);
			}
			else{
				q[c[i]].push_back(a[i]);
				ans++;
				string k="1 ";
				k+=c[i]+'0';
				s.push_back(k);
				if(q[c[i]][q[c[i]].size()-1]==q[c[i]][q[c[i]].size()-2]){
					q[c[i]].pop_back();
					q[c[i]].pop_back();
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(!q[i].empty()){
				for(int j=i+1;j<=n;j++){
					if(!q[j].empty()){
						if(q[i][0]==q[j][0]){
							q[i].pop_front();
							q[j].pop_front();
							ans++;
							string k="2 ";
							k+=i+'0';
							k+=' ';
							k+=j+'0';
							s.push_back(k);
						}
					}
				}
			}
				
		}
		cout<<ans<<endl;
		for(int i=0;i<s.size();i++) cout<<s[i]<<endl;
	}
	
	return 0;
}
