class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
      
        for (auto& q_w : queries) {
            for (auto& dict_w : dictionary) {
                int d_count = 0;
              
                for (int i = 0; i < q_w.size(); ++i) {
                    if (q_w[i] != dict_w[i]) {
                        d_count++;
                    }
                }
              
                if (d_count <= 2) {
                    result.emplace_back(q_w);
                    break;  
                }
            }
        }
      
        return result;
    }
};
