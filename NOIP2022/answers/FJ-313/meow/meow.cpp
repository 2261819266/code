#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
int t,n,m,k,top[305],bottom[305],c[605],v[605],op[2000005],cnt,a[2000005],kong,tem;
pair<int,int>s[2000005];
queue<int>q1,q2;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--){
		cnt=0;
		memset(c,0,sizeof c);
		memset(top,0,sizeof top);
		memset(bottom,0,sizeof bottom);
		n=read(),m=read(),k=read();
		while(q1.size())q1.pop();
		while(q2.size())q2.pop();
		if(k==2*n-2){
			for(register int i = 1;i<n;i++)q1.push(i),q2.push(i);
			for(register int i = 1,x;i<=m;i++){
				x=read();
				if(c[x]){
					if(v[x]==0){
						op[++cnt]=1,s[cnt]={n,0};
						op[++cnt]=2,s[cnt]={c[x],n};
						if(top[c[x]]){
							v[top[c[x]]]=0;
							bottom[c[x]]=top[c[x]];
							top[c[x]]=0;
							q1.push(c[x]);
						}
						else q2.push(c[x]),bottom[c[x]]=0;
					}
					else{
						op[++cnt]=1,s[cnt]={c[x],0};
						q1.push(c[x]);
						top[c[x]]=0;
					}
					c[x]=0;
				}
				else if(q2.size()){
					op[++cnt]=1,s[cnt]={q2.front(),0};
					bottom[q2.front()]=x,c[x]=q2.front(),v[x]=0;
					q2.pop();
				}
				else{
					op[++cnt]=1,s[cnt]={q1.front(),0};
					top[q1.front()]=x,c[x]=q1.front();v[x]=1;
					q1.pop();
				}
			}
		}
		else if(n==2){
			for(register int i = 1;i<=m;i++)a[i]=read();
			kong = 1;
			for(register int x,i = 1;i<=m;i++){
				x=a[i];
				if(c[x]==kong){
					if(!v[x]){
						if(!bottom[3-kong]){
							op[++cnt]=1,s[cnt]={3-kong,0};
							op[++cnt]=2,s[cnt]={kong,3-kong};
						}
						else op[++cnt]=1,s[cnt]={kong,0};
						if(tem){
							v[tem]=0;c[tem]=kong,bottom[kong]=tem;tem=0;
						}
						else if(top[kong]){
							v[top[kong]]=0;
							bottom[kong]=top[kong];
							top[kong]=0;
						}
						else {
							bottom[kong]=0;
							if(bottom[3-kong])kong = 3-kong;
						}
					}
					else {
						op[++cnt]=1,s[cnt]={kong,0};
						if(tem){
							v[tem]=1,c[tem]=kong,top[kong]=tem;tem=0;
						}
						else top[kong]=0;
					}
					c[x]=0;
				}
				else if (c[x]==3-kong){
					op[++cnt]=1,s[cnt]={3-kong,0};
					bottom[3-kong]=0;
					c[x]=0;
				}
				else if(!bottom[kong]){
					op[++cnt]=1,s[cnt]={kong,0};
					bottom[kong]=x,c[x]=kong,v[x]=0;
				}
				else if(!top[kong]){
					op[++cnt]=1,s[cnt]={kong,0};
					top[kong]=x,c[x]=kong,v[x]=1;
				}
				else{
					register int j;
					for(j = i+1;a[j]==a[i]&&j<=m;j++);
					if((j-i)%2==0){
						for(register int k = i;k<j;k++)op[++cnt]=1,s[cnt]={kong,0};
						i=j-1;
						continue;
					}
					else{
						for(register int k = i;k<j-1;k++)op[++cnt]=1,s[cnt]={kong,0};
						i=j-1;
					}
					for(j = i+2;a[j]==a[i+1]&&j<=m;j++);
					if(a[i+1]==bottom[kong]){
						if((j-i-1)%2==1){
							op[++cnt]=1,s[cnt]={kong,0};
							op[++cnt]=1,s[cnt]={3-kong,0};
							op[++cnt]=2,s[cnt]={kong,3-kong};
							for(register int k = i+2;k<j;k++)op[++cnt]=1,s[cnt]={3-kong,0};
							i=j;
							c[bottom[kong]]=0;
							bottom[kong]=top[kong],v[top[kong]]=0;
							top[kong]=x,c[x]=kong,v[x]=1;
						}
						else{
							op[++cnt]=1,s[cnt]={kong,0};
							op[++cnt]=1,s[cnt]={3-kong,0};
							op[++cnt]=2,s[cnt]={kong,3-kong};
							for(register int k = i+2;k<j-1;k++)op[++cnt]=1,s[cnt]={3-kong,0};
							c[bottom[kong]]=0;
							bottom[kong]=top[kong],v[top[kong]]=0;
							top[kong]=x,c[x]=kong,v[x]=1;
							i=j-1;
						}
					}
					else{
						if((j-i-1)%2==1){
							op[++cnt]=1,s[cnt]={3-kong,0};
							bottom[3-kong]=x;c[x]=3-kong;
							for(register int k = i+1;k<j;k++)op[++cnt]=1,s[cnt]={kong,0};
							c[top[kong]]=0,top[kong]=0;
							i=j;
						}
						else{
							op[++cnt]=1,s[cnt]={kong,0};
							c[top[kong]]=0;
							top[kong]=x,c[x]=kong,v[x]=1;
							for(register int k = i+1;k<j;k++)op[++cnt]=1,s[cnt]={3-kong,0};
							tem=a[i+1];
						}
					}
					i--;
				}
			}
		}
		printf("%d\n",cnt);
		for(register int i=1;i<=cnt;i++){
			if(op[i]==1)printf("%d %d\n",op[i],s[i].first);
			else printf("2 %d %d\n",s[i].first,s[i].second);
		}
	}
	return 0;
}
