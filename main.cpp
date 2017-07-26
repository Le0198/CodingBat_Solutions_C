#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 1. Given two int values, return their sum. Unless the two values are the same, then return double their sum.

int sumDouble(int a, int b)
{
    int sum = a + b;
    if (a == b) {
        sum = sum*2;
    }
    return sum;
}

// 2. The parameter weekday is true if it is a weekday, and the parameter vacation is true if we are on vacation.
// We sleep in if it is not a weekday or we're on vacation. Return true if we sleep in.

bool sleepIn(bool weekday, bool vacation)
{
    if(!weekday || vacation){
        return true;
    } else {
        return false;
    }
}

// Methods to help make it easier to make a string all UPPER CASE or lower case

string toUpper(string s){
    transform(s.begin(), s.end(), s.begin(),::toupper);
    return s;
}

string toLower(string s){
    transform(s.begin(), s.end(), s.begin(),::tolower);
    return s;
}

// 3. Given a string, return a new string where the last 3 chars are now in upper case.
// If the string has less than 3 chars, uppercase whatever is there.

string endUp(string str) {
    string result = "";
    if(str.size()<3){
        result = toUpper(str);
    } else {
        result = str.substr(0,str.size()-3)+toUpper(str.substr(str.size()-3));
    }
    return result;
}

// 4. Given a string and a non-negative int n, return a larger string that is n copies of the original string.

string stringTimes(string str, int n) {
    string nstr = "";
    int i = 0;
    while(i < n){
        nstr += str;
        i++;
    }
    return(nstr);
}


// 5. Given a string, return a new string made of every other char starting with the first, so "Hello" yields "Hlo".

string stringBits(string str) {
    string everyOther = "";
    int i = 0;
    while(i < str.size()){
        everyOther += str.at(i);
        i+=2;
    }
    return(everyOther);
}

// 6. Return the number of even ints in the given array.

int countEvens(vector<int> nums) {
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if (nums[i]%2 == 0){
            count++;
        }
    }
    return count;
}

// 7. Return the sum of the numbers in the array, except ignore sections of numbers starting with a 6 and
// extending to the next 7 (every 6 will be followed by at least one 7). Return 0 for no numbers.

int sum67(vector<int> nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 6){
            while(nums[i] != 7){
                i += 1;
            }
        }else{
            sum += nums[i];
        }
    }
    return sum;
}

// 8. Given an array of ints, return true if the value 3 appears in the array exactly 3 times,
// and no 3's are next to each other.

bool haveThree(vector<int> nums) {
    int count = 0;
    for(int i =0; i < nums.size(); i++){
        if(nums[i] == 3){
            count++;
            if(i+1 < nums.size() && nums[i+1] == 3){
                return false;
            }
        }
    }
    if(count == 3){
        return true;
    } else {
        return false;
    }
}

// 9. Return an array that contains the exact same numbers as the given array, but rearranged so
// that all the even numbers come before all the odd numbers. Other than that, the numbers can
// be in any order. You may modify and return the given array, or make a new array.

vector<int> evenOdd(vector<int> nums) {
    vector<int> order;
    int i = 0;
    for(int num : nums){
        if(num%2 == 0){
            order.push_back(num);
            i++;
        }
    }
    for(int num : nums){
        if(num%2 == 1){
            order.push_back(num);
            i++;
        }
    }
    return order;
}

// 10. Given n of 1 or more, return the factorial of n, which is n * (n-1) * (n-2) ... 1.
// Compute the result recursively (without loops).

int factorial(int n) {
    if(n < 1){
        return(1);
    }
    return(n*factorial(n-1));
}

// 11. Given a string, compute recursively (no loops) the number of lowercase 'x' chars in the string.

int countX(string str) {
    if (str.length() == 0) return 0;
    if (str.at(0) == 'x') return 1 + countX(str.substr(1));
    return countX(str.substr(1));
}

// 12. We want to make a row of bricks that is goal inches long. We have a number of small bricks (1 inch each) and
// big bricks (5 inches each). Return true if it is possible to make the goal by choosing from the given bricks.

bool makeBricks(int small, int big, int goal) {
    return((goal - big*5) <= small && goal % 5 <= small);
}

// 13. Given 2 arrays that are the same length containing strings, compare the 1st string in one array
// to the 1st string in the other array, the 2nd to the 2nd and so on. Count the number of times
// that the 2 strings are non-empty and start with the same char. The strings may be any length, including 0.

int matchUp(vector<string> a, vector<string> b) {
    int count = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i].length() > 0 && b[i].length() > 0){
            if(b[i].at(0) == a[i].at(0)){
                count++;
            }
        }
    }
    return count;
}

// 14. Given two strings, base and remove, return a version of the base string where all instances
// of the remove string have been removed (not case sensitive). You may assume that the remove string
// is length 1 or more. Remove only non-overlapping instances, so with "xxx" removing "xx" leaves "x".

string withoutString(string base, string remove) {
    while(base.find(remove) != string::npos){
        base = base.erase(base.find(remove),remove.length());
    }
    while(base.find(toLower(remove)) != string::npos){
        base = base.erase(base.find(remove), remove.length());
    }
    while(base.find(toUpper(remove)) != string::npos){

        base = base.erase(base.find(remove), remove.length());
    }
    return base;
}

int main()
{
    cout<<boolalpha << endl;
    cout<<"1. " << sumDouble(1,2)<<endl;
    cout<<"2. " << sleepIn(false,false)<<endl;
    cout<<"3. " << endUp("hello")<<endl;
    cout<<"4. " << stringTimes("Hello",3)<<endl;
    cout<<"5. " << stringBits("Leonardo Lopez")<<endl;
    cout<<"6. " << countEvens({8,10,16,17,3,4})<<endl;
    cout<<"7. " << sum67({1, 1, 6, 7, 2})<< endl;
    cout<<"8. " << haveThree({3, 1, 3, 1, 3})<< endl;
    cout<<"9. ";
            vector<int> order;
    order = evenOdd({3, 4, 3, 4, 3});
    for(int i = 0; i < order.size(); i++){
        cout<<order[i]<<", ";
    }
    cout<<"10. " << factorial(5)<<endl;
    cout<<"11. " << countX("xyxxyxyxxx")<<endl;
    cout<<"12. " << makeBricks(3, 1, 8)<<endl;
    cout<<"13. " << matchUp({"aa", "bb", "cc"}, {"aaa", "b", "bb"})<<endl;
    cout<<"14. " << withoutString("Hello there", "llo")<<endl;
}

