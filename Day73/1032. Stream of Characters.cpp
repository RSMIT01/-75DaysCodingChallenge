class StreamChecker {
public:
    struct Node{
        Node* arr[26];
        bool isEnd;
        Node(){
            for(int i=0;i<26;i++){
                arr[i]=NULL;
            }
            isEnd=false;
        }
    };
    string s="";
    Node* root=new Node();
    void insert(string word){
        Node* curr=root;
        for(int i=word.size()-1;i>=0;i--){
            if(curr->arr[word[i]-'a']==NULL){
                curr->arr[word[i]-'a']=new Node();
            }
            curr=curr->arr[word[i]-'a'];
        }
        curr->isEnd=true;
    }
    StreamChecker(vector<string>& words) {
        for(auto word:words)
        {
            insert(word);
        }
    }
    
    bool query(char letter) {
        s+=letter;
        Node* curr=root;
        for(int i=s.size()-1;i>=0;i--){
            curr=curr->arr[s[i]-'a'];
            if(curr==NULL)
            {
                return false;
            }
           
            if(curr->isEnd){
                return true;
            }

            
        }
        return false;
    }
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */