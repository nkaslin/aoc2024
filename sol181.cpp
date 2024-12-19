#include "template.h"


void vvprint(vvi& grid) {
    for (int i=0; i<grid.size(); i++) {
        vprint(grid[i]);
    }
    cout << endl;
    return;
}

void pprint(vector<vpi>& parent) {
    for (int i=0; i<parent.size(); i++) {
        for (int j=0; j<parent[0].size(); j++) {
            cout << parent[i][j].fi << "," << parent[i][j].se << " ";
        }
        cout << endl;
    }
}

int N = 71;  // 7, 71

vvi grid(N + 2, vi(N + 2, 0)); 
vvi size_(N + 2, vi(N + 2, 1));

vector<vpi> parent(N + 2, vpi(N + 2));

pi find(pi x) {
    if (parent[x.fi][x.se] == x)
        return x;
    return find(parent[x.fi][x.se]);
}

void union_(pi x, pi y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (size_[x.fi][x.se] < size_[y.fi][y.se])
            swap(x, y);
        parent[y.fi][y.se] = x;
        size_[x.fi][x.se] += size_[y.fi][y.se];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    for (int r=0; r<N+2; r++) {
        for (int c=0; c<N+2; c++) {
            parent[r][c] = {r, c};
        }
    }

    for (int i=2; i<N+2; i++) {
        parent[0][i] = {0, 2};
        parent[N+1-i][N+1] = {0, 2};
        parent[i][0] = {2, 0};
        parent[N+1][N+1-i] = {2, 0};
        grid[0][i] = 1;
        grid[N+1-i][N+1] = 1;
        grid[i][0] = 1;
        grid[N+1][N+1-i] = 1;
    }

    string line;
    int t = 0;
    while (getline(fin, line)) {
        stringstream ss(line); 
        int r, c;
        char comma;
        ss >> c >> comma >> r;
        c++; r++;

        if (ss.fail() || comma != ',' || t > 10000)
            break;

        // cout << t << " " << c << " " << r << endl;
        grid[r][c] = 1;
        for (int dr=-1; dr<2; dr++) {
            for (int dc=-1; dc<2; dc++) {
                if ((dr == 0 && dc == 0) || grid[r+dr][c+dc] == 0)
                    continue;
                union_({r, c}, {r+dr, c+dc});
            }
        }
        if (find({0, 2}).fi == find({2, 0}).fi && find({0, 2}).se == find({2, 0}).se) {
            // vvprint(grid);
            fout << --c << "," << --r << "\n";
            return 1;
        }
        t++;
        // pprint(parent);
    }

    return 0;
}
