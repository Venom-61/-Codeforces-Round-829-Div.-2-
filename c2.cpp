#include<bits/stdc++.h>
using namespace std;

#define ll long long 

// C2. Make Nonzero Sum (hard version)

void solve() {
    int n;             
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ones += abs(a[i]);
    }

    if(ones == 0) {
        cout << 1 << "\n";
        cout << 1 << " " << n << "\n";
        return ;
    }

    if(ones % 2 == 1) {
        cout << (-1) << "\n";
        return ;
    }

    vector<pair<int,int>> ans;
    int segSum = 0, prev = -1,parity = 1, segStart = 0;

    for(int i = 0; i < n; i++) {
        if(parity == 1)
            segSum += a[i];
        else 
            segSum -= a[i];
        
        parity ^= 1;

        if(a[i] != 0) {
            if(prev == -1) {
                prev = i;
            } else {
                if(segSum == 0) {
                    ans.push_back({segStart, i});
                    prev = -1;
                    segStart = i + 1;
                    parity = 1;
                    continue;
                }

                if(a[segStart] == 0){
                    if((i - prev + 1) % 2 == 0){
                        ans.push_back({segStart, prev - 1});
                        ans.push_back({prev, i - 1});
                        ans.push_back({i, i});
                    } else {
                        ans.push_back({segStart, prev - 1});
                        ans.push_back({prev, prev});
                        ans.push_back({prev + 1, i});
                    }
                } else {
                    int len = i - prev + 1;
                    if(len % 2 == 0){
                        ans.push_back({prev, i - 1});
                        ans.push_back({i, i});
                    } else {
                        ans.push_back({prev, prev});
                        ans.push_back({prev + 1, i});
                    }
                }
                prev = -1;
                segStart = i + 1;
                segSum=0;
                parity =1;
            }
        }
    }

    if(a[n - 1] == 0){
        ans.push_back({n - 1, n - 1});
        for(int i = n - 1; a[i] == 0; i--){
            ans.back().first = i;
        }
    }

    cout << ans.size() << "\n";
    for(auto i : ans){
        cout << (i.first + 1) << " " << (i.second + 1) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);

    int tc = 1;                  
    cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}
