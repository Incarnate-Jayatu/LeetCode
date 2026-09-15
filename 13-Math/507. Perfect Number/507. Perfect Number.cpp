class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }
            }
        }
        return sum == num;
    }
};

/* ALTERNATE SOLUTION
class Solution {
public:
    bool checkPerfectNumber(int num) {
        bool result;
        int sum=0;
        for(int i=1; i<=num/2; i++){
            if(num%i == 0)
                sum += i;
        }
        if(sum == num)
            result = true;
        else
            result =false;
        return result;    
    }
};
*/
