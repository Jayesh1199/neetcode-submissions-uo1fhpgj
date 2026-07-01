class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int curr = 0; curr < 32; curr++) {
            uint32_t bit = (n >> curr) & 1u;   // extract bit at position `curr`
            int new_pos = 31 - curr;           // mirror position for a 32-bit reversal
            ans |= (bit << new_pos);           // place it; no-op when bit is 0
        }
        return ans;
    }
};