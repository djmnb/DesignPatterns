#include <iostream>
#include <algorithm>
using namespace std;

/* 这是第三方的排序算法,  我们是不知道源码的, 只知道接口*/
class OtherSort
{
public:
    void quickSort(int *nums, int n)
    {
        sort(nums, nums + n);
    }
};

/* 这是以前已经用到的排序算法接口*/
class Sort
{
public:
    virtual void sort(int *nums, int n) = 0;
};
/* 以前的代码都是用这个方法的*/
class InsertSort : public Sort
{
public:
    virtual void sort(int *nums, int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i;
            int temp = nums[i];
            while (j > 0 && nums[j - 1] > temp)
            {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = temp;
        }
    }
};

/*现在我们要引入第三方的代码, 但是我们不知道它的源码,只知道接口, 我们需要引入一个适配器*/
class SortAdapter : public Sort
{
private:
    OtherSort otherSort;

public:
    virtual void sort(int *nums, int n)
    {
        otherSort.quickSort(nums, n);
    }
};

void showArr(int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main()
{
    int nums[] = {10, 2, 4, 5, 1};
    int n = sizeof(nums) / sizeof(int);
    showArr(nums, n);
    Sort *sort = new InsertSort;
    /*以前使用的sort方法*/
    // sort->sort(nums, n);
    // showArr(nums, n);
    // delete sort;

    /* 通过适配器使用第三方算法*/
    sort = new SortAdapter;
    sort->sort(nums, n);
    showArr(nums, n);
    delete sort;
}