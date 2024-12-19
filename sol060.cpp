#include "template.h"

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

    vector<vector<bool>> visited(n, vector<bool>(m, 0));

    auto valid = [n, m](int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    };

    vi dirs = {-1, 0, 1, 0, -1};
    int cur_dir = 0;

    unordered_set<tuple<int, int, int>, TupleHash> hit_obstacles;

    int res = 0;
    while (true) {

        while (valid(row, col) && grid[row][col] != '#') {
            if (!visited[row][col]) {
                res++;
                visited[row][col] = 1;
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
