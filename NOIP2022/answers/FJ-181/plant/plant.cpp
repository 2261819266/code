#include <iostream>
#include <string>
//#incldue <vector>
//#include <utility>
//#include <numeric>
//#include <algorithm>
//#include <functional>
#include <bitset>
//#include <>
using namespace std;


int N,M,n,m,c,f,t;
bool tk1[1005][1005];
string tk[1005];
long long fdc(){
   long long res=0;
   for(int i = 0;i<n;i++){
      for(int j = 0;j<m;j++){
            //cout << "K1";
        if(tk[i][j]=='1')continue;
        //cout << "K2";
        int x1 = i;
        int x2 = i+2;
        if(x2>=n or tk[x2][j]=='1' or tk[i+1][j]=='1') continue;
        //cout << "K3";
            int y1 = j+1;
            int y2 = j+1;
       
        while(x2<n and tk[x2][j]!='1'){

            while(y1<m and tk[x1][y1]!='1' and t[x1][y1] = 1 ){
                t[x1][y1] = 1;
                res++;y1++;y2++;
               // cout << res<<"y1"<<endl;
                //cout << y1;
            }
            while(y2<m and tk[x2][y2]!='1' and t[x1][y1] = 1 ){
                t[x2][y2] = 1;
               res++;y2++;y1++;
                //cout << res<<"y2"<<endl;
                //cout << "!!"<< x2<< "!!" << y2<< endl;
               //cout << y2<<" ";
            }
            x2++;

            y2 =j+1;
            y1=j+1;


        }
      }
   }

  return res;

}


int main()
{
    freopen("plant.in","r",stdin);
    freopen("plant.out","w",stdout);
    cin >> M >>N;

    for(int u =0;u<M;u++){
        if(N == 1){cout << 0 << " " << 0 <<endl;continue;}
        cin >> n >> m >> c >> f;

        for(int i = 0;i<n;i++){
            cin >> tk[i];

        }
        long long rc = fdc()*c;
        if(f==0){cout << (rc*c)%998244353 << " "<<0<<endl;continue;}
        cout << rc <<" "<< endl;


        }

      //for(int i = 0;i<n;i++){
          //  cout <<endl;
          //  for(int j = 0;j<m;j++){
            // cout << tk[i][j] << " ";
//

           // }

      //  }


    return 0;
}

