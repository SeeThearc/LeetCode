class Solution {
    public boolean isPalindrome(int x) {
        String line=String.valueOf(x);
        StringBuilder sb=new StringBuilder();
        sb.append(line);
        if(sb.reverse().toString().equals(line)){
            return true;
        }
        return false;
    }
}