class MyHashMap {
    vector<list<pair<int, int>>> mdata;
    int msize = 10000;
public:
    MyHashMap() {
        mdata.resize(msize);
    }
    
    void put(int key, int value) {
        auto &list = mdata[key%msize];
        for(auto & val: list){
            if(val.first == key){
                val.second = value;
                return;;
            }
        }
        list.emplace_back(key,value);
    }
    
    int get(int key) {
        const auto & list = mdata[key%msize];
        if(list.empty()){
            return -1;
        }
        for(const auto & val: list){
            if(val.first == key){
                return val.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto &list = mdata[key%msize];
        list.remove_if([key](auto n){return n.first == key;});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */