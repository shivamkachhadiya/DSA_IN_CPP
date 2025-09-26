class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        //jese hi new node visit kro mark in vector

        visited[node] = 1;
        
        //ye for loop each row ke liye chalegi
        
        for (int j = 0; j < isConnected.size(); j++) {
            //iska matalab node connected hona chahiye
            // but usko vector mei visit mark na kiya ho matalb vo visted nahi hei
            //visit krne ke liye dfs call lagaoo
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n + 1, 0);
        int count = 0;

        //ye main outer loop hei.. jo 0 se mat.size tak jayegi
        //jo vector mei mark rakhegi and count karegi
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};