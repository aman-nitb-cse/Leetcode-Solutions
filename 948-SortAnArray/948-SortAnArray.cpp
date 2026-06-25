// Last updated: 6/25/2026, 11:19:53 PM
class Solution {
public:
    void marge(vector<int>&nums, int s, int e){
        int mid = (e + s) / 2;
        int i = s, j = mid + 1;

        vector<int> temp;
        while(j <= e or i <= mid){
            if(i > mid) temp.push_back(nums[j++]);
            else if(j > e or nums[i] < nums[j]) temp.push_back(nums[i++]);
            else if(nums[i] >= nums[j]) temp.push_back(nums[j++]);
        }
        for(int k = 0; k < temp.size(); k++){
            nums[s + k] = temp[k];
        }
    }

    void margeSort(vector<int>& nums, int s, int e){
        if(s == e) return;
        int mid = (e + s) / 2;
        margeSort(nums, s, mid);
        margeSort(nums, mid + 1, e);
        marge(nums, s, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        margeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};