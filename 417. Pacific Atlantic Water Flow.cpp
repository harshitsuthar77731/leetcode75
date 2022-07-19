class Solution{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &ocean){
        if (i < 0 || i == matrix.size() || j < 0 || j == matrix[0].size() || ocean[i][j] == 1 || matrix[i][j] < prev)
            return;

        ocean[i][j] = 1;
        for (int k = 0; k < 4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(matrix, nx, ny, matrix[i][j], ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights){
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> ans;
        if (n == 0)
            return ans;

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++){
                if (row == 0 || col == 0){
                    dfs(heights, 0, col, INT_MIN, pacific);
                    dfs(heights, row, 0, INT_MIN, pacific);
                }

                if (row == n - 1 || col == m - 1) {
                    dfs(heights, n - 1, col, INT_MIN, atlantic);
                    dfs(heights, row, m - 1, INT_MIN, atlantic);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                if (pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
