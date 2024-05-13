class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int pointerOne = 0;
        int pointerTwo = people.size() - 1;
        int boatCount = 0;

        while (pointerOne <= pointerTwo) {
            if (people[pointerOne] + people[pointerTwo] <= limit) {
                pointerOne++;
                pointerTwo--;
            } else {
                pointerTwo--;
            }
            boatCount++;
        }

        return boatCount;
    }
};