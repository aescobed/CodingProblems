



#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int reverse(int x)
{

    std::cout << "input: " << x << endl;

    // Length of int
    int length = 0;

    // If x is negative
    if (x < 0)
        length = -1;

    // Get length of int by converting it to a string first
    length += to_string(x).length();


    // Add the remainder after dividing by a power of 10 to the answer
    int num = x;
    num = (num % 10) * pow(10, length - 1);

    int ans = num;

    for (int i = 1; i < length; i++)
    {

        num = (x / pow(10, i));
        num = (num % 10) * pow(10, (length - i - 1));

        ans += num;

    }


    return ans;

}


int main()
{

    int x = -1234;
    x = reverse(x);

    std::cout << "ans: " << x;
    return 0;
}
