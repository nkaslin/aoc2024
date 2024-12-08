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

#define vprint(x) for(auto it: x) cout << it << " "; cout << endl;

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

string pattern = "XMAS";
int l = pattern.length();
int n, m;


bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int count(int x, int y, vector<string>& grid) {
    int cnt = 0;
    int ptr;

    ptr = 1;
    while (ptr < l && valid(x + ptr, y) && grid[x+ptr][y] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    ptr = 1;
    while (ptr < l && valid(x, y + ptr) && grid[x][y+ptr] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    ptr = 1;
    while (ptr < l && valid(x + ptr, y + ptr) && grid[x+ptr][y+ptr] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    ptr = 1;
    while (ptr < l && valid(x - ptr, y) && grid[x-ptr][y] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    ptr = 1;
    while (ptr < l && valid(x, y - ptr) && grid[x][y-ptr] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    ptr = 1;
    while (ptr < l && valid(x - ptr, y - ptr) && grid[x-ptr][y-ptr] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    ptr = 1;
    while (ptr < l && valid(x + ptr, y - ptr) && grid[x+ptr][y-ptr] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    ptr = 1;
    while (ptr < l && valid(x - ptr, y + ptr) && grid[x-ptr][y+ptr] == pattern[ptr])
        ptr++;
    if (ptr == l) 
        cnt++;

    return cnt;


}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;
    vector<string> grid;

    while (getline(fin, s)) {
        grid.pb(s);
    }

    n = grid.size(); 
    m = grid[0].length();
    
    ll res = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (grid[i][j] != pattern[0])
                continue;
            res += count(i, j, grid);
        }
    }

    fout << res << "\n";
    return 0;
}
