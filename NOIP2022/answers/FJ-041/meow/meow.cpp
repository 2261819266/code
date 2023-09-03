#include <bits/stdc++.h> 

int a[2000000],nxt[2000000],nxt_[605],front[300];
std::queue<int> que;
std::vector<int> s[300],ope,num,num2;

int read(){
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
    int T=read(),n,m,k,l=0,mini,x;
    bool v;
    for(int r=0;r<T;r++){
    	memset(nxt,0,sizeof(nxt));memset(nxt_,0,sizeof(nxt_));
		memset(front,0,sizeof(front));ope.clear();num.clear();num2.clear();
    	n=read();m=read();k=read();
    	for(int i=0;i<m;i++)a[i]=read();
    	for(int i=m-1;i>=0;i--){
    		nxt[i]=nxt_[a[i]];
    		nxt_[a[i]]=i;
		}
		
		s[0].push_back(0);
		for(int i=0;i<m;i++){
			v=false;
			for(int j=0;j<n;j++){
				if(s[j].size()>front[j]&&a[s[j][s[j].size()-1]]==a[i]){
					s[j].pop_back();
					ope.push_back(1);num.push_back(j+1);
					v=true;
					break;
			}}
			if(v)continue;
			
			v=false;
			mini=-1;
			for(int j=0;j<n;j++){
				if(s[j].size()==front[j]){
					mini=j;
					break;
			}}
			if(mini!=-1){
				for(int j=0;j<n;j++){
					if(s[j].size()>front[j]&&a[s[j][front[j]]]==a[i]){
						s[mini].push_back(i);ope.push_back(1);num.push_back(mini+1);
						que.push(mini);
						v=true;
						break;
			}}}
			if(v){
				while(!que.empty()){
					x=que.front();
					que.pop();
					for(int j=0;j<n;j++){
						if(j!=x&&s[j].size()>front[j]&&a[s[j][front[j]]]==a[s[x][front[x]]]){
							front[x]++;front[j]++;
							if(s[j].size()>front[j])que.push(j);
							if(s[x].size()>front[x])que.push(x);
							ope.push_back(2);num.push_back(j+1);num2.push_back(x+1);
							break;
				}}}
				continue;
			}
			
			mini=-1;
			for(int j=0;j<n;j++){
				if(s[j].size()>front[j]&&nxt[s[j][s[j].size()-1]]>nxt[i]){
					if(mini==-1){
						mini=j;
						continue;
					}
					if(nxt[s[j][s[j].size()-1]]<nxt[s[mini][s[mini].size()-1]])mini=j;
			}}
			if(mini==-1){
				v=false;
				for(int j=0;j<n;j++){
					if(s[j].size()==front[j]){
						ope.push_back(1);num.push_back(j+1);
						s[j].push_back(i);
						v=true;
						break; 
				}}
				if(v)continue;
				mini=0;
				for(int j=1;j<n;j++)
					if(nxt[s[j][s[j].size()-1]]>nxt[s[mini][s[mini].size()-1]])mini=j;
				ope.push_back(1);
				num.push_back(mini+1);
				s[mini].push_back(i);
				continue;
			}
			ope.push_back(1);
			num.push_back(mini+1);
			s[mini].push_back(i);
		}
		
		printf("%d\n",ope.size());
		for(int i=0,j=0;i<ope.size();i++){
			printf("%d %d",ope[i],num[i]);
			if(ope[i]==2)printf(" %d",num2[j++]);
			printf("\n");	
	}}
	return 0;
}
