// 1CE, 3WA, 1AC, online algorithm with O(n) time.
class Solution {
public:
	int jump(int A[], int n) {
		if (A == nullptr || n <= 0) {
			return -1;
		} else if (n == 1) {
			return 0;
		}
		
		int last_pos, this_pos;
		int i;
		int result;
		
		last_pos = 0;
		this_pos = 0;
		result = 0;
		for (i = 0; this_pos < n - 1; ++i) {
			if (i > this_pos) {
				return -1;
			}
			if (i + A[i] > this_pos) {
				if (i > last_pos) {
					last_pos = this_pos;
					++result;
				}
				this_pos = i + A[i];
			}
		}
		
		return result + 1;
	}
};