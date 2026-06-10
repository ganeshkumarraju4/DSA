class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowMin = 0,rowMax = matrix.size()-1;
        int colMin = 0,colMax = matrix[0].size()-1;
        int i = 0,j = 0;
        vector<int> spiral;
        while(rowMin <= rowMax && colMin <= colMax){
            while(j<=colMax){
                spiral.push_back(matrix[rowMin][j]);
                j++;
            }
            j = colMax;
            rowMin++;
            i++;
            if(rowMin > rowMax) break;
            while(i <= rowMax){
                spiral.push_back(matrix[i][colMax]);
                i++;
            }
            colMax--;
            i = rowMax;
            j--;
            if(colMin > colMax) break;
            while(j >= colMin){
                spiral.push_back(matrix[rowMax][j]);
                j--;
            }
            rowMax--;
            j = colMin;
            if(rowMin > rowMax) break;
            i--;
            while(i >= rowMin){
                spiral.push_back(matrix[i][colMin]);
                i--;
            }
            colMin++;
            i = rowMin;
            j++;
        }
        return spiral;
    }
};