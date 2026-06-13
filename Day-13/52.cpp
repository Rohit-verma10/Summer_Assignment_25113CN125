#include <iostream>
#include <vector>
int main() {
    int size;
    int evenCount=0;
    int oddCount=0;

    std::cout<<"Enter the total number of elements: ";
    std::cin>>size;

    std::vector<int>numbers(size);

    std::cout<<"Enter "<<size<<" integers:\n";
    for (int i=0;i<size;++i) {
        std::cin>>numbers[i];
    }
    for (int i=0;i<size;++i) {
        if (numbers[i]%2==0) {
            evenCount++;
        } else {
            oddCount++;
        }}
    std::cout<<"Total Even Elements: "<<evenCount<<std::endl;
    std::cout<<"Total Odd Elements: "<<oddCount<<std::endl;

    return 0;
}