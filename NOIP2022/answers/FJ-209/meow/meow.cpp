#include<bits/stdc++.h>
#define r(x) x=read()
using namespace std;
int read(){
	//unsigned
	int num=0;
	char a=getchar();
	while(a<'0'||a>'9') a=getchar();
	while(a>='0'&&a<='9'){
		num=(num*10)+a-'0';
		a=getchar();
	}
	return num;
}
int t,n,m,k;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	r(t);
	if(t%10==1){
		int s[305][3];
		string on="1 ",h="\n",tw="2 ",sn;
		while(t--){
			string ans;
			r(n),r(m),r(k);
			sn=to_string(n);
			int op=0,l;
			memset(s,0,sizeof(s));
			for(int i=0;i<m;i++){
				r(l);
				bool al=false;
				for(int i=1;i<=n;i++){
					if(s[i][0]==l){
						al=true;
						if(s[i][1]==0){
							ans+=(on+to_string(i)+h);
							s[i][0]=0;
							op++;
						}
						else{
							ans+=(on+sn+h+tw+to_string(i)+" "+sn+h);
							s[i][0]=s[i][1];
							s[i][1]=0;
							op+=2;
						}
						break;
					}
					else if(s[i][1]==l){
						al=true;
						ans+=(on+to_string(i)+h);
						op++;
						s[i][1]=0;
						break;
					}
				}
				if(!al){
					op++;
					for(int i=1;i<n;i++){
						if(s[i][0]==0){
							ans+=(on+to_string(i)+h);
							al=true;
							s[i][0]=l;
							break;
						}
					}
					if(!al){
						for(int i=1;i<n;i++){
							if(s[i][1]==0){
								ans+=(on+to_string(i)+h);
								s[i][1]=l;
								break;
							}
						}
					}
				}
			}
			cout<<op<<"\n"<<ans;
		}
	}
	else{
		int s[3][3];
		string on="1 ",h="\n",tw="2 ";
		while(t--){
			memset(s,0,sizeof(s));
			r(n),r(m),r(k);
			string ans;
			int l,op=0,zt=-1;
			for(int i=0;i<m;i++){
			bool al=false;
				//cout<<i<<": "<<zt<<endl;
				r(l);
				for(int i=1;i<=2;i++){
					if((s[i][1]==l)||(s[i][0]==l&&s[i][1]==0)){
						if(s[i][1]==l){
							ans+=(on+to_string(i)+h);
							s[i][1]=0;
						}
						else{
							ans+=(on+to_string(i)+h);
							s[i][0]=0;
						}
						op++;
						al=true;
						if(s[1][1]) zt=1;
						else if(s[2][1]) zt=3;
						else if(s[2][0]&&s[1][0]) zt=2;
						else if(s[2][0]) zt=4;
						else if(s[1][0]) zt=0;
						else zt=-1;
						break;
					}
				}
				if(al) continue;
				if(zt==-1){
					s[1][0]=l;
					op++;
					ans+=("1 1\n");
					zt=0;
				}
				else if(zt==0){
					s[1][1]=l;
					op++;
					ans+=("1 1\n");
					zt=1;
				}
				else if(zt==1){
					if(l==s[1][0]){
						op+=2;
						ans+=("1 2\n2 1 2\n");
						s[1][0]=s[1][1];
						s[1][1]=0;
						zt=0;
					}
					else{
						int ne;
						r(ne);
						i++;
						if(ne==s[1][1]){
							ans+=("1 2\n1 1\n");
							op+=2;
							s[2][0]=l;
							s[1][1]=0;
							zt=2;
						}
						else if(ne==l){
							op+=2;
							ans+=("1 1\n1 1\n");
						}
						else if(ne==s[1][0]){
							ans+=("1 1\n1 2\n2 1 2\n");
							op+=3;
							s[1][0]=s[1][1];
							s[1][1]=l;
						}
					}
				}
				else if(zt==2){
					int ne;
					i++;
					r(ne);
					if(ne==l){
						op+=2;
						ans+=("1 1\n1 1\n");
					}
					else if(ne==s[2][0]){
						zt=1;
						ans+=("1 1\n1 2\n");
						s[1][1]=l;
						s[2][0]=0;
					}
					else{
						ans+=("1 2\n1 1\n");
						s[1][0]=0;
						s[2][1]=l;
						zt=3;
					}
				}
				else if(zt==3){
					if(l==s[2][0]){
						op+=2;
						ans+=("1 1\n2 1 2");
						s[2][0]=s[2][1];
						s[2][1]=0;
						zt=4;
					}
					else{
						int ne;
						r(ne);
						i++;
						if(ne==s[2][1]){
							ans+=("1 1\n1 2\n");
							op+=2;
							s[1][0]=l;
							s[2][1]=0;
							zt=2;
						}
						else if(ne==l){
							op+=2;
							ans+=("1 1\n1 1\n");
						}
						else if(ne==s[2][0]){
							ans+=("1 2\n1 1\n2 1 2\n");
							op+=3;
							s[2][0]=s[2][1];
							s[2][1]=l;
						}
					}
				}
				else{
					s[2][1]=l;
					op++;
					ans+=("1 2\n");
					zt=3;
				}
			}
			cout<<op<<"\n"<<ans;
		}
	}
	return 0;
}
