// 1AC, simple variation of binary search, time complexity O(log(n))
class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int offset;
        
        if(A == nullptr || n <= 0){
            return -1;
        }
        
        int left, mid, right;
        if(A[0] < A[n - 1]){
            offset = n - 1;
        }else{

            left = 0;
            right = n - 1;
            while(right - left > 1){
                mid = (left + right) / 2;
                if(A[left] > A[mid]){
                    right = mid;
                }else{
                    left = mid;
                }
            }
            offset = left;
        }

        offset = (offset + 1) % n;
        left = offset;
        right = n - 1 + offset;
        while(left <= right){
            mid = (left + right) / 2;
            if(target < A[mid % n]){
                right = mid - 1;
            }else if(target > A[mid % n]){
                left = mid + 1;
            }else{
                return mid % n;
            }
        }
        
        return -1;
    }
};