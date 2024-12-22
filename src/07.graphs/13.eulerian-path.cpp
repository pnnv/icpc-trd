// Theme: Eulerian Path

int sz;

vector<vector<int>> graph;

// Algorithm: Eulerian Path
// Complexity: O(M)

vector<int> eul;

// 0 - path not exist
// 1 - cycle exits 
// 2 - path exists
int euler_path() {
    vector<int> deg(sz);

    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            deg[i] += g[i][j];

    int v1 = -1, v2 = -1;
    for (int i = 0; i < sz; i++)
        if (deg[i] & 1)
            if (v1 == -1) v1 = i;
            else if (v2 == -1) v2 = i;
            else return 0;

    if (v1 != -1) {
        if (v2 == -1)
            return 0;
        graph[v1][v2]++;
        graph[v2][v1]++;
    }

    stack<int> st;
    
    for (int i = 0; i < sz; i++) {
        if (deg[i]) {
            st.push(i);
            break;
        }
    }

    while (st.size()) {
        int u = st.top();

        int ind = -1;
        
        for (int i = 0; i < sz; i++)
            if (graph[u][i]) {
                ind = i;
                break;
            }

        if (ind == -1) {
            eul.push_back(u);
            st.pop();
        }
        else {
            graph[u][ind]--;
            graph[ind][u]--;
            st.push(ind);
        }
    }

    int res = 2;
    if (v1 != -1) {
        res = 1;

        for (int i = 0; i < eul.size() - 1; i++)
            if (eul[i] == v1 && eul[i + 1] == v2 ||
            eul[i] == v2 && eul[i + 1] == v1) {
                vector<int> teul;
                for (int j = i + 1; j < eul.size(); j++)
                    teul.push_back(eul[j]);
                for (int j = 0; j <= i; j++)
                    teul.push_back(eul[j]);
                eul = teul;
                break;
            }
    }

    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            if (graph[i][j])
                return 0;

    return res;
}