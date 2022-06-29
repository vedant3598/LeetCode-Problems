class Solution {
public:
    vector<vector<int>> wallsAndGates(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        deque<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 0){
                    q.push_back(make_pair(r, c));
                    visited[r][c] = true;
                }
            }
        }
        
        vector<vector<int>> directions = {[1, 0], [-1, 0], [0, 1], [0, -1]};
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                pair<int, int> cell = q.front(); q.pop_front();
                for(int d = 0; d < directions.size(); d++){
                    int r = cell.first + d[i][0];
                    int c = cell.second + d[i][1];
                    if(r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] != -1 && visited[r][c] == false){
                        grid[r][c] = grid[cell.first][cell.second] + 1;
                        visited[r][c] = true;
                        q.push_back(make_pair(r, c));
                    }
                }
            }
        }
        return grid;
    }        
    
    
}
