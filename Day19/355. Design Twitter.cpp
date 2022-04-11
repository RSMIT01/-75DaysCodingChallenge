class Twitter {
public:
    vector<pair<int,int>>posts;
    unordered_map<int,unordered_set<int>>flw;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
         
        posts.insert(posts.begin(),{userId,tweetId});//insert post in starting to get recent post
          
    }
    
    vector<int> getNewsFeed(int userId) {
         vector<int>feed;
          for(auto it:posts)
          {
              if(it.first==userId || (flw[userId].find(it.first)!=flw[userId].end()))//if post is own or his/her followings then include it
              {
                  feed.push_back(it.second);
                  if(feed.size()==10)
                  {
                      break;
                  }
              }
          }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        flw[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        flw[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */