#include "template.h"

void vvprint(vvi& grid) {
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return;
}

int N = 205;

vvi grid(N, vi(N, -1));
vvi group(N, vi(N, -1));

vi dirs = {1, 0, -1, 0, 1};


int dfs(int row, int col, int g, int s) {
    if (group[row][col] != -1 || grid[row][col] != s) {
        return 0;
    }
    // cout<<row<<" "<<col<<endl;
    group[row][col] = g;
    int size = 1;
    for (int i=0; i<4; i++) {
        size += dfs(row+dirs[i], col+dirs[i+1], g, s);
    }
    return size;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;

    vi group_size;
    vi tot_perim;

    int row = 1;
    int col;
    while (getline(fin, s)) {
        for (col=1; col<=s.length(); col++) {
            grid[row][col] = s[col-1] - 'A';
        }
        row++;
    }

    // vvprint(grid);
    // vvprint(group);

    int size;
    
    int cur_group = 0;
    for (int r=1; r<row; r++) {
        for (int c=1; c<col; c++) {
            if (group[r][c] == -1) {
                size = dfs(r, c, cur_group++, grid[r][c]);
                group_size.pb(size);
                tot_perim.pb(4 * size);
                // cout<<"--->"<<r<<" "<<c<<" "<<size<<endl;
            }
            
            for (int i=0; i<4; i++) {
                if (group[r][c] == group[r+dirs[i]][c+dirs[i+1]]) {
                    tot_perim[group[r][c]]--;
                }
            }
        }
    }

    // vvprint(group);
    // vprint(tot_perim);

    ll res = 0;
    for (int g=0; g<cur_group; g++) {
        res += group_size[g] * tot_perim[g];
    }

    fout << res << "\n";

    return 0;
}
