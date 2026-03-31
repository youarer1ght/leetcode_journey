#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保 nums1 是较短的数组，减少二分搜索范围
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        // 搜索分割线位置
        while (left <= right) {
            // i = nums1 中分割线位置（左边有 i 个元素）
            // j = nums2 中分割线位置（左边有 j 个元素）
            // 总左边元素数 = i + j = (m + n + 1) / 2
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // 获取分割线两边的元素（注意处理边界情况）
            int nums1Left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1Right = (i == m) ? INT_MAX : nums1[i];
            int nums2Left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2Right = (j == n) ? INT_MAX : nums2[j];

            // 检查分割是否正确：所有左边元素 <= 所有右边元素
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                // 找到正确分割，计算中位数
                int maxLeft = max(nums1Left, nums2Left);
                int minRight = min(nums1Right, nums2Right);

                if ((m + n) % 2 == 1) {
                    // 总元素数为奇数，中位数是左边最大值
                    return maxLeft;
                } else {
                    // 总元素数为偶数，中位数是左边最大值和右边最小值的平均
                    return (maxLeft + minRight) / 2.0;
                }
            } else if (nums1Left > nums2Right) {
                // nums1 的分割线太靠右，需要向左移动
                right = i - 1;
            } else {
                // nums2Left > nums1Right，nums1 的分割线太靠左，需要向右移动
                left = i + 1;
            }
        }

        // 不会执行到这里
        return 0.0;
    }
};
