class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int rows = rooms.size();
        int cols = rooms[0].size();
        vector<vector<bool>> visited(rows, vector<int>(cols, false));
        deque<pair<int, int>> gates;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(rooms[r][c] == 0){
                    gates.push_back(make_pair(r, c));
                    visited[r][c] = true;
                }
            }
        }

        int dist = 1;
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, 1}};
        while(!gates.empty()){
            int len = gates.size();
            for(int i = 0; i < len; i++){
                pair<int, int> cell = gates.front();
                gates.pop_front();
                int row = cell.first;
                int col = cell.second;
                for(int j = 0; j < dir.size(); j++){
                    int r = row + dir[j][0];
                    int c = col + dir[j][1];
                    if(r >= 0 && r < rows && c >= 0 && c < cols && !visited[r][c] && rooms[r][c] == INT_MAX){
                        rooms[r][c] = dist;
                        gates.push_back(make_pair(r, c));
                        visited[r][c] = true;
                    }
                }
            }
            dist++;
        }
    }
};
