class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;

        for( int i = 0 ; i < 32; i ++){

            int j = n & (1 << i);

            if(j != 0){
                ret |= 1<<(31-i);
            }
        }
        return ret;
    }
};
