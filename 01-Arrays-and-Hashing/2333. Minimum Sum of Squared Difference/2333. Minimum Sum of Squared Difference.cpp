long long minSumSquareDiff(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
        const int n = nums1.size();

        // Track deltas between nums1 and nums2 with counting sort buckets
        const int MAX_DELTA = 100000;
        std::vector<int> freq(MAX_DELTA + 1, 0);
        int max_delta = 0;
        int64_t total = 0;
        for (int i = 0; i < n; ++i) {
            int delta = std::abs(nums1[i] - nums2[i]);
            ++freq[delta];
            max_delta = std::max(max_delta, delta);
            total += delta;
        }

        int64_t mods = static_cast<int64_t>(k1) + k2;
        if (mods >= total) {
            return 0;
        }

        // Reduce larger deltas first and calculate sum of squares in the same pass
        int64_t sum = 0;
        for (int delta = max_delta; delta > 0; --delta) {
            if (freq[delta] == 0) {
                continue;
            }

            if (mods > 0) {
                // If we have mods left to spend, subtract from highest delta count
                int move = static_cast<int>(std::min<int64_t>(mods, freq[delta]));
                freq[delta] -= move;
                freq[delta - 1] += move;
                mods -= move;
            }

            // Add squared sum for any remaining instances of this delta
            sum += static_cast<int64_t>(freq[delta]) * delta * delta;
        }

        return sum;
    }