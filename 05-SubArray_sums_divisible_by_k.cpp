#include<iostream>
#include<string>
using namespace std;

//Burte force
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int left = 0, countTotalSubarray = 0;
        int length = nums.size();

        while( left < length ) {
        int right = left, sumsOfnums = 0;

            while( right < length ) {
                sumsOfnums += nums[right];

                if( sumsOfnums % k == 0 ){
                    countTotalSubarray++;
                }

            right++;
            }

            left++;
        }
        return countTotalSubarray;
    }
};



int main(){
int nums = {5,4,0,-2,-3,1}
 subarraysDivByK(nums)


}


//optimal solution
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        std::unordered_map<int, int> remainderCount; // Stores remainder frequencies
        remainderCount[0] = 1; // To handle cases where prefix sum itself is divisible by k
        
        int countTotalSubarray = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;  // Accumulate prefix sum
            int remainder = prefixSum % k;

            // Adjust remainder to always be positive
            if (remainder < 0) {
                remainder += k;
            }

            // If this remainder was seen before, it means a valid subarray exists
            if (remainderCount.find(remainder) != remainderCount.end()) {
                countTotalSubarray += remainderCount[remainder];
            }

            // Store or update remainder count in the map
            remainderCount[remainder]++;
        }

        return countTotalSubarray;
    }
};
