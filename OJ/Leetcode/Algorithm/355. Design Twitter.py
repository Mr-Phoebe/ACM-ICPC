import heapq

class Twitter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.time = 0
        self.tweets = {}
        self.followstar = {}

    def postTweet(self, userId, tweetId):
        """
        Compose a new tweet.
        :type userId: int
        :type tweetId: int
        :rtype: void
        """
        self.time += 1
        self.tweets[userId] = self.tweets.get(userId, []) + [(-self.time, tweetId)]

    def getNewsFeed(self, userId):
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        :type userId: int
        :rtype: List[int]
        """
        tweets = self.tweets
        star = self.followstar.get(userId, set()) | set([userId])
        tw = []
        for people in star:
            if people in tweets:
                tw.append((tweets[people][-1][0], tweets[people][-1][1], people, len(tweets[people])-1))
        heapq.heapify(tw)
        
        ans = []
        while len(ans) < 10 and len(tw) != 0:
            u = heapq.heappop(tw)
            ans.append(u[1])
            if u[3] > 0:
                heapq.heappush(tw, (tweets[u[2]][u[3]-1][0], tweets[u[2]][u[3]-1][1], u[2], u[3]-1))
        return ans
            

    def follow(self, followerId, star):
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        self.followstar[followerId] = self.followstar.get(followerId, set()) | set([star])

    def unfollow(self, followerId, star):
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        :type followerId: int
        :type followeeId: int
        :rtype: void
        """
        if followerId in self.followstar and star in self.followstar[followerId]:
            self.followstar[followerId].remove(star)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)