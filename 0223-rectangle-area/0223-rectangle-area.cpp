class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
        // pehle dono rectangles ka area
        int areaA = (ax2 - ax1) * (ay2 - ay1);
        int areaB = (bx2 - bx1) * (by2 - by1);
        
        // overlap rectangle ke bounds
        int overlapX1 = max(ax1, bx1);
        int overlapY1 = max(ay1, by1);
        int overlapX2 = min(ax2, bx2);
        int overlapY2 = min(ay2, by2);
        
        // agar overlap valid hai to area nikalna
        int overlapArea = 0;
        if(overlapX1 < overlapX2 && overlapY1 < overlapY2) {
            overlapArea = (overlapX2 - overlapX1) * (overlapY2 - overlapY1);
        }
        
        return areaA + areaB - overlapArea;
    }
};
