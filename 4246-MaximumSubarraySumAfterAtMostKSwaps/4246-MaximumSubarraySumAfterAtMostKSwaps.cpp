// Last updated: 6/24/2026, 3:27:42 AM
class Solution {
public:
    using ll = long long;

    long long maxSum(vector<int>& nums, int k) {
        int n = nums.size();

        ll ans = INT_MIN;

        if(k == 0 || n == 1){
            ll sum = 0;

            for(int x : nums){
                sum += x;
                ans = max(ans, sum);

                if(sum < 0) sum = 0;
            }

            return ans;
        }

        int negCnt = 0;
        ll posSum = 0;

        vector<ll> pref(n + 1);

        for(int i = 0; i < n; i++){
            if(nums[i] >= 0) posSum += nums[i];
            else negCnt++;

            pref[i + 1] = pref[i] + nums[i];

            ans = max(ans, (ll)nums[i]);
        }

        if(negCnt <= k) return posSum;

        vector<vector<ll>> dp(n, vector<ll>(n));

        for(int l = 0; l < n; l++){
            priority_queue<int> pq;

            ll removedNegSum = 0;

            for(int r = l; r < n; r++){
                if(nums[r] >= 0){
                    dp[l][r] = removedNegSum;
                    continue;
                }

                if(pq.size() < k){
                    pq.push(nums[r]);
                    removedNegSum += nums[r];
                }
                else{
                    if(pq.top() > nums[r]){
                        removedNegSum -= pq.top();
                        pq.pop();

                        removedNegSum += nums[r];
                        pq.push(nums[r]);
                    }
                }
            }
        }

        for(int l = 0; l < n; l++){
            priority_queue<int, vector<int>, greater<int>> pq;

            ll addedPosSum = 0;

            for(int i = 0; i < l; i++){
                if(nums[i] < 0) continue;

                if(pq.size() < k){
                    pq.push(nums[i]);
                    addedPosSum += nums[i];
                }
                else{
                    if(pq.top() < nums[i]){
                        addedPosSum -= pq.top();
                        pq.pop();

                        addedPosSum += nums[i];
                        pq.push(nums[i]);
                    }
                }
            }

            for(int r = n - 1; r > l; r--){
                ll curSum = pref[r + 1] - pref[l];

                curSum -= dp[l][r];
                curSum += addedPosSum;

                ans = max(ans, curSum);

                if(nums[r] < 0) continue;

                if(pq.size() < k){
                    pq.push(nums[r]);
                    addedPosSum += nums[r];
                }
                else{
                    if(pq.top() < nums[r]){
                        addedPosSum -= pq.top();
                        pq.pop();

                        addedPosSum += nums[r];
                        pq.push(nums[r]);
                    }
                }

                if(!pq.empty()) ans = max(ans, addedPosSum);
            }
        }

        return ans;
    }
};