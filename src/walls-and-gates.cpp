class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int rows = rooms.size();
        int cols = rooms[0].size();
        deque<pair<int, int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(rooms[r][c] == 0){
                    visited[r][c] = true;
                    q.push_back(make_pair(r, c));
                }
                if(rooms[r][c] == -1){
                    visited[r][c] = true;
                }
            }
        }

        int dist = 1;
        while(!q.empty()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                pair<int, int> room = q.front();
                q.pop_front();
                for(int j = 0; j < dir; j++){
                    int r = room.first + dir[j][0];
                    int c = room.second + dir[j][1];
                    if(r >= 0 && r < rows && c >= 0 && c < cols && !visited[r][c]){
                        visited[r][c] = true;
                        rooms[r][c] = dist;
                        q.push_back(make_pair(r, c));
                    }
                }
            }
            dist++;
        }
    }
};
