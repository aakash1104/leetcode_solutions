class RandomizedSet {
public:
    // O(1) insert and delete
    std::unordered_map<int, int> ht;
    // used for O(1) getRandom
    std::vector<int> vec;
    
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (ht.find(val) != ht.end())
            return false;

        ht.emplace(val, vec.size());
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (ht.find(val) == ht.end())
            // item not found
            return false;
        
        int last = vec.at(vec.size() - 1);
        int index = ht.find(val)->second;
        
        // index of element being deleted will now have the last element
        vec.at(index) = last;
        vec.erase(vec.end() - 1);
        // update index
        ht.find(last)->second = index;
        
        ht.erase(val);
        return true;
    }
    
    int getRandom() {
        int rand_pos = std::rand() % vec.size();
        return vec.at(rand_pos);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
