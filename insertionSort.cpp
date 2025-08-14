#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& vec){
    int n=vec.size();
    for(int i=1;i<n;i++){
        int key=vec[i];
        int j=i-1;
        while(j>=0 && vec[j]>key){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=key;
        for(int i:vec) std::cout<<i<<" ";
        std::cout<<std::endl;
    }
}

int main(){
    int n;
    std::cout<<"Enter number of elements: ";std::cin>>n;
    std::vector<int> vec(n);
    std::cout<<"Enter elements: ";
    for(int i=0;i<n;i++) std::cin>>vec[i];

    insertionSort(vec);
    std::cout<<"Sorted vector is: ";
    for(int i=0;i<n;i++) std::cout<<vec[i]<<" ";
}