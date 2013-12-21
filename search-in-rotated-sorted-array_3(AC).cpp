// 1AC, simple variation of binary search, the code is not beautiful, though...
class Solution {
public:
    int search(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int offset;
        
        if(A == nullptr || n <= 0){
            return -1;
        }
        
        int left, mid, right;
        
        left = 0;
        right = n - 1;
        while(left <= right){
            mid = (left + right) / 2;
            if(A[left] <= A[right]){
                // the interval is already monotonous
                if(target < A[mid]){
                    right = mid - 1;
                }else if(target > A[mid]){
                    left = mid + 1;
                }else{
                    return mid;
                }
            }else{
                // the interval includes the 'pivot', containing two monotonous sub-array
                if(target < A[mid]){
                    if(target >= A[left]){
                        right = mid - 1;
                    }else{
                        if(A[mid] >= A[left]){
                            left = mid + 1;
                        }else{
                            right = mid - 1;
                        }
                    }
                }else if(target > A[mid]){
                    if(target <= A[right]){
                        left = mid + 1;
                    }else{
                        if(A[mid] >= A[left]){
                            left = mid + 1;
                        }else{
                            right = mid - 1;
                        }
                    }
                }else{
                    return mid;
                }
            }
        }
        
        return -1;
    }
};