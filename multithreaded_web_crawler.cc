/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        std::unordered_set<string> visited;
        std::queue<std::future<std::vector<string>>> threads;
        
        visited.insert(startUrl);
        
        string startHost = GetHost(startUrl);
        
        // std::async returns a std::future object
        threads.push(std::async([&htmlParser, startUrl]
                    {return htmlParser.getUrls(startUrl);}));

        while(!threads.empty()) {
            std::vector<string> urls = threads.front().get();
            threads.pop();
            
            for (string url : urls) {
                // Visit neighbors
                string host = GetHost(url);
                if (host != startHost) 
                    // Different hostname so we don't care
                    continue;
                
                if (visited.find(url) == visited.end()) {
                    visited.insert(url);
                    threads.push(std::async([&htmlParser, url]
                            {return htmlParser.getUrls(url);}));
                }
            }
        }
        
        return std::vector<string>(visited.begin(), visited.end());
    }
private:
    string GetHost(string url) {
        // Only need part after 'http://'
        url = url.substr(7);
        size_t found = url.find('/');
        
        return (found == string::npos) ? url : url.substr(0, found);
    }
};
