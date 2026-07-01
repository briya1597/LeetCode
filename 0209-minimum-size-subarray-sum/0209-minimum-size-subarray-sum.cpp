class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n;
            int ans = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (prefix[mid] >= prefix[i] + target) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (ans != -1) {
                minLen = min(minLen, ans - i);
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};