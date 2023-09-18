#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Find parent of given node, return -1 if oldest */
int find_parent(const vector<vector<bool> >& edges, int root) {
    int N = edges.size();
    for(int i = 0; i < N; i++) {
        if(edges[root][i]) { // only one parent possible
            return i;
        }
    }
    return -1;
}

int LCA(const vector<vector<bool> >& edges, int l, int r) {
    int N = edges.size();
    vector<int> parents; // left's parents
    int parent = l;
    while(parent != -1) {
        parent = find_parent(edges, parent);
        parents.push_back(parent);
    }

    parent = r; // now check right side for overlap
    while(parent != -1) {
        parent = find_parent(edges, parent);
        if(find(parents.begin(), parents.end(), parent) != parents.end()) {
            return parent; // first shared dependency
        }
    }
    return -1; // sentinel
}

int dfs(const vector<vector<bool> >& edges, const vector<int>& lens, int root) {
    int page_sum = 0;
    int N = edges.size();
    int parent = root;
    while(parent != -1) {
        page_sum += lens[parent];
        parent = find_parent(edges, parent);
    }
    return page_sum;
}

int dfs2(const vector<vector<bool> >& edges, const vector<int>& lens, int root1, int root2) {
    int t = root1;
    int N = edges.size();
    int page_sum = lens[t];
    while(t != root2) {
        t = find_parent(edges, t);

        if(t != root2) {
            page_sum += lens[t];
        }
    }
    return page_sum;
}

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> lens(n + 1);
    for(int i = 0; i < n; i++) cin >> lens[i + 1]; // 1 indexed

    vector<vector<bool> > edges(n + 1, vector<bool>(n + 1, false));

    vector<bool> is_root(n + 1, true);
    is_root[0] = false;

    for(int i = 0; i < m; i++) { // get edges
        int a, b;
        cin >> a >> b;
        edges[b][a] = true; 
        is_root[a] = false;
    }
    int min_pages = INT_MAX;

    for(int l = 0; l <= n; l++) {
        for(int r = l + 1; r <= n; r++) { // choose two roots
            if(is_root[l] && is_root[r]) { 
                int cumsum = 0;
                // overlapping subtrees, so no memo is possible
                int root_overlap = LCA(edges, l, r);
                if(root_overlap == -1) { // no shared dependencies
                    cumsum = dfs(edges, lens, l) + dfs(edges, lens, r);
                } else {
                    int overlap = dfs(edges, lens, root_overlap);
                    int l_path = dfs2(edges, lens, l, root_overlap);
                    int r_path = dfs2(edges, lens, r, root_overlap);
                    // path to ancestor + overlap
                    cumsum = overlap + l_path + r_path;
                }
                min_pages = min(min_pages, cumsum);
            }

        }
    }
    cout << min_pages << "\n";
}