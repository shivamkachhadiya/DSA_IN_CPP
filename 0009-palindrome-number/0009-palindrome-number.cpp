class Solution {
public:
    bool isPalindrome(int x) {
               int dum=x;

        int revnum=0;
        while(x!=0){
            int lastdigit=x%10;
              if (revnum > INT_MAX / 10 || revnum < INT_MIN / 10) {
                return false;
            }
            revnum=(revnum*10)+lastdigit;
            x=x/10;
            

        }


        if(dum>=0&&dum==revnum&&revnum>=0){
            return true;
        }else{
            return false;
        }
        
    }
};