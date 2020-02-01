#include "iostream"

using namespace std;

#define ARRAY_SIZE(x)           (sizeof(x)/sizeof(x[0]))
extern "C" double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main(int argc, char *argv[])
{
    int a[] = {2, 3, 4};
    int b[] = {1};
    int i;
    // std::cout <<"a:"<<std::endl;
    // for (i = 0; i < ARRAY_SIZE(a); i++) {
    //     std::cout <<a[i]<<" ";
    // }
    // std::cout<<"\nb:"<<endl;
    // for (i = 0; i < ARRAY_SIZE(b); i++) {
    //     std::cout <<b[i]<<" ";
    // }
    // std::cout<<std::endl;
    double ret = findMedianSortedArrays(a, ARRAY_SIZE(a), b, ARRAY_SIZE(b));
    std::cout<<"ret="<<ret<<std::endl;
    return 0;
}
