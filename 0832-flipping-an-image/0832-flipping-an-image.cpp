class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            int pointerOne = 0;
            int pointerTwo = image[0].size() - 1;

            while(pointerOne <= pointerTwo){
                if(image[i][pointerOne] == 0 && image[i][pointerTwo] == 0){
                    image[i][pointerOne] = 1;
                    image[i][pointerTwo] = 1;
                } else if (image[i][pointerOne] == 1 && image[i][pointerTwo] == 1){
                    image[i][pointerOne] = 0;
                    image[i][pointerTwo] = 0;
                }
                pointerOne++;
                pointerTwo--;
            }
        }

        return image;
    }
};