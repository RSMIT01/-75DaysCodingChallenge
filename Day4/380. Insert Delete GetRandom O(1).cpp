class RandomizedSet {
public:
    unordered_map<int,int>m;
    vector<int>arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)==m.end())
        {
             arr.push_back(val);
             m[val]=arr.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
         if(m.find(val)!=m.end())
        {
           
           int idx=m[val];
             
           arr[idx]=arr.back();
           m[arr.back()]=idx;
             
            m.erase(val);
            arr.pop_back();
            return true;
        }
          return false;
    }
    
    int getRandom() {
      int rnum=rand()%(arr.size());
        return arr[rnum];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */