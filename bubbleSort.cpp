#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& vec){
  int temp,flag=0;
  int size=vec.size();

  for(int i=0;i<size-1;i++){
    flag=0;
    for(int j=0;j<size-i-1;j++){
      if(vec[j]>vec[j+1]){
        temp=vec[j];vec[j]=vec[j+1];vec[j+1]=temp;  //SWAPPING
        flag=1;
      }
    }
    if(flag==0) break;   //If there are no swaps then it means it is sorted
  }
}

int main(){
    int n;
    std::cout<<"Enter number of elements: ";std::cin>>n;
    std::vector<int> vec(n);
    std::cout<<"Enter elements: ";
    for(int i=0;i<n;i++) std::cin>>vec[i];

    bubbleSort(vec);
    std::cout<<"Sorted vector is: ";
    for(int i=0;i<n;i++) std::cout<<vec[i]<<" ";
}