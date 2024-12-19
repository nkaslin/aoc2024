#include "template.h"

int get_n_digits(ll x) {
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ofstream fout ("out.txt");
    
    string s;
    // vll stones = {125, 17};
    vll stones = {77, 515, 6779622, 6, 91370, 959685, 0, 9861};

    unordered_map<ll, ll> stone_counts;
    for (ll& s: stones) {
        stone_counts[s]++;
    }

    cout << "->"<<__cplusplus << endl;

    cout << pow(10,0)<<endl;
    for (int i=0; i<75; i++) {
        unordered_map<ll, ll> next_stone_counts;
        for (const auto& [s, c]: stone_counts) {
            int n_digits = get_n_digits(s);
            if (s == 0) {
                next_stone_counts[1] += c;
            } else if (n_digits % 2 == 0) {
                int p = pow(10, n_digits / 2);
                // cout<<p<<" "<<n_digits<<endl;
                next_stone_counts[s / p] += c;
                next_stone_counts[s % p] += c;
            } else {
                next_stone_counts[s * 2024] += c;
            }
        }
        stone_counts = next_stone_counts;
        next_stone_counts.clear();
        // vprint(stones);
    }

    ll res = 0;
    for (const auto& [s, c]: stone_counts) {
        res += c;
    }

    fout << res << "\n";

    return 0;
}
