#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    for (int tc = 1; tc <= t; tc++) {
        int n;
        cin >> n;
 
        vector<long long> arr(n);
        for (auto& i : arr) {
            cin >> i;
        }
 
        long long ans = 0, cur_max = arr[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (cur_max < arr[i]) {
                cur_max = arr[i];
            }
            else {
                ans += cur_max - arr[i];
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }
 
    return 0;
}