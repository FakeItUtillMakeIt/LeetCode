class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto heightsException = heights;
		sort(heightsException.begin(), heightsException.end());
		int diffNum = 0;
		for (int i=0;i<heights.size();i++)
		{
			if (heights[i] != heightsException[i])
				diffNum++;
		}

		return diffNum;
    }
};