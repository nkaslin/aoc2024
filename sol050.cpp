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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    int x, y;
    string line;

    unordered_set<int> hs;

    while (getline(fin, line)) {
        if (line.empty()) {
            break;
        }

        x = (line[0] - '0') * 10 + (line[1] - '0');
        y = (line[3] - '0') * 10 + (line[4] - '0');

        hs.insert(x + 100 * y);
    }

    int res = 0;
    while (getline(fin, line)) {
        vi cur_order;
        stringstream ss(line);
        string num;

        while (getline(ss, num, ',')) {
            cur_order.push_back(stoi(num));
        }

        // vprint(cur_order);

        bool valid = true;

        for (int i=0; i<cur_order.size(); i++) {
            for (int j=i+1; j<cur_order.size(); j++) {
                if (hs.count(cur_order[i] * 100 + cur_order[j]) != 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }



        if (valid) {
            // cout  << cur_order[(cur_order.size() - 1) / 2] << endl;
            res += cur_order[(cur_order.size() - 1) / 2];
        }
    }

    fout << res << "\n";
    return 0;
}
