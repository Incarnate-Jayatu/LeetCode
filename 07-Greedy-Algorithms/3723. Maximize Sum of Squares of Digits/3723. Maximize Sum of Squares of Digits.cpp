class Solution
{
public:
    string maxSumOfSquares(size_t n, size_t s) const noexcept
    {
        if (n * 9 < s) return {};

        size_t q = s / 9;
        size_t rem = s % 9;
        bool fill_nines = q <= n - q - !!rem;
        string ans(n, fill_nines ? '0' : '9');
        if (fill_nines)
        {
            ranges::fill(ans | views::take(q), '9');
        }
        else
        {
            ranges::fill(ans | views::drop(q + !!rem), '0');
        }
        if (rem)
        {
            ans[q] = '0' + rem;
        }
        return ans;
    }
};