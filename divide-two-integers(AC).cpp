// 2RE, 2WA, 1AC
class Solution {
public:
    int divide(int dividend, int divisor) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        // 2RE here, -2147483648 is a tricky case
        
        long long int div1, div2;
        int s1, s2;
        long long int base;
        // 1WA here, $r overflows, must be long long int
        long long int res, r;
        
        s1 = sign(dividend);
        s2 = sign(divisor);
        
        if(s1 * s2 == 0){
            return 0;
        }
        
        div1 = (long long int)dividend * s1;
        div2 = (long long int)divisor * s2;
        
        base = div2;
        r = 1;
        while(base <= div1){
            base <<= 1;
            r <<= 1;
        }
        
        res = 0;
        while(r > 0){
            if(div1 >= base){
                div1 -= base;
                res += r;
            }
            base >>= 1;
            r >>= 1;
        }
        
        // 1WA here, forgot to multiply sign variables
        return res * s1 * s2;
    }
private:
    int sign(int x){
        if(x > 0){
            return 1;
        }else if(x < 0){
            return -1;
        }else{
            return 0;
        }
    }
};