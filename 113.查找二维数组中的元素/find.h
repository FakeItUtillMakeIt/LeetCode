class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {

        if(array.empty() || array[0].empty()){
            return false;
        }
        int row=0;
        int col=0;
        
        for(int i=0;i<array[0].size();i++){
            if(array[0][i]==target){
                return true;
            }
            else if(array[0][i]>target){
                col=i;
                break;
            }
            
            col=i;
        }
        cout<<"col:"<<col<<endl;
        for(int j=0;j<=col;j++){
            for(int i=1;i<array.size();i++){
                if(array[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};



