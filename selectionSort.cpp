#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& vec){
    int n=vec.size();
    for(int i=0;i<n-1;i++){
        int min=vec[i],minIndex=i;
        for(int j=i+1;j<n;j++){
            if(min>vec[j]){
                min=vec[j];minIndex=j;
            }
        }
        //Now, swap the minimum element with the first element of the unsorted part
        int temp=vec[i];vec[i]=min;vec[minIndex]=temp;
    }
}

int main(){
    int n;
    std::cout<<"Enter number of elements: ";std::cin>>n;
    std::vector<int> vec(n);
    std::cout<<"Enter elements: ";
    for(int i=0;i<n;i++) std::cin>>vec[i];

    selectionSort(vec);
    std::cout<<"Sorted vector is: ";
    for(int i=0;i<n;i++) std::cout<<vec[i]<<" ";
}