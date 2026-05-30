class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }
    
    Node* build(vector<vector<int>>& grid, int x, int y, int len) {
        // check if all values same
        bool same = true;
        int val = grid[x][y];
        for(int i = x; i < x + len; i++) {
            for(int j = y; j < y + len; j++) {
                if(grid[i][j] != val) {
                    same = false;
                    break;
                }
            }
            if(!same) break;
        }
        
        if(same) {
            // leaf node
            return new Node(val == 1, true);
        }
        
        // divide into 4 parts
        int half = len / 2;
        Node* topLeft = build(grid, x, y, half);
        Node* topRight = build(grid, x, y + half, half);
        Node* bottomLeft = build(grid, x + half, y, half);
        Node* bottomRight = build(grid, x + half, y + half, half);
        
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
