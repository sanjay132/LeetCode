class Solution {
private:
    long last;
    unordered_map<string,string> encodeDB;
    unordered_map<string,string> urlDB;
        
    #define ENCODE_PREFIX "http://tinyurl.com/"
    string getNextEncode(string url){
        string hash = to_string(last);
        last++;
        return hash;
    }
public:

    Solution(){
        last = 1;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // To check if longUrl is already stored 
        if(urlDB.find(longUrl) != urlDB.end())
            return urlDB[longUrl];
        string hash = getNextEncode(longUrl);
        
        string encodeUrl = ENCODE_PREFIX+hash;
        encodeDB.insert({encodeUrl, longUrl});
        urlDB.insert({longUrl, encodeUrl});
        
        return encodeUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return encodeDB[shortUrl];
    }
};