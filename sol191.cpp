#include "template.h"

const int K = 26;

struct Vertex {
    int next[K];
    bool output = false;

    Vertex() {
        fill(begin(next), end(next), -1);
    }
};

vector<Vertex> trie(1);
ll memo[9999];

void add_string(string const& s) {
    int v = 0;
    for (char chr : s) {
        int c = chr - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back(Vertex());
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

ll rec(string const& s, int i) {
    if (memo[i] != -1)
        return memo[i];
    Vertex cur = trie[0];
    ll res = 0;
    for (int j=i; j<s.length(); j++) {
        if (cur.next[s[j] - 'a'] == -1) {
            memo[i] = res;
            return res;
        } else {
            cur = trie[cur.next[s[j] - 'a']];
            if (cur.output) {
                res += rec(s, j+1);
            }
        }
    }
    memo[i] = res;
    return res;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    ifstream fin ("in.txt");
    ofstream fout ("out.txt");

    vector<string> patterns;

    string line;

    if (getline(fin, line)) {
        stringstream lineStream(line);
        string token;

        while (std::getline(lineStream, token, ',')) {
            token.erase(0, token.find_first_not_of(" \t"));
            token.erase(token.find_last_not_of(" \t") + 1);
            patterns.push_back(token);
        }
    }

    for (string const& s: patterns) {
        add_string(s);
    }

    ll res = 0;
    getline(fin, line);
    int i = 0;
    while (getline(fin, line)) {
        fill(begin(memo), end(memo), -1);
        memo[line.length()] = 1;
        // cout << line << " " << rec(line, 0) << endl;
        res += rec(line, 0);
    }

    fout << res << "\n";
    return 0;
}
