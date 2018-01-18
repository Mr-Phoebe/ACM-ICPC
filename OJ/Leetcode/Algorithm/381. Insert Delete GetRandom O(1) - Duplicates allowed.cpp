class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].insert(v.size());
        v.push_back(val);
        return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!m.count(val)) {
            return false;
        }
        int last = v.back();
        int pos = *(m[val].rbegin());
        m[last].erase(*(m[last].rbegin()));
        m[last].insert(pos);
        v[pos] = last;
        v.pop_back();
        if (m[val].size() > 1) {
            m[val].erase(*(m[val].rbegin()));
        } else {
            m.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
    
private:
    vector<int> v;
    unordered_map<int, set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 * 
 * I have use unordered_map<int, vector<int>> to solve the problems but fail. I still don't know why.
 */
