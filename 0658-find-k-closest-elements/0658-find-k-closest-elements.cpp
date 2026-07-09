class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        //distance ,index
        priority_queue<pair<int,int>> pq;  //Max heap
        for(int i=0;i<k;i++){
            pq.push({abs(x-nums[i]),i});
        }

        for(int i=k;i<nums.size();i++){
            //2nd condition for distance are same them compare position of index
            if(pq.top().first>abs(x-nums[i]) || (pq.top().first == abs(x-nums[i]) &&
    nums[pq.top().second] > nums[i])){
                pq.pop();
                pq.push({abs(x-nums[i]),i});
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(nums[pq.top().second]);
            pq.pop();
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};