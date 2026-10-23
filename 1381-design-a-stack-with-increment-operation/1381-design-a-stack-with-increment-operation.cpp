class CustomStack {
public:
    vector<int>st;
    int index=-1;
    int maxSize;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(index==maxSize-1){
            return;
        }
        index++;
        st[index]=x;
    }
    
    int pop() {
        if(index==-1)return -1;
        int val=st[index];
        index--;
        return val;
    }
    
    void increment(int k, int val) {
        int limit=min(k,index+1);
        for(int i=0;i<limit;i++){
            st[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */