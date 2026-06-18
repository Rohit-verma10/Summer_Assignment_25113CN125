#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    if (n<=0) {
        cout<<"Invalid number of elements"<<endl;
        return 0;
    }
    vector<int> arr(n);
    cout<<"Enter "<<n<<" elements: ";
    for (int i=0;i<n;++i) {
        cin>>arr[i];
    }
    unordered_map<int,int>frequencyMap;
    int maxFreq=0;
    int maxElement=arr[0];

    for (int i=0;i<n;++i) {
        frequencyMap[arr[i]]++;
        if (frequencyMap[arr[i]]>maxFreq) {
            maxFreq=frequencyMap[arr[i]];
            maxElement=arr[i];
        }
    }
    cout<<"\n--- Results ---"<<endl;
    cout<<"Maximum frequency element: "<<maxElement<<endl;
    cout<<"Frequency count: "<<maxFreq<<" times"<<endl;
    return 0;
}