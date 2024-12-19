#include "template.h"

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    int x, y;
    string line;

    unordered_set<int> hs;

    while (getline(fin, line)) {
        if (line.empty()) {
            break;
        }

        x = (line[0] - '0') * 10 + (line[1] - '0');
        y = (line[3] - '0') * 10 + (line[4] - '0');

        hs.insert(x + 100 * y);
    }

    int res = 0;
    while (getline(fin, line)) {
        vi cur_order;
        stringstream ss(line);
        string num;

        while (getline(ss, num, ',')) {
            cur_order.push_back(stoi(num));
        }

        // vprint(cur_order);

        bool valid = true;

        for (int i=0; i<cur_order.size(); i++) {
            for (int j=i+1; j<cur_order.size(); j++) {
                if (hs.count(cur_order[i] * 100 + cur_order[j]) != 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid)
                break;
        }



        if (valid) {
            // cout  << cur_order[(cur_order.size() - 1) / 2] << endl;
            res += cur_order[(cur_order.size() - 1) / 2];
        }
    }

    fout << res << "\n";
    return 0;
}
