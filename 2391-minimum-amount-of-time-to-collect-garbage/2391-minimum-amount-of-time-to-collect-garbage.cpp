class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int metalBus = 0;
        int paperBus = 0;
        int glassBus = 0;

        int lastMHouse = 0;
        int lastPHouse = 0;
        int lastGHouse = 0;
        for(int i = 0; i < garbage.size(); i++){
            for(int j = 0; j < garbage[i].length(); j++){
                if(garbage[i][j] == 'M'){
                    metalBus++;
                    lastMHouse = i;
                } else if(garbage[i][j] == 'P'){
                    paperBus++;
                    lastPHouse = i;
                } else if(garbage[i][j] == 'G'){
                    glassBus++;
                    lastGHouse = i;
                }
            }
        }

        for(int i = 1; i <= lastMHouse; i++){
            metalBus += travel[i - 1];
        }
        for(int i = 1; i <= lastPHouse; i++){
            paperBus += travel[i - 1];
        }
        for(int i = 1; i <= lastGHouse; i++){
            glassBus += travel[i - 1];
        }

        return metalBus + paperBus + glassBus;
    }
};