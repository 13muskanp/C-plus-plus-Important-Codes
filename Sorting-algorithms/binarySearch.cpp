#include <bits/stdc++.h> 

using namespace std;

int binarySearch(int arr[], int l, int h, int key)
{
	int mid = (h+l)/2;
	if(l<=h)
	{
		if(key == arr[mid])
			return mid;
		else if(key<arr[mid])
			return binarySearch(arr,l,mid-1,key);
		else
			return binarySearch(arr,mid+1,h,key);
	}
	else
		return -1;
}

int linearSearch(int arr[], int n, int key)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i] == key)
			return i;
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Enter n: ";
	cin>>n;
	int arr[n];
	srand(time(0));
	for(int i=0; i<n; i++)
		arr[i] = rand()%100000;
	
	sort(arr, arr+n); 
	
	for(int i=0; i<n; i++)
		cout<<arr[i]<<" ";
	int h,l,key;
	cout<<endl<<endl<<endl<<"Enter key: ";
	cin>>key;
	
	auto start1 = chrono::steady_clock::now();
	int pos1 = binarySearch(arr,0,n-1,key);
	cout<<endl<<"Element "<<key<<" was found at "<<pos1;
	auto end1 = chrono::steady_clock::now();
	cout<<endl<<endl<<"Elapsed time for Binary Search is (in microseconds) : "<<chrono::duration_cast<chrono::microseconds>(end1 - start1).count()<<endl;

	auto start2 = chrono::steady_clock::now();
	int pos2 = linearSearch(arr,n, key);
	cout<<endl<<"Element "<<key<<" was found at "<<pos2;
	auto end2 = chrono::steady_clock::now();
	cout<<endl<<endl<<"Elapsed time for Linear Search is (in microseconds) : "<<chrono::duration_cast<chrono::microseconds>(end2 - start2).count()<<endl;
}
