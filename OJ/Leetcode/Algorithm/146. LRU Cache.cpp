class LRUCache {
public:
    LRUCache(int capacity) : sz(capacity) {}

    int get(int key) {
        if(cache.find(key) == cache.end())  return -1;
        itl it = cache[key];
        cache[key] = setfront(it);
        return cache[key]->second;
    }

    void put(int key, int val) {
        if(cache.find(key) != cache.end())
        {
            itl it = cache[key];
            it->second = val;
            cache[key] = setfront(it);
        }
        else
        {
            if(cache.size() == sz)
            {
                cache.erase(used.back().first);
                used.pop_back();
            }
            used.push_front(make_pair(key, val));
            cache[key] = used.begin();
        }
    }

private:
    typedef pair<int, int> pii;
    typedef list<pii> lii;
    typedef lii::iterator itl;
    int sz;
    lii used;
    unordered_map<int, itl> cache;
    itl setfront(itl& it)
    {
        int key = it->first, val = it->second;
        used.erase(it);
        used.push_front(make_pair(key, val));
        return used.begin();
    }
};
