#include<iostream>
using namespace std;
   int encrypt(int n) {
        int mx = 0;
        int digits = 0;
        int temp = n;

       
        while (temp > 0) {
            mx = max(mx, temp % 10);
            digits++;
            temp /= 10;
        }

       
        int ans = 0;
        for (int i = 0; i < digits; i++) {
            ans = ans * 10 + mx;
        }

        return ans;
    }

 int main(){
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += encrypt(nums[i]);
        }
        return sum;
 }