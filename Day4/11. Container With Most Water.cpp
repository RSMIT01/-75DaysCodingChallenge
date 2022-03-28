class Solution {
public:
    int maxArea(vector<int>& height) {
        int j=height.size()-1;
        int i=0;
        int water=0;
        while(i<j)
        {
          water=max(water,(j-i)*min(height[i],height[j]));
           if(height[i]>height[j])
           {
             j--;
           }
           else
                     {
                    i++;
                     }
        
        }
        return water;
    }
};