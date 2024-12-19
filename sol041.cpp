#include "template.h"

int n, m;


bool valid(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool check(int x, int y, vector<string>& grid) {
    int cntS = 0;
    int cntM = 0;
    int ptr;

    if (valid(x+1, y+1)) {
        if (grid[x+1][y+1] == 'S') {
            cntS++;
        } else if (grid[x+1][y+1] == 'M') {
            cntM++;
        }
    }

    if (valid(x-1, y+1)) {
        if (grid[x-1][y+1] == 'S') {
            cntS++;
        } else if (grid[x-1][y+1] == 'M') {
            cntM++;
        }
    }

    if (valid(x+1, y-1)) {
        if (grid[x+1][y-1] == 'S') {
            cntS++;
        } else if (grid[x+1][y-1] == 'M') {
            cntM++;
        }
    }

    if (valid(x-1, y-1)) {
        if (grid[x-1][y-1] == 'S') {
            cntS++;
        } else if (grid[x-1][y-1] == 'M') {
            cntM++;
        }
    }

    if (cntM == 2 && cntS == 2 && grid[x-1][y-1] != grid[x+1][y+1]) 
        return 1;
    return 0;

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
            if (grid[i][j] != 'A')
                continue;
            res += check(i, j, grid);
        }
    }

    fout << res << "\n";
    return 0;
}
