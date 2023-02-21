class Solution {
public:
    bool publicChar(string s1,string s2){
        for (char ch1 : s1) {
            for (char ch2 : s2) {
                if (ch1 == ch2) return true;
            }
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() > b.size();
        });
        int maxV=0;
        for(int i=0;i<words.size()-1;i++){
            
            if ((words[i].size()*words[i+1].size()) <= maxV) {
                std::cout<<(words[i].size()*words[i+1].size())<<std::endl;
                break;
                }
            for(int j=i+1;j<words.size();j++){
                if(!publicChar(words[i],words[j])){
                    if((words[i].size()*words[j].size())>maxV)
                        maxV=(words[i].size()*words[j].size());
                }
            }

        }
        return maxV;
    }
};
