#include <vector>
#include <string>

using namespace std;

class Robot {
public:
    Robot(int width, int height) {
        pos.emplace_back(vector<int>{0, 0}, "South");
        for (int i = 1; i < width; ++i)
            pos.emplace_back(vector<int>{i, 0}, "East");
        for (int j = 1; j < height; ++j)
            pos.emplace_back(vector<int>{width - 1, j}, "North");
        for (int i = width - 2; i >= 0; --i)
            pos.emplace_back(vector<int>{i, height - 1}, "West");
        for (int j = height - 2; j > 0; --j)
            pos.emplace_back(vector<int>{0, j}, "South");
        isOrigin = true;
        idx = 0;
    }
    
    void step(int numSteps) {
        if (numSteps == 0) return;
        isOrigin = false;
        idx = (idx + (long long)numSteps) % pos.size();
    }
    
    vector<int> getPos() {
        return pos[idx].first;
    }
    
    string getDir() {
        return isOrigin ? "East" : pos[idx].second;
    }

private:
    bool isOrigin;
    int idx;
    vector<pair<vector<int>, string>> pos;
};