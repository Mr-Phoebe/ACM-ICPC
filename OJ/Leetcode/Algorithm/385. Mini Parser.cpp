/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {  
public:  
    NestedInteger deserialize(string s) {  
        if(s[0] != '[') return NestedInteger(stoi(s));  
        stack<NestedInteger*> stk;  
        NestedInteger* ans = NULL;  
        int idx = 0;  
          
        for(int i=0; i<s.size(); i++) {  
            if(s[i] == '[') {  
                stk.push(new NestedInteger());  
                if(!ans) ans = stk.top();  
                idx = i + 1;  
            }  
            else if(s[i] == ',') {
                if(idx != i)  
                    stk.top()->add(NestedInteger(stoi(s.substr(idx, i-idx))));  
                idx = i + 1;
            }
            else if(s[i] == ']') {  
                if(idx != i)  
                    stk.top()->add(NestedInteger(stoi(s.substr(idx, i-idx)))); 
                NestedInteger* cur = stk.top();  
                stk.pop();  
                if(!stk.empty()) stk.top()->add(*cur);  
                idx = i + 1;  
            }  
        }  
          
        return *ans;  
    }  
};  