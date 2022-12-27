#include <iostream>
using namespace std;

void swap(int arr[], int L, int R);
int* netherlandsFlag(int arr[], int L, int R);

void swap(int arr[], int L, int R)
{
    arr[L]=arr[L]^arr[R];
    arr[R]=arr[L]^arr[R];
    arr[L]=arr[L]^arr[R];
}

// arr[L...R] �������������Ļ��֣���arr[R]������ֵ
// <arr[R] ==arr[R] >arr[R]
int* netherlandsFlag(int arr[], int L, int R)
{
    if (L>R) 
    {
        int res[]={-1,-1};
        return res;
    }
    if (L==R)
    {
        int* a = new int[2] {L,R};
        return a;
    }
    int less = L - 1; // < �� �ұ߽�
	int more = R; // > �� ��߽�
	int index = L;
    while(index<more)  // ��ǰλ�ã����ܺ� >������߽�ײ��
    {
        if (arr[index]==arr[R])
        {
            index++;
        } else if (arr[index]<arr[R]) {
            swap(arr, index++, ++less);  //no need to see the left, so skip
        } else {
            swap(arr, index, --more);
        }
    }
    swap(arr, more, R);
    int res[]={less+1, more};
    return res;
}

int main() {
    int arr[]={4,1,2,3};
    int* ans=netherlandsFlag(arr, 0, 2);
    // for (int k=0; k<2; k++)
    // {
    //     cout<<ans[k]<<endl;
    // }
    cout<<ans[0];
}