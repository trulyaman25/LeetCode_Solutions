class Solution {
public:
    int findContentChildren(vector<int>& demand, vector<int>& size) {
        int satisfiedChild = 0;
        int unsatisfiedChild = demand.size();

        int pointerOne = 0;
        int pointerTwo = 0;

        sort(demand.begin(), demand.end());
        sort(size.begin(), size.end());

        while(pointerOne < demand.size() && pointerTwo < size.size()){
            int childDemand = demand[pointerOne];
            int cookieSize = size[pointerTwo];

            if(childDemand <= cookieSize){
                satisfiedChild++;
                unsatisfiedChild--;

                pointerOne++;
                pointerTwo++;
            } else {
                pointerTwo++;
            }
        }

        return satisfiedChild;
    }
};