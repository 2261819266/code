#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T,n,m,k,op,a[302][302],b[10000];//a是栈，b是牌堆 n, m, k，分别表示栈的个数、卡牌的个数、卡牌上图案的种类。
	cin>>T;
	for(int round=0;round<T;round++){
		op=0;
		cin>>n>>m>>k;
		for(int i=1;i<=m;i++){
			cin>>b[i];
		}
		if(T%1000==1){
			int y[302]={},top=1;
			while(m-top>=0){
				bool flag=false;
				for(int i=1;i<=n;i++){
					if(a[i][y[i]]==b[top]){
						y[i]--;
						top++;
						op++;
						flag=true;
						break;
					}else if(a[i][y[i]-1]==b[top]){
						top++;
						a[i][y[i]-1]=a[i][y[i]];
						y[i]--;
						op+=2;
						flag=true;
						break;
					}
				}
				if(!flag){
					for(int i=1;i<=n;i++){
						if(y[i]<2){
							y[i]++;
							a[i][y[i]]=b[top];
							top++;
							op++;
							break;
						}
					}
				}
			}
			cout<<op<<endl;
			for(int i=1;i<=n;i++) y[i]=0;
			top=1;
			while(m-top>=0){
				bool flag=false;
				for(int i=1;i<=n;i++){
					if(a[i][y[i]]==b[top]){
						cout<<1<<" "<<i<<endl;
						y[i]--;
						top++;
						op++;
						flag=true;
						break;
					}else if(a[i][y[i]-1]==b[top]){
						top++;
						a[i][y[i]-1]=a[i][y[i]];
						y[i]--;
						op+=2;
						flag=true;
						cout<<1<<" "<<n<<endl;
						cout<<2<<" "<<i<<" "<<n<<endl;
						break;
					}
				}
				if(!flag){
					for(int i=1;i<=n;i++){
						if(y[i]<2){
							cout<<1<<" "<<i<<endl;
							y[i]++;
							a[i][y[i]]=b[top];
							top++;
							op++;
							break;
						}
					}
				}
			}
		}else if(T%1000==2){
			int top=1,y=0,s=0,flag=1;//s缓存 flag主栈 
			while(top<=m){
				if(b[top]==s){
					top++;
					op++;
					s=0;
				}else if(y==0){
					op++;
					y++;
					a[1][y]=b[top];
					top++;
				}else if(y==1){
					if(b[top]==a[1][y]){
						top++;
						y--;
						op++;
					}else if(s!=0&&b[top+1]==a[1][y]){
						op+=2;
						a[1][1]=s;
						a[1][2]=b[top];
						top+=2;
						y++;
						s=0;
					}else{
						a[1][++y]=b[top++];
						op++;
					}
				}else if(y==2){
					if(b[top]==a[1][2]){
						y--;
						top++;
						op++;
					}else if(b[top]==a[1][1]){
						a[1][1]=a[1][2];
						top++;
						op+=2;
					}else if(b[top+1]==b[top]){
						op+=2;
						top+=2;
					}else if(b[top+1]==a[1][1]){
						a[1][1]=a[1][2];
						a[1][2]=b[top];
						top+=2;
						op+=3;
					}else{
						s=b[top];
						y--;
						op+=2;
						top+=2;
					}
				}
			}
			cout<<op<<endl;
			top=1;
			y=0;
			s=0;
			for(int i=0;i<=3;i++) a[1][i]=0;
			while(top<=m){
				if(b[top]==s){
					cout<<1<<" "<<3-flag<<endl;
					top++;
					op++;
					s=0;
				}else if(y==0){
					cout<<1<<" "<<flag<<endl;
					op++;
					y++;
					a[1][y]=b[top];
					top++;
				}else if(y==1){
					if(b[top]==a[1][y]){
						cout<<"1 "<<flag<<endl;
						top++;
						y--;
						op++;
					}else if(s!=0&&b[top+1]==a[1][y]){
						flag=3-flag;
						cout<<"1 "<<flag<<endl<<"1 "<<3-flag<<endl;
						op+=2;
						a[1][1]=s;
						a[1][2]=b[top];
						top+=2;
						s=0;
						y++;
					}else{
						cout<<"1 "<<flag<<endl;
						a[1][++y]=b[top++];
						op++;
					}
				}else if(y==2){
					if(b[top]==a[1][2]){
						y--;
						top++;
						op++;
						cout<<"1 "<<flag<<endl;
					}else if(b[top]==a[1][1]){
						a[1][1]=a[1][2];
						top++;
						op+=2;
						cout<<"1 "<<3-flag<<endl<<"2 1 2"<<endl;
					}else if(b[top+1]==b[top]){
						cout<<"1 "<<flag<<endl<<"1 "<<flag<<endl;
						op+=2;
						top+=2;
					}else if(b[top+1]==a[1][1]){
						cout<<"1 "<<flag<<endl<<"1 "<<3-flag<<endl<<"2 1 2"<<endl;
						a[1][1]=a[1][2];
						a[1][2]=b[top];
						top+=2;
						op+=3;
					}else{
						cout<<"1 "<<3-flag<<endl<<"1 "<<flag<<endl;
						s=b[top];
						y--;
						op+=2;
						top+=2;
					}
				}
			}
		}
	}
	return 0;
}

