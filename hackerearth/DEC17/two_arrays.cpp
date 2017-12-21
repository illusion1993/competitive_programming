/*
6 9 4
3 5 2 4 5 7
4 8 5 4 7 2 3 2 6
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[200000], b[200000];
long long ans;

void solve(int s) {
    ans = 0;
    unordered_map<int, int> a_map;
    unordered_map<int, int> b_map;
    // unordered_map<int, int>::const_iterator tmp;

    int mat_num, l;
    
    for (int i = s - 1; i < m; i++) {
        l = s; mat_num = 0;
        a_map.clear(); b_map.clear();
        
        
        for (int x = i - l + 1; x <= i; x++) {
            if (b_map.find(b[x]) == b_map.end()) 
                b_map[b[x]] = 0;
            b_map[b[x]]++;
        }
        for (int x = 0; x < l; x++) {
            if (a_map.find(a[x]) == a_map.end()) 
                a_map[a[x]] = 0;
            a_map[a[x]]++;
        }
        for (auto it : a_map) { 
            if (b_map.find(it.first) != b_map.end()) {
                mat_num += (it.second * b_map[it.first]);
            }
        }
        
        for (int j = s - 1; j < n; j++) {
            if (mat_num < k) {
                // increase l till no margin or mat_num >= k
                while (mat_num < k && j + 1 > l && i + 1 > l) {
                    l++;

                    if (a_map.find(a[j - l + 1]) == a_map.end()) 
                        a_map[a[j - l + 1]] = 0;
                    a_map[a[j - l + 1]]++;
                    
                    if (b_map.find(a[j - l + 1]) != b_map.end())
                        mat_num += b_map[a[j - l + 1]];
                    
                    if (b_map.find(b[i - l + 1]) == b_map.end())
                        b_map[b[i - l + 1]] = 0;
                    b_map[b[i - l + 1]]++;
                    
                    if (a_map.find(b[i - l + 1]) != a_map.end())
                        mat_num += a_map[b[i - l + 1]];
                }
                
                if (mat_num >= k) 
                    ans += (min(i, j) - l + 2);
            }
            else {
                // decrese l till mat_num >= k
                while (mat_num >= k && l > s) {
                    l--;
                    
                    a_map[a[j - l]]--;
                    if (b_map.find(a[j - l]) != b_map.end()) 
                        mat_num -= b_map[a[j - l]];
                    
                    b_map[b[i - l]]--;
                    if (a_map.find(b[i - l]) != a_map.end())
                        mat_num -= a_map[b[i - l]];
                }
                // write dp
                if (mat_num < k) 
                    ans += (min(i, j) - (l + 1) + 2);
                else 
                    ans += (min(i, j) - l + 2);
            }
            // Add j + 1th number from a in a_map, add its occ in b_map to mat_num
            if (a_map.find(a[j + 1]) == a_map.end())
                a_map[a[j + 1]] = 0;
            a_map[a[j + 1]]++;
            if (b_map.find(a[j + 1]) != b_map.end())
                mat_num += b_map[a[j + 1]];
            
            // Remove j - l + 1th num from a_map, subtract its occ in b_map from mat_num
            a_map[a[j - l + 1]]--;
            if (b_map.find(a[j - l + 1]) != b_map.end())
                mat_num -= b_map[a[j - l + 1]];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    
    int s = sqrt(k);
    if (s * s < k) s++;
    
    solve(s);

    cout << ans;
    
    return 0;
}