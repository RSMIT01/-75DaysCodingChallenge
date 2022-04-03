class RandomizedCollection {
public:
    vector<int>arr;
    unordered_map<int,unordered_set<int>>m;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ispresent=true;
        if(m.find(val)!=m.end())
        {
           ispresent=false;
        }
        arr.push_back(val);
        int idx=arr.size()-1;
        m[val].insert(idx);
        return ispresent;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end())
        {
          return false;
        }
         int removeidx=*(m[val].begin());
           m[val].erase(removeidx);
           int lastelement=arr.back();
           arr[removeidx]=lastelement;
            m[lastelement].insert(removeidx);
           m[lastelement].erase(arr.size()-1);
         
           arr.pop_back();
       
        if(m[val].empty())
        {
            m.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */