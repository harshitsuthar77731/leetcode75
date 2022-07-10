class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pqasc;
        for(auto x : stones)
            pqasc.push(x);
        while(pqasc.size()>1){
            int a = pqasc.top(); pqasc.pop();
            int b = pqasc.top(); pqasc.pop();
            int c= abs(a-b);
            pqasc.push(c);
        }
        return pqasc.top();
    }
};
