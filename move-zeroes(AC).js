/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
  if (nums === null) {
    return;
  }

  var n = nums.length;
  var i, j;
  i = j = 0;

  var zero_value = 0;
  while (i < n) {
    if (nums[i] != zero_value) {
      nums[j++] = nums[i++];
    } else {
      i++;
    }
  }
  while (j < n) {
    nums[j++] = zero_value;
  }
};
