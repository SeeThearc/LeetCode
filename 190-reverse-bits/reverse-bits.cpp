class Solution {
public:
    int reverseBits(int n) {
        string bin = bitset<32>(n).to_string();
        reverse(bin.begin(),bin.end());
        return stoi(bin,0,2);
    }
};