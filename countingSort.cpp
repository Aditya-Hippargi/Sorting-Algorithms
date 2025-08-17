#include <iostream>
#include <vector>

//Efficient for positive numbers
void countingSort(std::vector<int>& vec){
    int size=vec.size();

    if (size<= 1) {
        return;
    }

    int max=vec[0];
    for(int i=0;i<size;i++){
        if(max<vec[i]) max=vec[i];
    }
    std::vector<int> counts(max+1);
    for(int i=0;i<size;i++){
        counts[vec[i]]++;
    }

    int mainIndex=0;
    for(int i=0;i<max+1;i++){
        int temp=counts[i];
        while(temp!=0){
            vec[mainIndex]=i;
            mainIndex++;temp--;
        }
    }
    
}

int main(){
    int n;
    std::cout<<"Enter number of elements: ";std::cin>>n;
    std::vector<int> vec(n);
    std::cout<<"Enter elements: ";
    for(int i=0;i<n;i++) std::cin>>vec[i];

    countingSort(vec);

    std::cout<<"Sorted vector is: ";
    for(int i=0;i<n;i++) std::cout<<vec[i]<<" ";
}