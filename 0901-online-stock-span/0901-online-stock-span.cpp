class StockSpanner {
public:
    stack<pair<int,int>>stk;
    int ans;
    StockSpanner() {
        ans=0;
    }
    

    int next(int price) {
         ans=1;  //1 for current
        if(stk.empty() || stk.top().first>price){   //if prev is greter
            stk.push({price,1});
            return ans;
        }

        while(!stk.empty() && stk.top().first<=price){  //if prev is smaller find till prev become greater
            ans+=stk.top().second;
            stk.pop();
        }stk.push({price,ans});  //push incremented ans
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */