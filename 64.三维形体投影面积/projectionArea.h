class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;
	
		unordered_map<int, vector<int>> yEqual;

		int xarea = 0;
		int zarea = 0;

		for (int i=0;i<grid.size();i++)
		{
			int maxX = 0;
			for (int j=0;j<grid[i].size();j++)
			{
				yEqual[j].push_back(grid[i][j]);
				if (grid[i][j]>maxX)
				{
					maxX = grid[i][j];
				}
				if (grid[i][j]!=0)
				{
					zarea++;
				}
			}
			xarea += maxX;
		}

		int yarea = 0;
		for (auto i = yEqual.begin(); i != yEqual.end(); i++)
		{
			int maxY = 0;
			for (auto j=0;j<i->second.size();j++)
			{
				if (i->second[j]>maxY)
				{
					maxY = i->second[j];
				}
			}
			yarea += maxY;
		}
		return xarea + yarea + zarea;
    }
};