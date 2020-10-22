using namespace std;
#include<bits/stdc++.h>
void selection(int[],int);
void showData(int[],int);

int main(){
	const int size = 40;
	int counter = 0;
	int array[size]; //Size can be changed, just to prove it works
	cout << "************FILLING ARRAY************" << endl;
	for(int i=size;i>0;i--){ //Worst case, as it is ordered backwards
		array[counter]= i;
		cout << "Array, position " << counter << ": " << array[counter] << endl;
		counter++;
	}
	cout << "************FINISHED FILLING, STARTING SORTING************" << endl;
	selection(array,size);
}

void selection(int data[], int size){
	int i, j, mini;  
    for (i = 0; i < size-1; i++)  
    {  
        // Finding the minimum element in unsorted array  
        mini = i;  
        for (j = i+1; j < size; j++)  
        if (data[j] < data[mini])  
            mini = j;  
        // Swap the found minimum element with the first element  
        swap(data[mini], data[i]);  
    }  
}

void showData(int array[],int size){
	for(int i=0;i<size;i++){
		cout << "Element " << (i+1) << ": " << array[i] << endl;
	}
}
