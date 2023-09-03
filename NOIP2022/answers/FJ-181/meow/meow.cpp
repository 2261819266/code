#include <iostream>
#include <string>
//#incldue <vector>
//#include <utility>
//#include <numeric>
//#include <algorithm>
//#include <functional>
//#include <bitset>
#include <sstream>
#include <deque>
using namespace std;


int N,n,k,m,t;

deque<int> de;
deque<int> de1;
deque<int> de2;
deque<int> de3;
int main(){
    freopen("meow.in","r",stdin);
    freopen("meow.out","w",stdout);
     cin >> N;
     for(int u = 0;u<N;u++){
        cin >> n >> m >> k;

        for(int i =0;i<m;i++){cin >> t;de.push_front(t);}
        if(N<=1005 and n!=3){
                int res = 1;
         ostringstream os;
            de1.push_front(de.back());
            de.pop_back();
            os << 1 <<" "<< 1 <<endl;
            while(!de.empty()){

                int a = de.back();
                if(a==de1.front()){de1.pop_front();de.pop_back();os << 1 << " "<<1<<endl;res++;}
                else{de1.push_front(a);os << 1 << " "<<1<<endl;res++;de.pop_back();if(de.back() == de1.back()){os << 1 << " "<<2<<endl;os<< 2 <<" "<< 1 <<" "<< 2<<endl;res+=2;de.pop_back();de1.pop_back();}}


            }
            cout << res << endl<<os.str();



           de.clear();
           de1.clear();
           de2.clear();
           de3.clear();
        }

     }
    return 0;
}

