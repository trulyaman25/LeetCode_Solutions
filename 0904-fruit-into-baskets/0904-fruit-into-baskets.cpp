class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int pointerOne = 0;
        int pointerTwo = 0;
        int maxFruits = 0;
        unordered_map<int, int> fruitFrequency;
        
        while(pointerTwo < fruits.size()){
            fruitFrequency[fruits[pointerTwo]]++;
            
            while(fruitFrequency.size() > 2 && pointerOne < fruits.size()){
                fruitFrequency[fruits[pointerOne]]--;
                if(fruitFrequency[fruits[pointerOne]] <= 0){
                    fruitFrequency.erase(fruits[pointerOne]);
                }
                pointerOne++;
            }

            maxFruits = max(pointerTwo - pointerOne + 1, maxFruits);
            pointerTwo++;
        }

        return maxFruits;
    }
};