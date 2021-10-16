/*class SubrectangleQueries {
public:
    // My Original Code : It was generating TLE in some cases and hence was gravely un-optimised.
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rm = rectangle ; 
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        
        for(int i = row1 ; i <= row2 ; ++i){
            
            for( int j = col1 ; j <= col2 ; ++j){
                rm[i][j] = newValue ; 
            }
        }
    }
    
    int getValue(int row, int col) {
        return rm[row][col] ;
    }
private:
    vector<vector<int>> rm ; 
};

*/
// Optimised Code from Discussions Tab  
// Track Updates rather than updating the original data structure .. approach.

class SubrectangleQueries {
    public:
    vector<vector<int>> rect, subs;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        swap(rect, rectangle);
    }
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        subs.push_back({row1, col1, row2, col2, newValue});
    }
    int getValue(int row, int col) {
        for (int i = subs.size() - 1; i >= 0; --i)
            if (subs[i][0] <= row && subs[i][1] <= col && row <= subs[i][2] && col <= subs[i][3])
                return subs[i][4];
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
