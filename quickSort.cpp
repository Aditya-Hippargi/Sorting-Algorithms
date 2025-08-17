#include <iostream>
#include <vector>

int partition(std::vector<int>& vec,int low,int high){
    int pivot=vec[high];  //Choosing pivot as element at index high
    int i=low-1;

    for(int j=low;j<=high-1;j++){
        if(vec[j]<=pivot){
            i++;
            int temp=vec[i];vec[i]=vec[j];vec[j]=temp;
        }
    }
    int temp=vec[i+1];vec[i+1]=vec[high];vec[high]=temp;
    return (i+1);
}

void quickSort(std::vector<int>& vec,int low,int high){
    if(low<high){
        int p=partition(vec,low,high);

        quickSort(vec,low,p-1);       //Left half
        quickSort(vec,p+1,high);    //Right half

    }
}

int main(){
    int n;
    std::cout<<"Enter number of elements: ";std::cin>>n;
    std::vector<int> vec(n);
    std::cout<<"Enter elements: ";
    for(int i=0;i<n;i++) std::cin>>vec[i];

    quickSort(vec,0,vec.size()-1);

    std::cout<<"Sorted vector is: ";
    for(int i=0;i<n;i++) std::cout<<vec[i]<<" ";
}