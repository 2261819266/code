#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

const int maxn = 2e4 + 1;

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
typedef vector<string> strings;


// const vector<int> VECTOR_INT_INIT(26, 0);
class Trie {
#define word (i - 'A')
#define pw a[p][word]
    struct Node {
        int a[26];
        int data;
        int &operator[](int x) { return a[x]; }
        int operator*() { return data; }
        int operator=(int x) { return data = x; }
    } NODE_INIT = {};
    vector<Node> a;
    static const int root = 0;
public:
    Trie() {
        a.assign(1, NODE_INIT);
    }

    int insert(const string &s, int x) {
        int p = root;
        for (int i : s) {
            if(!pw) pw = a.size(), a.push_back(NODE_INIT);
            p = pw;
        }
        return a[p] = x;
    }

    Node &operator[](const string &s) {
        int p = root;
        for (int i : s) {
            if(!pw) pw = a.size(), a.push_back(NODE_INIT);
            p = pw;
        }
        return a[p];
    }
} st;



struct Sentence {
    int speaker;
    bool k;
    int who;
    bool is;
    int day;
} a[maxn];
int n, m, q, now;

const string weekDay[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};



int main() {
#ifdef LOCAL
    LOCALfo
#endif
    string s;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        st[s] = i;
    }
    while (m--) {
        cin >> s;

    }
}
