class Solution {
    private:
    int leftMost(vector<int> nums,int k){
        int s=0;
        int e=nums.size()-1;
        int mid = s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]==k){
                ans = mid;
                e=mid-1;
            }
            else if(nums[mid]<k){
                s= mid+1;
            }
            else if(nums[mid]>k){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    int rightMost(vector<int> nums,int k){
        int s=0;
        int e=nums.size()-1;
        int mid = s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(nums[mid]==k){
                ans =mid;
                s=mid+1;
            }
            else if(nums[mid]<k){
                s= mid+1;
            }
            else if(nums[mid]>k){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = leftMost(nums,target);
        int right = rightMost(nums,target);

        vector<int> v;
        v.push_back(left);
        v.push_back(right);

        return v;
    }
};