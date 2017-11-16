class AllOne {
    struct Row {
        int value;
        unordered_set<string> st;
    };
    list<Row> li;
    unordered_map<string, list<Row>::iterator> mp;
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(mp.find(key) == mp.end())
             mp[key] = li.insert(li.begin(), {0, {key}});
        
        auto now = mp[key], next = now;
        next++;
        
        if(next == li.end() || next->value != now->value+1)
            next = li.insert(next, {now->value+1, {}});
        next->st.insert(key);
        mp[key] = next;
        
        now->st.erase(key);
        if(now->st.empty())
            li.erase(now);
        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(mp.find(key) == mp.end())    return;
        
        auto now = mp[key], pre = now;
        pre--;
        mp.erase(key);
        if(now->value > 1)
        {
            if(now == li.begin() || pre->value != now->value-1)
                pre = li.insert(now, {now->value-1, {}});
            pre->st.insert(key);
            mp[key] = pre;
        }
            
        
        now->st.erase(key);
        if(now->st.empty())
            li.erase(now);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return li.empty() ? "" : *(li.rbegin()->st.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return li.empty() ? "" : *(li.begin()->st.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
