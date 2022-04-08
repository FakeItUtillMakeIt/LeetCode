class Solution {
public:
    //string:npos是个特殊值，说明查找没有匹配   
    //字符串拼接+字串查找
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};