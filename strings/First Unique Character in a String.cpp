#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int,int>> mp; // {index, count}
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]].second++;
            } else {
                mp[s[i]] = {i, 1};
            }
        }

        int ans = n; // large number
        for (auto &p : mp) {
            if (p.second.second == 1) {
                ans = min(ans, p.second.first);
            }
        }

        return (ans == n) ? -1 : ans;
    }
};
