
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int time = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int>> pq;

        // Add the user's own latest tweet
        if (!tweets[userId].empty()) {
            int i = tweets[userId].size() - 1;
            pq.push({tweets[userId][i].first, userId, i});
        }

        // Add each followed user's latest tweet
        for (int followee : follows[userId]) {
            if (!tweets[followee].empty()) {
                int i = tweets[followee].size() - 1;
                pq.push({tweets[followee][i].first, followee, i});
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [t, author, i] = pq.top();
            pq.pop();

            feed.push_back(tweets[author][i].second);

            // Add the previous tweet by the same author
            if (i > 0) {
                pq.push({tweets[author][i - 1].first,
                         author, i - 1});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};


// this code gives TLE here, because in getNewsFeed we go through all the feeds
// class Twitter {
//      unordered_map<int, unordered_map<int, int>>follows;
//      vector<pair<int, int>>posts;

// public:
//     Twitter() {
//     }
    
//     void postTweet(int userId, int tweetId) {
//         posts.push_back({userId, tweetId});
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         vector<int>feed;
//         for(int i=(int)posts.size()-1; i>=0 && feed.size() < 10; i--){ // we are iterating from back because in vector when we push something we push it from back, counting 9 to 10 tweets
//             int author = posts[i].first;

//             if (author == userId || follows[userId][author] == 1) { //for first condition - Is this tweet posted by the user who is viewing their feed, for second - Does the current user follow the person who posted this tweet
//                 feed.push_back(posts[i].second); // tells you WHICH tweet to add
//             }
//         }

//         return feed;
//     }
    
//     void follow(int followerId, int followeeId) {
//     follows[followerId][followeeId] = 1; // if userId follows another userId
//     }
    
//     void unfollow(int followerId, int followeeId) {
//          follows[followerId][followeeId] = 0; //  // if userId does not follows another userId
//     }
// };

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna