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
    cout<<"space is = "<<res[0]<<res[1]<<endl;
    int* b;
    b=res; 
    //for (int i=0; i<2; i++)          //All right!
    //{
    //	cout<<*(b+i)<<endl;
    //}
    return b;
}

int main() {
    int arr[]={4,1,3,3};
    int arr2[2]={0};
    int* ans;
    ans=arr2;
    ans=netherlandsFlag(arr, 1, 3);
    // for (int k=0; k<2; k++)
    // {
    //     cout<<ans[k]<<endl;
    // }
    int len = 3;
    cout<<1111111111111<<endl;
    for (int i=0; i<2; i++)
    {
    	cout<<ans<<endl;
    }
}
