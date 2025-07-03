class Solution {
private:
    char helper(int k, int level) {
        if(level == 0){
            return 'a';
        } 

        int half = 1 << (level - 1); 

        if(k <= half){
            return helper(k, level - 1);
        } 

        else {
            char ch = helper(k - half, level - 1);
        
            return ((ch - 'a' + 1) % 26) + 'a'; 
        }
    }

public:
    char kthCharacter(int k) {
        int level = 0;
        while((1 << level) < k){
            level++;
        }

        return helper(k, level);
    }
};