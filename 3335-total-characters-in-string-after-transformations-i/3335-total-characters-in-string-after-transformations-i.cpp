class Solution {
public:
    long long MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<long long> assetVector(26, 0);
        for(int i = 0; i < s.length(); i++){
            assetVector[s[i] - 'a']++;
        }

        while(t--){
            vector<long long> tempVector(26, 0);
            for(int i = 0; i < tempVector.size(); i++){
                if(i == 25){
                    tempVector[0] = (tempVector[0] + assetVector[25]) % MOD;
                    tempVector[1] = (tempVector[1] + assetVector[25]) % MOD;
                } else {
                    tempVector[i + 1] = (tempVector[i + 1] + assetVector[i]) % MOD;
                }
            }
            assetVector = tempVector;
        }

        long long length = 0;
        for(int i = 0; i < assetVector.size(); i++){
            length = (length + assetVector[i]) % MOD;
        }

        return (int)length;
    }
};