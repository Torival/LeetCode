class Solution {
public:
    int reverse(int x) {
        int num = 0;
        int x1 = abs(x);
        
        for(int i=1; i<=x1; i*=10) {
            //�ж��Ƿ����������С�����Ϊ�������������Ϊ���� 
            if(num >= INT_MAX/10 && (10*num + x1/i%10<0 || (INT_MAX-(10*num + x1/i%10))/10))
                return 0;
            num = 10*num + x1/i%10;
            if(x1/i < 10) break;
        }
        return x > 0 ? num :-num;
    }
};
