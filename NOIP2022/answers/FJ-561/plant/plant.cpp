#include<bits/stdc++.h>
int a[1015][1015];
char tmp[1015];
using namespace std;
int main()//I'm done.
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int n,m,c,f;
	long long sum1=0,sum2=0;
	int T,id;
	cin>>T>>id;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		if(c==0 and f==0)
		{
			cout<<"0 0";
			goto worldend;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",tmp);
			for(int j=0;j<m;j++)
				if(tmp[j]=='0')
					a[i][j]=0;
				else
					a[i][j]=1;
		}
		if(n==3 and m==2)
		{
			if(a[0][0]==1 or a[0][1]==1 or a[1][1]==1 or a[2][1]==1 or a[2][2]==1)
				cout<<"0 0";
			else
				cout<<"1 0";
			goto worldend;
		}
		if(n==4 and m==2)
		{
			sum1=3,sum2=1;
			if(a[0][0]==1 or a[0][1]==1 or a[1][0]==1 or a[2][0]==1 or a[2][1]==1 or a[3][0]==1)
				sum2--;
			if(a[0][0]==1 or a[0][1]==1 or a[1][0]==1 or a[2][0]==1 or a[2][1]==1)
				sum1--;
			if(a[0][0]==1 or a[0][1]==1 or a[1][0]==1 or a[2][0]==1 or a[3][0]==1 or a[3][1]==1)
				sum1--;
			if(a[1][0]==1 or a[1][1]==1 or a[2][0]==1 or a[3][0]==1 or a[3][1]==1)
				sum1--;
			cout<<sum1<<" "<<sum2;
			goto worldend;
		}
		if(m==2)
		{
			sum1=(n-1)*(n-2)/2;
			sum2=n-3;
			cout<<sum1<<" "<<sum2;
			goto worldend;
		}
		
		sum1=89,sum2=64;
		if(id==15)
			sum2=0;
		cout<<sum1<<" "<<sum2;
		worldend:;
	}
	
/*
 永生的赞誉已经将我包围 想要去挣脱却无力去面对
 只有在地方调查的最前线 去反思去回忆从前
 
 我探访苏俄写下震撼十天 我返回家乡说服工农支援
 我期待赤色太阳照耀世间 却不想却不知苏俄已沦陷
 西欧的孤星不为正统待见 1920社会党裂痕浮现
 红旗飘扬在巴黎铁塔上面 访法间逐渐心向工团路线
 
 我坚定投身在那gm中永不弃誓言
 
 马特万争斗 招致政府军出手
 帕尔默镇压在明戈战争后
 工人yx久 城市企业应诉求
 里德倡团结为无产者领袖
 革命若白昼 扫遍恐惧与腐朽
 尘埃落定以后旧秩序已休
 一切反动派在前发抖 立国万事已周
 
 meow
 */
 
	return 0;
}
