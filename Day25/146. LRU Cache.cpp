class LRUCache {
public:
    
    class node{
        public:
        int Key;
        int Val;
        node * prev;
        node *next;
        node(int k,int v)
        {
            Key=k;
            Val=v;
        }
    };
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    unordered_map<int,node*>m;
    int size=0;
    
    void addnode(node *cur,int key,int value)
    {
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            cur->next=head->next;
            head->next->prev=cur;
            head->next=cur;
            cur->prev=head;
            cur->Key=key;
            cur->Val=value;
            m[key]=cur;
    }
    
    LRUCache(int capacity) {
     size=capacity; 
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node *cur=m[key];
           addnode(cur,key,cur->Val);
            return cur->Val;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(m.find(key)!=m.end())
         {
              node *cur=m[key];
              addnode(cur,key,value);
            
         }
        else if(m.size()==size)
        {
             node *cur=m[tail->prev->Key];
              m.erase(cur->Key);
             addnode(cur,key,value);
        }
        else
        {
            node *cur=new node(key,value);
            cur->prev=head;
            cur->next=head->next;
            addnode(cur,key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */