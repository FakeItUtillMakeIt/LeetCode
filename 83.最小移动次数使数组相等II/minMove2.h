class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int totalMinStep = 0;
		int totalMinStep1 = 0;
		int midVal=0;
		int midVal1 = 0;
		
		sort(nums.begin(), nums.end());

		midVal = nums[nums.size() / 2];
		midVal1 = nums[nums.size() / 2] - 1;
		for (auto num:nums)
		{
			totalMinStep += abs(num - midVal);
			totalMinStep1 += abs(num - midVal1);
		}

		
		return totalMinStep>totalMinStep1?totalMinStep1:totalMinStep;
    }
};