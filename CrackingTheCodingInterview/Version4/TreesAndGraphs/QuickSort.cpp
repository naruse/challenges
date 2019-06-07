#include <iostream>
#include <vector>

using namespace::std;

int partition (vector<int> &arr, int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    int tmp = 0;
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {//ascending, change to >= to descending
            i++;    // increment index of smaller element
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    tmp = arr[i + 1];
    arr[i+1] = arr[high];
    arr[high] = tmp;
    return (i + 1);
}


void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
        // sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char* argv[]) {
    vector<int> v = {1,3,4,0,-5,8,9,10,22,-1, -7};
    //vector<char> v = {'a','c','d','z','f','g','t','m','n'};

    cout << "Values: " << endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;


    cout << "Ordered: " << endl;

    std::sort(v.begin(), v.end(), std::less<int>()); //std::greater<int>()

    //quickSort(v, 0, v.size()-1);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
