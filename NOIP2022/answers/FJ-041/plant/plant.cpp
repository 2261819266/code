#include <bits/stdc++.h> 
typedef long long int ll;

ll row[1000][1000],line[1000][1000],mod=998244353;
bool a[1000][1000];

ll read(){
	ll ans=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}

bool read_(){
	char c=getchar();
	while(c!='0'&&c!='1')c=getchar();
	if(c=='0')return false;
	return true;
}

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read(),n,m;
	ll c,f,ans,ans_;
	for(int r=0;r<T;r++){
		memset(a,0,sizeof(a));memset(row,0,sizeof(row));memset(line,0,sizeof(line));
		n=read();m=read();c=read();f=read();
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i][j]=read_();
		for(int i=0;i<n;i++){
			if(a[i][m-1])row[i][m-1]=-1;
			for(int j=m-2;j>=0;j--){
				if(a[i][j])row[i][j]=-1;
				else row[i][j]=row[i][j+1]+1;
		}}
		if(c){
			ans=0;
			for(int j=0;j<m;j++){
				ans_=0;
				for(int i=0;i<n;i++){
					if(a[i][j]){
						ans_=0;
						continue;
					}
					ans=(ans+ans_*row[i][j]%mod)%mod;
					if(i>0&&!a[i-1][j])ans_=(ans_+row[i-1][j])%mod;
			}}
			printf("%d ",ans);
		}
		else printf("0 ");
		if(f){
			for(int j=0;j<m;j++){
				if(a[n-1][j])line[n-1][j]=-1;
				for(int i=n-2;i>=0;i--){
					if(a[i][j])line[i][j]=-1;
					else line[i][j]=line[i+1][j]+1;
			}}
			ans=0;
			for(int j=0;j<m;j++){
				ans_=0;
				for(int i=0;i<n;i++){
					if(a[i][j]){
						ans_=0;
						continue;
					}
					ans=(ans+(ans_*row[i][j]%mod)*line[i][j]%mod)%mod;
					if(i>0&&!a[i-1][j])ans_=(ans_+row[i-1][j])%mod;
			}}
			printf("%d\n",ans);
		}
		else printf("0\n");
	}
	return 0;
}
