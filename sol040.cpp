#include "template.h"

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
