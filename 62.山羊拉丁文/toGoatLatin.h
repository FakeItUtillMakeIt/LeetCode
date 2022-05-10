class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int n = sentence.size();
        int i = 0, cnt = 1;
        string ans;

        while (i < n) {
            int j = i;
            while (j < n && sentence[j] != ' ') {
                ++j;
            }

            ++cnt;
            if (cnt != 2) {
                ans += ' ';
            }
            if (vowels.count(sentence[i])) {
                ans += sentence.substr(i, j - i) + 'm' + string(cnt, 'a');
            }
            else {
                ans += sentence.substr(i + 1, j - i - 1) + sentence[i] + 'm' + string(cnt, 'a');
            }

            i = j + 1;
        }

        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/goat-latin/solution/shan-yang-la-ding-wen-by-leetcode-soluti-1l55/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。