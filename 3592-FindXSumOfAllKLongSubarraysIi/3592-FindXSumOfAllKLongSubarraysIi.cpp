// Last updated: 7/18/2026, 12:23:14 AM
class Solution {
public:
    using ll = long long;
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        set<pair<int,int>> mp, rem; // {freq, val}
        unordered_map<int,int> freq; // value -> freq

        for(int i = 0; i < k; i++) freq[nums[i]]++;

        for(auto &[val, f] : freq){
            rem.insert({f, val});
        }

        ll sum = 0;
        vector<ll> ans;

        // balance rem and mp : take top frequent element rem -> mp
        auto balance = [&](){
            while(mp.size() < x && !rem.empty()){
                auto it = prev(rem.end());
                auto [f, v] = *it;

                rem.erase(it);
                mp.insert({f, v});

                sum += 1LL * f * v;
            }
            ans.push_back(sum);
        };

        // update the frequency and move to rem
        auto update = [&](int val, int dif){
            int of = freq[val];
            freq[val] += dif;
            int nf = freq[val];

            // remove from mp set
            if(mp.count({of, val})){
                sum -= 1LL * of * val;
                mp.erase({of, val});
            }
            else rem.erase({of, val});

            if(nf) rem.insert({nf, val});
        };

        balance(); // initial balance
        for(int i = k; i < nums.size(); i++){

            update(nums[i], 1);
            update(nums[i - k], -1);
            update(mp.begin()->second, 0); // bcz rem may have better candidate

            balance();
        }

        return ans;
    }
};

// top x freq element sum for k size subarray