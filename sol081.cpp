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
