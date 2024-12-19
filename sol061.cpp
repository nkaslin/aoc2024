#include "template.h"

struct TupleHash {
    std::size_t operator()(const std::tuple<int, int, int>& t) const {
        std::size_t h1 = std::hash<int>()(std::get<0>(t));
        std::size_t h2 = std::hash<int>()(std::get<1>(t));
        std::size_t h3 = std::hash<int>()(std::get<2>(t));
        return h1 ^ (h2 << 1) ^ (h3 << 2); // Combine hashes
    }
};

bool has_loop(vector<string>& grid, int r_obs, int c_obs, int srow, int scol) {

    int row = srow, col = scol;

    int m = grid[0].length(), n = grid.size();

    auto valid = [n, m](int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < m);
    };

    vi dirs = {-1, 0, 1, 0, -1};
    int cur_dir = 0;

    unordered_set<tuple<int, int, int>, TupleHash> hit_obstacles;

    while (true) {

        while (valid(row, col) && grid[row][col] != '#') {
            row += dirs[cur_dir];
            col += dirs[cur_dir + 1];
        }

        if (valid(row, col)) {
            if (hit_obstacles.count({row, col, cur_dir}) > 0) {
                return 1;
            }
            hit_obstacles.insert({row, col, cur_dir});
        } else {
            return 0;
        }
        row -= dirs[cur_dir];
        col -= dirs[cur_dir + 1];
        cur_dir++;
        cur_dir %= 4;
    }

    return 0;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;
    vector<string> grid;

    string test ="abcd";
    cout<<test<<endl;
    test[2] = '#';
    cout<<test<<endl;

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

    // vector<vector<bool>> visited(n, vector<bool>(m, 0));

    // auto valid = [n, m](int row, int col) {
    //     return (row >= 0 && row < n && col >= 0 && col < m);
    // };

    // vi dirs = {-1, 0, 1, 0, -1};
    // int cur_dir = 0;

    // unordered_set<tuple<int, int, int>, TupleHash> hit_obstacles;

    // while (true) {

    //     while (valid(row, col) && grid[row][col] != '#') {
    //         if (!visited[row][col]) {
    //             visited[row][col] = 1;
    //         }
    //         row += dirs[cur_dir];
    //         col += dirs[cur_dir + 1];
    //     }

    //     if (valid(row, col)) {
    //         if (hit_obstacles.count({row, col, cur_dir}) > 0) {
    //             break;
    //         }
    //         hit_obstacles.insert({row, col, cur_dir});
    //     } else {
    //         break;
    //     }
    //     row -= dirs[cur_dir];
    //     col -= dirs[cur_dir + 1];
    //     cur_dir++;
    //     cur_dir %= 4;
    // }

    int res = 0;
    for (int r=0; r<m; r++) {
        for (int c=0; c<n; c++) {
            // if (!visited[r][c])
                // continue;
            if (grid[r][c] != '.') {
                continue;
            }
            grid[r][c] = '#';
            if (has_loop(grid, r, c, row, col)) {
                res++;
                // cout << r <<" "<<c<<endl;
            }
            grid[r][c] = '.';
        }
    }

    fout << res << endl;
    return 0;
}
