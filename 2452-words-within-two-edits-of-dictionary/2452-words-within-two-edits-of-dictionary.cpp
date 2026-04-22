class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
      
        for (auto& queryWord : queries) {
            for (auto& dictWord : dictionary) {
                int differenceCount = 0;
              
                for (int i = 0; i < queryWord.size(); ++i) {
                    if (queryWord[i] != dictWord[i]) {
                        differenceCount++;
                    }
                }
              
                if (differenceCount <= 2) {
                    result.emplace_back(queryWord);
                    break;  
                }
            }
        }
      
        return result;
    }
};
