class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return vector<int>{};
		unordered_map<string, int> m;
		for (string a : words)
			m[a]++;
		int n = s.size(), num = words.size(), len = words[0].size();
		vector<int> index;
		for (int i = 0; i < len; ++i)
		{
			unordered_map<string, int> temp;
			int count = 0;
			int lo = i;

			for (int hi = i; hi + len <= n; hi += len)
			{
				string str = s.substr(hi, len);
				if (m.find(str) != m.end())
				{
					temp[str]++;
					count++;
					while (temp[str] > m[str])
					{
						string rmWord = s.substr(lo, len);
						temp[rmWord]--;
						count--;
						lo += len;
					}
					if (count == num)
					{
						index.push_back(lo);
						string rmWord = s.substr(lo, len);
						temp[rmWord]--;
						count--;
						lo += len;
					}
				}
				else
				{
					temp.clear();
					count = 0;
					lo = hi + len;
				}
			}
		}
		return index;
    }
};
