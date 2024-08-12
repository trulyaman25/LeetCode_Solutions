class KthLargest {
    int index = 0;
    vector<int> assetVector;

public:
    KthLargest(int k, vector<int>& nums) {
        index = k;
        assetVector = nums;
    }
    
    int add(int val) {
        assetVector.push_back(val);
        sort(assetVector.rbegin(), assetVector.rend());

        return assetVector[index - 1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */