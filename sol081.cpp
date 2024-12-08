#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pll>> vvpll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define len(x) ((ll)(x).size())
#define vprint(x) for(auto it: x) cout << it << " "; cout << endl;

constexpr ll mod = 1e9 + 7; // 998244353;
constexpr double eps = 1e-12;
constexpr double PI = acos(-1);

// simplifies res = max(res, x) to smax(res, x)
template<typename T, typename U> void smax(T &a, const U &b) { if (a < b) a = b; }
template<typename T, typename U> void smin(T &a, const U &b) { if (a > b) a = b; }

namespace io {
    // define re, pr, de (used with the dbg macro)
    template<class T, class... U> void re(T&& a, U&&... b) {
        cin >> forward<T>(a); 
        (int[]){(cin >> forward<U>(b), 0)...};
    }
    template<class T, class... U> void print(T&& a, U&&... b) {
        cout << forward<T>(a); 
        (int[]){(cout << " " << forward<U>(b), 0)...};
        cout << "\n";
    }
    template<class T, class... U> void de(T&& a, U&&... b) {
        cerr << forward<T>(a); 
        (int[]){(cerr << " " << forward<U>(b), 0)...};
        cerr << "\n";
    }
}

using namespace io;

#define dbg(...) { cerr << "[Line " << __LINE__ << "] " << #__VA_ARGS__ << " is "; io::de(__VA_ARGS__); }

struct TupleHash {
    std::size_t operator()(const std::tuple<int, int, int>& t) const {
        std::size_t h1 = std::hash<int>()(std::get<0>(t));
        std::size_t h2 = std::hash<int>()(std::get<1>(t));
        std::size_t h3 = std::hash<int>()(std::get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2); // Combine hashes
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;
    vector<string> grid;

    vector<vector<pair<int, int>>> locs(128);



    int cur_row = 0;
    int m;
    while (getline(fin, s)) {
        if (cur_row == 0)
            m = s.length();
        grid.pb(s);
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '.')
                continue;
            locs[(int) s[i]].pb({cur_row, i});
        }
        cur_row++;
    }

    int n = cur_row;

    vector<vector<bool>> antinode(n, vector<bool>(m, 0));

    auto valid = [n, m](int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    };

    int res = 0;

    int dr, dc, r1, r2, c1, c2, mult;
    for (int i=0; i<128; i++) {
        for (int j=0; j<locs[i].size(); j++) {
            for (int k=j+1; k<locs[i].size(); k++) {
                r1 = locs[i][j].fi; 
                r2 = locs[i][k].fi;
                c1 = locs[i][j].se; 
                c2 = locs[i][k].se;
                dr = r1 - r2;
                dc = c1 - c2;

                mult = 0;
                while (valid(r1 + mult * dr, c1 + mult * dc)) {
                    if (!antinode[r1 + mult * dr][c1 + mult * dc]) {
                        res++;
                        antinode[r1 + mult * dr][c1 + mult * dc] = 1;
                        grid[r1 + mult * dr][c1 + mult * dc] = '#';
                    }
                    mult++;
                }
                mult = 0;
                while (valid(r2 - mult * dr, c2 - mult * dc)) {
                    if (!antinode[r2 - mult * dr][c2 - mult * dc]) {
                        res++;
                        antinode[r2 - mult * dr][c2 - mult * dc] = 1;
                        grid[r2 - mult * dr][c2 - mult * dc] = '#';
                    }
                    mult++;
                }
            }
        }
    }

    // for (auto g: grid) {
    //     cout<<g<<endl;
    // }

    fout << res << endl;

    return 0;
}
