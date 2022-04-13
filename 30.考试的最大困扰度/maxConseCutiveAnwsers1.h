/**
在指定字符的情况下，我们可以计算其最大连续数目。具体地，我们使用滑动窗口的方法，从左到右枚举右端点，维护区间中另一种字符的数量为 \textit{sum}sum，当 \textit{sum}sum 超过 kk，我们需要让左端点右移，直到 \textit{sum} \leq ksum≤k。移动过程中，我们记录滑动窗口的最大长度，即为指定字符的最大连续数目。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximize-the-confusion-of-an-exam/solution/kao-shi-de-zui-da-kun-rao-du-by-leetcode-qub5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
**/

class Solution {
public:
//滑动窗口
    int maxConsecutiveChar(string& answerKey, int k, char ch) {
        int n = answerKey.length();
        int ans = 0;
        for (int left = 0, right = 0, sum = 0; right < n; right++) {
            sum += answerKey[right] != ch;
            while (sum > k) {
                sum -= answerKey[left++] != ch;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }

    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
                   maxConsecutiveChar(answerKey, k, 'F'));
    }
};

