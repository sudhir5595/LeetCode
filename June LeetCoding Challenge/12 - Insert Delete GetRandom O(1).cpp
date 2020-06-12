class RandomizedSet {
public:
    /** Initialize your data structure here. */
    
    unordered_map <int, int> mp;
    vector <int> v;
    
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        
        if(mp.find(val) != mp.end()){
            return false;
        }
        
        mp[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if(mp.find(val) != mp.end()){
            mp[v[v.size()-1]] = mp[val];
            swap(v[v.size()-1], v[mp[val]]);
            mp.erase(val);
            v.pop_back();
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
