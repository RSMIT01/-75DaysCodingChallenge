class MyHashMap {
public:
    vector<pair<int,int>>m;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        bool found=false;
        for(int i=0;i<m.size();i++)
        {
            if(m[i].first==key)
            {
              m[i].second=value;
                found=true;
                break;
            }
        }
        if(!found)
        {
             m.push_back({key,value});
        }
       
    }
    
    int get(int key) {
         bool found=false;
        for(auto it:m)
        {
            if(it.first==key)
            {
                return it.second;
               
            }
        }
         return -1;
      
    }
    
    void remove(int key) {
        for(int i=0;i<m.size();i++)
        {
            if(m[i].first==key)
            {
               m.erase(m.begin()+i);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */