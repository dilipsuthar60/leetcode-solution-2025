class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        int pointerX=0, pointerY=colSize-1; // two to visiting our matrix

        while(pointerX<rowSize&&pointerY>=0){
            if(matrix[pointerX][pointerY]==target){ // case we finding traget element
                return true;
            }
            if(matrix[pointerX][pointerY]>target) pointerY--;
            else pointerX++;
        }
        return false;
    }
};

// row => n
// col =>m

// O(n*log(m))
// case of 13
// [
//     [1,3,5,7],
//     [10,11,16,20],
//     [23,30,34,60]
// ]

// O(n+m)

// 23
