#include "template.h"

int N = 105;

vvi grid(N, vi(N, -1));

vi dirs = {1, 0, -1, 0, 1};

int dfs(int row, int col) {
    if (grid[row][col] == 9) {
        return 1;
    }
    int res = 0;
    for (int i=0; i<4; i++) {
        if (grid[row+dirs[i]][col+dirs[i+1]] == grid[row][col] + 1) {
            res += dfs(row+dirs[i], col+dirs[i+1]);
        }
    }
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;

    int row = 1;
    int col;
    while (getline(fin, s)) {
        for (col=1; col<=s.length(); col++) {
            grid[row][col] = s[col-1] - '0';
        }
        // vprint(grid[row]);
        row++;
    }

    int res = 0;
    for (int r=1; r<=row; r++) {
        for (int c=1; c<=col; c++) {
            if (grid[r][c] != 0) {
                continue;
            }
            res += dfs(r, c);
        }
    }

    fout << res << "\n";

    return 0;
}
