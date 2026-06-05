class PeekingIterator : public Iterator {
    int nextVal;
    bool hasVal;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        if (Iterator::hasNext()) {
            nextVal = Iterator::next();
            hasVal = true;
        } else {
            hasVal = false;
        }
    }
    
    // Returns the next element without advancing
    int peek() {
        return nextVal;
    }
    
    int next() {
        int ret = nextVal;
        if (Iterator::hasNext()) {
            nextVal = Iterator::next();
            hasVal = true;
        } else {
            hasVal = false;
        }
        return ret;
    }
    
    bool hasNext() const {
        return hasVal;
    }
};
