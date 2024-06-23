#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int ans = 0;
    std::map<char, int> mp;
    for (auto i : s)
        mp[i]++;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (k && mp[i] != mp[i - 'a' + 'A'])
        {
            int x = abs(mp[i] - mp[i - 'a' + 'A']) / 2;
            x = std::min(x, k);
            k -= x;
            mp[i] += x;
            mp[i - 'a' + 'A'] += x;
        }
        ans += std::min(mp[i], mp[i - 'a' + 'A']);
    }
    std::cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T = 1;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}