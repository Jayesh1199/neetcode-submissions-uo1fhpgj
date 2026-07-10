// This is O(n^2) Solution
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        int alen = a.length();
//        int blen = b.length();
//        int i = 0, carry = 0;
//        string ans = "";

//        while(i<alen || i<blen || carry != 0){
//            int x =0;
//            if(i < alen && a[alen-i-1] == '1'){
//                x=1;
//            }
//            int y = 0;
//            if(i<blen and b[blen -i-1] == '1'){
//                y=1;
//            }
//            ans = to_string((x+y+carry)%2) + ans;
//            carry = (x + y + carry)/2;
//            i = i+1;
//        }
//        return ans;
//    }
//};

// This is O(n) Solution and clean code

#include<string>
#include<algorithm>
class Solution{
    public:
    std::string addBinary(std::string a, std::string b){
        std:: string result = "";
        int i = a.length()  - 1;
        int j = b.length() -1;
        int carry = 0;

        //Loop continues as long as there are characters left OR a carrt exists
        while(i >= 0 || j>= 0 || carry > 0){
            int sum = carry;

            //Subtracting '0' converts the char to its integer value (0 or 1)
            if(i >= 0){
                sum= sum + a[i] - '0';
                i--;
            }
            if(j >= 0){
                sum = sum + b[j] - '0';
                j--;
            }
            // Append the lowest bit of sum to the result

            result = result + std :: to_string(sum % 2);

            // Calculate the new carry
            carry = sum/2;
        }
        //Reverse the string at the end to get the correct order
        std::reverse(result.begin(),result.end());
        return result;
    }
};



