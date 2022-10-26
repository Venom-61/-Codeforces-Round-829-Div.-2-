#include<bits/stdc++.h>
using namespace std;

#define ll long long

// B. Kevin and Permutation 

void solve() {
    int n;
    cin >> n;
    if(n <= 3) {
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << endl;
        return ;
    }

    if(n % 2 == 0) {
        int k = n / 2;
        for(int i = k; i >= 1; i--) {
            cout << i << " " << i + k << " ";
        }
        cout << "\n";
    } else {
        int k = ++n / 2;
        for(int i = 1; i < k; i++) {
            cout << i << " " << i + k << " ";
        }
        cout << k << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
