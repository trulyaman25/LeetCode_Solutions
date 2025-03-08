class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int pointerOne = 0;
        int pointerTwo = 0;

        int whiteCount = 0;
        int repaintedBlocks = INT_MAX;
        while(pointerTwo < k){
            if(blocks[pointerTwo] == 'W'){
                whiteCount++;
            }
            pointerTwo++;
        }

        repaintedBlocks = min(repaintedBlocks, whiteCount);

        while(pointerTwo < blocks.size()){
            if(blocks[pointerTwo] == 'W'){
                whiteCount++;
            }

            if(blocks[pointerOne] == 'W'){
                whiteCount--;
            }

            if(pointerTwo - pointerOne == k){
                repaintedBlocks = min(repaintedBlocks, whiteCount);
            }

            pointerOne++;
            pointerTwo++;
        }

        return repaintedBlocks;
    }
};