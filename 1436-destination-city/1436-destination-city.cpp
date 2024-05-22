class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> hashMap;
        for(int i = 0; i < paths.size(); i++){
            hashMap[paths[i][0]] = paths[i][0];
        }
        for(int i = 0; i < paths.size(); i++){
            for(int j = 0; j < paths[i].size(); j++){
                if(!hashMap.count(paths[i][j])){
                    return paths[i][j];
                }
            }
        }
        return "";
    }
};