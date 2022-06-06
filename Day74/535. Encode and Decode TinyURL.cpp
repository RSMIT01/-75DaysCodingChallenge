class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string>m;
    string encode(string longUrl) {
        string s1;
        int i=0;
       while(i<longUrl.length())
       {
           s1+=to_string(longUrl[i]-'a');
           i++;
       }
        string s="http://tinyurl.com/"+s1;
            m[s]=longUrl;
        return s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));