class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end(),greater<int>());

        int bots=0;
        int currWeight=0;//9 4 6 1

        int start=0;
        int end=people.size()-1;

        while(start<=end){
            if(people[start]+people[end]<=limit){
                bots++;
                start++;
                end--;
            }else if(people[start]>=people[end]){
                bots++;
                start++;
            }else{
                bots++;
                end--;
            }
        }
        return bots;

        
    }
};