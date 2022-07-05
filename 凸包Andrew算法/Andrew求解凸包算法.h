//向量差值
	vector<int> substract(const vector<int>& a, const vector<int>& b) {
		return { a[0] - b[0],a[1] - b[1] };
	}

	//叉乘 意义：通过符号判断两矢量间的顺逆时针关系
	double cross(const vector<int>& a, const vector<int>& b) {
		return a[0] * b[1] - a[1] * b[0];
	}

	//从ab到ac扫过的面积。我们根据这个即可判断ac是更接近ab的顺时针方向还是逆时针方向
	double getArea(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
		return cross(substract(b, a), substract(c, a));
	}


 /**
 详细解题步骤
     @brief  https://leetcode.cn/problems/erect-the-fence/solution/by-ac_oier-4xuu/
     https://leetcode.cn/problems/erect-the-fence/solution/an-zhuang-zha-lan-by-leetcode-solution-75s3/
     @param  trees - 
     @retval       - 
 **/
	vector<vector<int>> outerTrees(vector<vector<int>> trees) {
		//先按照x排序，x相同则按照y排序
		sort(trees.begin(), trees.end(), [](const vector<int>& a,const vector<int>& b) {
			a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
			});

		const int len = trees.size();
		int pointNum = 0;
		vector<int> stk(len + 10);//存凸包点索引
		vector<bool> vis(len + 10);//点是否访问过
		stk[++pointNum] = 0;//不标记起点
//若栈内元素不少于 2 个，考虑是否要将栈顶的边删掉（由栈顶前两个元素组成的边）假设栈顶元素为 b，次栈顶元素为 a，即栈顶存在一条 a 到 b 的边，
				// 当前处理到的点为 c，此时我们根据 ac 边是否在 ab 边的时针方向来决定是否要将 ab 边去掉：
				////如果ac在ab的逆时针方向，则我们将b从上半部分的边中踢出去，让c入栈
				// 
				// //下凸壳一定是从最小值一直「左拐」直到最大值，
				// 上凸壳一定是从最大值「左拐」到最小值，
				// 因此我们首先升序枚举求出下凸壳，然后降序求出上凸壳。
				// 
				// 按照x排序，从小往大走，再从大往小走
		//画凸包的第一部分  下凸
		for (int i=1;i<len;i++)
		{
			auto& c = trees[i];
			while (pointNum>=2)
			{
				auto& a = trees[stk[pointNum - 1]], b = trees[stk[pointNum]];
				
				//这里是ac在ab顺时针方向，继续搜寻下一个点
				if (getArea(a,b,c)<0)
				{
					vis[stk[pointNum--]] = false;
				}
				else
				{
					break; 
				}
				
			}
			stk[++pointNum] = i;//否则，我们认为ab比ac更在xia面//采用的第pointNum个点为i
			vis[i] = true;
			
		}
		const int usePointNum = pointNum;
		//画凸包的第二部分  上凸
		for (int i =len-1;i>=0;--i )
		{
			//不能使用已经作为上半部分的边的点
			if (vis[i])
			{
				continue;
			}
			auto& c = trees[i];
			while (pointNum>usePointNum)
			{
				auto& a = trees[stk[pointNum - 1]], b = trees[stk[pointNum]];
				//如果ac在ab的顺时针方向，则不使用b点
				if (getArea(a,b,c)>0)
				{
					--pointNum;
				}
				else
				{
					break;
				}
			}
			stk[++pointNum] = i;//否则，使用c点
		}

		//因为我们一开始的时候就多了一个首节点，因此我们最后的结果中需要移除该节点
		//凸包点集
		vector<vector<int>> res(pointNum - 1);
		for (int i=1;i<pointNum;++i)
		{
			res[i - 1] = trees[stk[i]];
		}

		return res;
	}