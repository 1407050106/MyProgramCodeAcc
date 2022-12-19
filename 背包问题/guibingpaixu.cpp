#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

void MergeSortArr(int arr[],int left,int mid,int right){//�ú���ͬ�ڽ����������кϲ���һ�������У�ͬʱ�����������ж�Ϊͬһ��Ԫ����һ�����Դ��� 
	int i = left,j = mid + 1;//�������������������������� 
	int k=0;//k���������ݴ�����temp 
	int temp[right-left+1];//��һ��������ʱ���
	while(i <=mid && j <= right){//�����������н��б���������һ�����б�����ɽ���ѭ�� 
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++]; 
	}
	while(i <= mid){//������һ��û�б�����ȫ��������ȫ�����뵽temp�� 
		temp[k++] = arr[i++];
	} 
	while(j <= right){
		temp[k++] = arr[j++];
	}
	//����������Ҫע��ѭ�����������治��ʹ��left��Ϊleft��ֵ�ڸı� 
	for(i = 0;i < k;i++)//���ź�������и��µ�Ŀ�������� 
		arr[left++] = temp[i];
}
//�ݹ鷽�� 
void MergeSort(int arr[],int left,int right){
	if(left == right)//�����������ΪͬһԪ�أ��ݹ���� 
		return ;
	int mid = left+(right-left)>>1;//�Ա��������ٴν��л��� 
	MergeSort(arr, left, mid);//����ߵ����н��л��ִ����������������ߵ������Ѿ����� 
	MergeSort(arr, mid+1, right);//���ұߵ����н��л��ִ���������������ұߵ������Ѿ����� 
	MergeSortArr(arr, left, mid, right);//�Ͳ��������� 
} 

int main() {
    int arr[8] = {8, 4, 5, 7, 1, 3, 6, 2};
	for(int i = 0;i < 8;i++)
		cout<<arr[i]<<" ";
	cout<<endl; 
    MergeSort(arr,0,7);
    for(int i = 0;i < 8;i++)
		cout<<arr[i]<<" ";
	cout<<endl; 
}
