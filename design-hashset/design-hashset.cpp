class MyHashSet {
    public: 
    void add(int key) {
    auto it = find(arr.begin(),arr.end(),key);
        if(it == arr.end())
            arr.push_back(key);
    }

    void remove(int key) {
        auto it = find(arr.begin(),arr.end(),key);
        if(it!=arr.end())
            arr.erase(it);
    }


    bool contains(int key) {
         auto it = find(arr.begin(),arr.end(),key);
            if(it == arr.end())
                return false;
        return true;
    }
    private:
    vector<int>arr;

};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */