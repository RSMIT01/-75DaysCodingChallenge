class Solution {
public:
    int binary_search(vector<int> &row)
    {
        int low=0;
        int high=row.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(row[mid]>=0)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return row.size()-high-1; // high points on last positive number
    }
    int countNegatives(vector<vector<int>>& grid) {
        // O(m+n)
//         int n=0;
//         int i=0;
//         int j=grid[0].size()-1;
//         while(i<grid.size() && j>=0)
//         {
//             if(grid[i][j]<0 )
//            {
//             n+=grid.size()-i;
//             j--;
//            }
//            else
//            {
//               i++;
//            }
       
//         }
//       return n;
            
            
            //O(mlogn)
            int ans=0;
            for(int i=0;i<grid.size();i++)
            {
                ans+=binary_search(grid[i]);
            }
        return ans;
    }
};