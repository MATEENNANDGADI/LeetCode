class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int max=0;

        while(i<j){
            int cwidth= j - i;
            int cheight= min(height[i],height[j]);
            int carea= cwidth*cheight;
            if (carea>max){
                max=carea;
            }

            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
            
        }
        return max;
        }
        
};