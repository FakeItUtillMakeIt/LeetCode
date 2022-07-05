#include<unordered_map>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mapNums;
        for(int i:nums){
            mapNums[i]+=1;
        }
        for(auto a=mapNums.begin();a!=mapNums.end();a++){
            if(a->second==1){
                return a->first;
            }
        }
        return 0;
    }
};