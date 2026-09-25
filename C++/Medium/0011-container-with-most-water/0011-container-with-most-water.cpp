class Solution {
public:
    long long maxArea(vector<int>& height) {
        long long maxwater=0;
        int i=0;
        int j=height.size()-1;
        
        while(i<j){
            int ht= min(height[i],height[j]);
            int width= j-i;
            long long currvol= ht*width;
            maxwater=max(currvol,maxwater);
            height[i]<height[j]?i++:j--;
            
        }
        return maxwater;
    }
};