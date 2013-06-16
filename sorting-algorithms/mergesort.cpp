#include <vector>
#include <iostream>
#include <assert.h>
#include <limits>

using std::numeric_limits;
using std::vector;
using std::cout;
using std::cin;

void merge(vector<double>& array, int start, int mid, int end)
{
    vector<double> leftarray(mid - start + 2);
    vector<double> rightarray(end - mid + 1);
    
    for(int i = 0; i < leftarray.size() - 1; ++i)
	leftarray[i] = array[i + start];
    leftarray[leftarray.size() - 1] = std::numeric_limits<double>::max();

    for(int i = 0; i < rightarray.size() - 1; ++i)
	rightarray[i] = array[i + mid + 1];
    rightarray[rightarray.size() - 1] = std::numeric_limits<double>::max();
    
    int i = 0, j = 0;
    for(int k = start; k <= end; ++k)
    {
	if(leftarray[i] <= rightarray[j])
	    array[k] = leftarray[i++];
	else
	    array[k] = rightarray[j++];
    }
}		    

void mergesort(vector<double>& array, int start, int end)
{
    if(start < end)
    {
	int mid = (start + end)/2;

	mergesort(array, start, mid);
	mergesort(array, mid + 1, end);
	merge(array, start, mid, end);
    }
}

int main()
{
    int number = 0;
    cout<<"Please Enter number of elements to sort:";
    cin>>number;
    
    if(number <= 0)
    {
	cout<<"No Elements to sort\n";
	return -1;
    }

    vector<double> array(number);
    for(size_t i = 0; i < array.size(); ++i)
    {
	cout<<"Enter number "<<(i + 1)<<" :";
	cin>>array[i];
    }

    cout<<"Calling Merge Sort..\n";
    mergesort(array, 0, array.size() - 1);

    cout<<"Sorted array is:";
    for(size_t i = 0; i < array.size(); ++i)
	cout<<array[i]<< " ";
    cout<<"\n";
}
