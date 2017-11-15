class Logger {
public:
    map<string, int> ok;
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */

    bool shouldPrintMessage(int timestamp, string message) {
        if(timestamp < ok[message])
            return false;
        ok[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
