class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
      vector<int> ans;
      int total_stamp = 0, turn_stamp = -1;
      while (turn_stamp) {
          turn_stamp = 0;
          for (int sz = stamp.size(); sz > 0; --sz) 
              for (auto i = 0; i <= stamp.size() - sz; ++i) {
                  auto new_stamp = string(i, '*') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '*');
                  auto pos = target.find(new_stamp);
                  while (pos != string::npos) {
                      ans.push_back(pos);
                      turn_stamp += sz;
                      fill(begin(target) + pos, begin(target) + pos + stamp.size(), '*');
                      pos = target.find(new_stamp);
                  }
              }
          total_stamp += turn_stamp;
      }
      reverse(ans.begin(), ans.end());
      return total_stamp == target.size() ? ans : vector<int>();
    }
};