class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(row+col)
        // int i=0;
        // int j=matrix[0].size()-1;
        // while(i<matrix.size() && j>=0)
        // {
        //     if(matrix[i][j]==target)
        //     {
        //         return true;
        //     }
        //     else if(matrix[i][j]>target)
        //     {
        //         j--;
        //     }
        //     else
        //     {
        //       i++;
        //     }
        // }
        // return false;
        
        
        
        
        //O(log row*col)
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0;
        int high=(m*n)-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[mid/n][mid%n]==target)
            {
                return true;
            }
            else if(matrix[mid/n][mid%n]>target)
            {
                high=mid-1;
            }
            else
            {
             low=mid+1;
            }
        }
        
        return false;
    }
    
};