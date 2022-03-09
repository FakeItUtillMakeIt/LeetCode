class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //任意比较两条边  找同一节点
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};
