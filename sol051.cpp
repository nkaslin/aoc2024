#include "template.h"

int n = 105;
vector<vector<int>> adj(n); // adjacency list of graph
vector<bool> visited;
vector<int> ts;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ts.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ts.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(all(ts));
}

bool in(vi& v, int x) {
    for (int& y: v) {
        if (y == x)
            return true;
    }
    return false;
}

vi order(vi& v) {
    vi res;
    for (int& x: ts) {
        if (in(v, x)) {
            res.pb(x);
        }
    }
    return res;
}


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
        adj[x].pb(y);
    }

    topological_sort();
    vprint(ts);

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



        if (!valid) {
            // cout  << cur_order[(cur_order.size() - 1) / 2] << endl;
            res += order(cur_order)[(cur_order.size() - 1) / 2];
        }
    }

    fout << res << "\n";
    return 0;
}
