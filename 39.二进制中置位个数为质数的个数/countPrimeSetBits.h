class Solution {
public:

    bool isZhiShu(int Num) {
        if (Num==1)
        {
            return false;
        }
        bool zhishu = true;
        int chushuNum = 0;
        for (int i = 1; i <= Num/2; i++) {
            chushuNum += Num % i == 0 ? 1 : 0;
            if (chushuNum >= 2)
                return false;
        }
        if (chushuNum == 1)
            zhishu = true;
        
        return zhishu;
    }

    int countPrimeSetBits(int left, int right) {
        int totalZhiShuN = 0;
        for (int start = left; start <= right; start++) {
            int tmp = start;
            int zhishuN = 0;
            while (tmp > 0) {
                int a = (tmp & 0x1);
                if ( a== 1) {
                    zhishuN += 1;
                }
                
                tmp = tmp >> 1;
            }
            totalZhiShuN += isZhiShu(zhishuN);
        }
        return totalZhiShuN;
    }
};