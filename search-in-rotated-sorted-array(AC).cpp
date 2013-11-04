// 1AC, simple variation of binary search
class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int offset;
        
        if(A == nullptr || n <= 0){
            return -1;
        }
        
        for(offset = 0; offset < n; ++offset){
            if(A[offset] > A[(offset + 1) % n]){
                break;
            }
        }
        
        int left, mid, right;
        
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