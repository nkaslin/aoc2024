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

    int col, row;

    int cur_row = 0;
    while (getline(fin, s)) {
        grid.pb(s);
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '^') {
                col = i;
                row = cur_row;
            }
        }
        cur_row++;
    }

    int m = grid[0].length(), n = grid.size();

    vector<vector<bool>> obs_added(n, vector<bool>(m, 0));

    auto valid = [n, m](int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    };

    auto validNoObs = [&](int row, int col) {
        return valid(row, col) && grid[row][col] != '#' && !obs_added[row][col];
    };

    vi dirs = {-1, 0, 1, 0, -1};
    int cur_dir = 0;

    vvi hist(4, vi(max(n, m), -1));
    for (int i=0; i<max(n, m); i++) {
        hist[2][i] = max(n, m);
        hist[3][i] = max(n, m);
    }

    unordered_set<tuple<int, int, int>, TupleHash> hit_obstacles;

    int res = 0;
    while (true) {

        while (valid(row, col) && grid[row][col] != '#') {

            if (cur_dir == 0) {
                if (hist[cur_dir][row] > col 
                    && validNoObs(row + dirs[cur_dir], col + dirs[cur_dir+1])
                ) {
                    res++;
                    obs_added[row + dirs[cur_dir]][col + dirs[cur_dir+1]] = 1;
                }
            } else if (cur_dir == 1) {
                if (hist[cur_dir][col] > row 
                    && validNoObs(row + dirs[cur_dir], col + dirs[cur_dir+1])
                ) {
                    res++;
                    obs_added[row + dirs[cur_dir]][col + dirs[cur_dir+1]] = 1;
                }
            } else if (cur_dir == 2) {
                if (hist[cur_dir][row] < col 
                    && validNoObs(row + dirs[cur_dir], col + dirs[cur_dir+1])
                ) {
                    res++;
                    obs_added[row + dirs[cur_dir]][col + dirs[cur_dir+1]] = 1;
                }
            } else {
                if (hist[cur_dir][col] < row 
                    && validNoObs(row + dirs[cur_dir], col + dirs[cur_dir+1])
                ) {
                    res++;
                    obs_added[row + dirs[cur_dir]][col + dirs[cur_dir+1]] = 1;
                }
            }
            
            row += dirs[cur_dir];
            col += dirs[cur_dir + 1];
        }

        // for (int i=0; i<n; i++) {
        //     vprint(visited[i]);
        // }
        // cout<<res<<endl;

        if (valid(row, col)) {
            if (hit_obstacles.count({row, col, cur_dir}) > 0) {
                fout << res << endl;
                return 0;
            }
            hit_obstacles.insert({row, col, cur_dir});
            if (cur_dir == 0) {
                hist[3][col] = min(hist[3][col], row);
            } else if (cur_dir == 1) {
                hist[0][row] = max(hist[0][row], col);
            } else if (cur_dir == 2) {
                hist[1][col] = max(hist[1][col], row);
            } else {
                hist[2][row] = min(hist[2][row], col);
            }
            
        } else {
            fout << res << endl;
            return 0;
        }
        row -= dirs[cur_dir];
        col -= dirs[cur_dir + 1];
        cur_dir++;
        cur_dir %= 4;
    }

    return 0;
}
