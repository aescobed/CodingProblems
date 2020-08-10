#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


double getMedian(vector<int>& nums1, vector<int>& nums2)
{
    vector<int> combined;

    int Size = nums2.size() + nums1.size();

    // Create pointers to the first numbers in each array
    auto nums1Ptr = nums1.cbegin();
    auto nums2Ptr = nums2.cbegin();

    // Sort the arrays into 1 array
    while (nums1Ptr != nums1.cend() && nums2Ptr != nums2.cend())
    {
        if (*nums1Ptr < *nums2Ptr)
        {
            combined.push_back(*nums1Ptr);
            ++nums1Ptr;
        }
        else
        {
            combined.push_back(*nums2Ptr);
            ++nums2Ptr;
        }
    }

    // Push the remaining numbers
    while (nums1Ptr != nums1.cend())
    {
        combined.push_back(*nums1Ptr);
        ++nums1Ptr;
    }

    while (nums2Ptr != nums2.cend())
    {
        combined.push_back(*nums2Ptr);
        ++nums2Ptr;
    }

    /*
    // Print sorted list
    for (auto i = combined.cbegin(); i != combined.cend(); ++i)
        cout << *i << " ";
    */

    // If the median is the middle number
    if ((Size % 2) == 1)
        return combined[(Size - 1) / 2];
    // If the median is the average of the two middle numbers
    else
        return (double(combined[(Size/2)]) + double(combined[(Size/2) - 1]))/2;
}


int main()
{

    vector<int> nums1;
    vector<int> nums2;

    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);

    std::cout << "\nans: " << getMedian(nums1, nums2);
    
    return 0;
}