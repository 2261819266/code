#include <iostream>

using std::cin;
using std::cout;

void T392401() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    T392401();
    return 0;
}