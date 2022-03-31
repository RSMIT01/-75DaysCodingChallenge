class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int m=1e9+7;
        
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int height=max(horizontalCuts[0],h-horizontalCuts[horizontalCuts.size()-1]);
        int width=max(verticalCuts[0],w-verticalCuts[verticalCuts.size()-1]);
        
        
        for(int i=1;i<horizontalCuts.size();i++)
        {
           height=max(height,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++)
        {
           
              width=max(width,verticalCuts[i]-verticalCuts[i-1]);
        }
        
     return ((long long) height * width) % m;
    }
};