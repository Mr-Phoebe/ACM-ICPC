class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        _times = times;
        vector<int> number(persons.size(), 0);
        timeToPeople.resize(persons.size());
        int max = -1, peo;
        for(int i = 0; i < persons.size(); i++) {
            if(++number[persons[i]] >= max) {
                max = number[persons[i]];
                peo = persons[i];
            }
            timeToPeople[i] = peo;
        }
    }
    
    int q(int t) {
        int r = upper_bound(_times.begin(), _times.end(), t) - (_times).begin();
        return timeToPeople[--r];
    }
private:
    vector<int> timeToPeople;
    vector<int> _times;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
