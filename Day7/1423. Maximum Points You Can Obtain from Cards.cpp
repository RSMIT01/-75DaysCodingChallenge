class Solution {
public:
//     int solve(vector<int>& cardPoints, int k,int i,int j)
//     {
//         if(i>j || k==0)
//         {
//             return 0;
//         }
        
//         return max(cardPoints[i]+solve(cardPoints,k-1,i+1,j),cardPoints[j]+solve(cardPoints,k-1,i,j-1));
//     }
    int maxScore(vector<int>& cardPoints, int k) {
        // return solve(cardPoints,k,0,cardPoints.size()-1);
        
        
        //O(k)
        int max_score=0;
        int temp=0;
        for(int i=0;i<k;i++)
        {
            temp+=cardPoints[i];
        }
        int n=cardPoints.size()-1;
        k--;
        max_score=temp;
        while(k>=0)
        {
            temp-=cardPoints[k--];
            temp+=cardPoints[n--];
            max_score=max(max_score,temp);
        }
        return max_score;
    }
};