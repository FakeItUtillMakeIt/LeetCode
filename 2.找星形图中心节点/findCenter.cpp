#pragma once

#include <vector>
#include <map>
#include <memory>

using namespace std;

class Solution {
public:

	map<int, int> point;
	

	int findCenter(vector<vector<int>>& edges) {
	/*	for (int i = 0; i < edges.size()+1; i++)
		{

			point[i+1] = 0;

		}*/
		int n = edges.size() + 1;
		for (int i=0;i<edges.size();i++)
		{
			
			point[edges[i][0]] +=1;
			point[edges[i][1]] += 1;
			
		}

		/*int center=1;
		int maxvalue;
		maxvalue = point[1];
		for (int i=1;i<=point.size();i++)
		{

			if (maxvalue<point[i])
			{
				maxvalue = point[i];
				center = i ;
			}
		}*/

		for (int i=1;;i++)
		{
			if (point[i]==n-1)
			{
				return i;
			}
		}

		//return center;
	}
};