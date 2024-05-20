class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> hashMap;
        for(int i = 0; i < emails.size(); i++){
            string email = "";
            bool flag = false;
            bool atFlag = false;
            for(int j = 0; j < emails[i].length(); j++){
                if (emails[i][j] == '+') {
                    flag = true;
                } else if (emails[i][j] == '@') {
                    flag = false;
                    atFlag = true;
                }

                if(emails[i][j] != '.' && !flag && !atFlag){
                    email += emails[i][j];
                } else if(atFlag){
                    email += emails[i][j];   
                }
            }
            hashMap[email]++;
        }

        return hashMap.size();
    }
};