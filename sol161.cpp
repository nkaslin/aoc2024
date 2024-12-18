#include "template.h"

void vvprint(vvi& grid) {
    for (int i=0; i<grid.size(); i++) {
        vprint(grid[i]);
    }
    cout << "\n";
    return;
}

vi dirs = {1, 0, -1, 0, 1};

ll dijkstra(vvi& grid, int sc, int sr, int sd, int ec, int er, int ed) {

    vector<vvi> visited;
    for (int i=0; i<4; i++) {
        visited.pb(grid);
    }

    priority_queue<tuple<ll, int, int, int>> pq;
    pq.push({0, sc, sr, sd});

    visited[0][sr][sc] = 1;

    while (pq.size() > 0) {
        auto [cost, c, r, dir] = pq.top();
        pq.pop();

        // cout << r << " " << c << " " << dir << " "<<cost <<endl;
        if (c == ec && r == er && (ed == 5 || dir == ed)) 
            return -cost;
        
        if (visited[dir][r + dirs[dir+1]][c + dirs[dir]] == 0) {
            pq.push({cost - 1, c + dirs[dir], r + dirs[dir+1], dir});
            visited[dir][r + dirs[dir+1]][c + dirs[dir]] = 1;
        }

        if (visited[(dir + 1) % 4][r][c] == 0) {
            pq.push({cost - 1000, c , r, (dir + 1) % 4});
            visited[(dir + 1) % 4][r][c] = 1;
        }

        if (visited[(dir + 3) % 4][r][c] == 0) {
            pq.push({cost - 1000, c , r, (dir + 3) % 4});
            visited[(dir + 3) % 4][r][c] = 1;
        }
    }

    return -1;

}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;
    vvi grid;

    vector<vector<pair<int, int>>> locs(128);

    int s_row, s_col, e_row, e_col;

    int row = 0;
    int m;
    while (getline(fin, s)) {
        vi grid_row;
        for (int col=0; col<s.length(); col++) {
            if (s[col] == 'E') {
                e_row = row;
                e_col = col;
            } else if (s[col] =='S') {
                s_row = row;
                s_col = col;
            }
            grid_row.pb((s[col] == '#' ? 1 : 0));
        }
        grid.pb(grid_row);
        grid_row.clear();
        row++;
    }

    int opt = dijkstra(grid, s_col, s_row, 0, e_col, e_row, 5);

    cout<<opt<<endl;
    
    int res = 0;
    for (int r=1; r<grid.size()-1; r++) {
        cout << r << "/" << grid.size()-1 << "  res = " << res <<endl;
        for (int c=1; c<grid[0].size()-1; c++) {
            for (int d=0; d<4; d++) {
                if (grid[r][c] == 1)
                    continue;
                
                int dist = (
                    dijkstra(grid, s_col, s_row, 0, c, r, d) + 
                    dijkstra(grid, c, r, d, e_col, e_row, 5)
                );
                if (dist == opt) {
                    res++;
                    break;
                }

            }
        }
    }

    fout << res << "\n";



    return 0;
}
