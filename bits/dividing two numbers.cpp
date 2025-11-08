// class Solution {
// public:
//     int divide(int dividend, int divisor) {

//         if(dividend==INT_MIN && divisor==-1){
//             return INT_MAX;
//         }

//         long long a=abs((long long)dividend);
//         long long b=abs((long long)divisor);

//         bool neg=(dividend<0)^(divisor<0);

//         long long result=0;

//         while(a>=b){

//             long long temp=b;
//             long long count=1;

//             while(a>=(temp<<1)){
//                 temp<<=1;
//                 count<<=1;
//             }

//             a-=temp;
//             result+=count;
//         }

//         if(neg){
//             result=(-result);
//         }

//         if(result>INT_MAX) return INT_MAX;
//         if(result<INT_MIN) return INT_MIN;

//         return (int)result;

//     }
// };