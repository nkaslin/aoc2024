#include "template.h"


void vvprint(vvi& grid) {
    for (int i=0; i<grid.size(); i++) {
        vprint(grid[i]);
    }
    cout << endl;
    return;
}

int N = 71;  // 7, 71
int T = 1024;

vi dirs = {1, 0, -1, 0, 1};

vvi visited(N, vi(N, 0));

bool valid(int c, int r) {
    return (0 <= c && c < N && 0 <= r && r < N);
}

ll dijkstra(vvi& grid, int sc, int sr, int ec, int er) {

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, sc, sr});

    visited[sr][sc] = 1;

    while (pq.size() > 0) {
        auto [dist, c, r] = pq.top();
        pq.pop();

        // cout << r << " " << c << " " << dir << " "<<cost <<endl;
        if (c == ec && r == er) 
            return -dist;

        for (int d=0; d<4; d++) {
            int nc = c+dirs[d], nr = r+dirs[d+1];
            if (!valid(nc, nr) || visited[nr][nc] == 1 || grid[nr][nc] == 1) {
                continue;
            }
            visited[nr][nc] = 1;
            pq.push({dist-1, nc, nr});


        }
    }

    return -1;

}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    string s;
    vvi grid(N, vi(N, 0));

    int x, y;
    char comma;

    for (int t=0; t<T; t++) {
        fin >> x >> comma >> y;
        grid[y][x] = 1;
        // cout << t << " " << x << " " << y << endl;
    }

    // vvprint(grid);

    fout << dijkstra(grid, 0, 0, N-1, N-1) << "\n";


    return 0;
}
