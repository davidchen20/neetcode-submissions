class Twitter {
public:
    unordered_map<int, unordered_set<int>> userFollowing;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    int time;
    Twitter() : time(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time, tweetId});
        time++;    
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;

        follow(userId, userId);
        unordered_set<int>& following = userFollowing[userId];
        for (auto& followinger : following) {
            vector<pair<int, int>>& followingerTweets = userTweets[followinger];
            int numConsideredTweets = min((int)followingerTweets.size(), 10);
            for (int i = 0; i < numConsideredTweets; i++) {
                pq.push(followingerTweets[followingerTweets.size() - 1 - i]);
                if (pq.size() > 10) pq.pop();
            }
        }

        vector<int> tweets(pq.size());
        int idx = pq.size() - 1;
        while (!pq.empty()) {
            tweets[idx] = pq.top().second;
            pq.pop();
            idx--;
        }

        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowing[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowing[followerId].erase(followeeId);
    }
};
