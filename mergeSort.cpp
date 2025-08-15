#include <iostream>
#include <vector>

void merge(std::vector<int>& vec,int low,int mid,int high){
    int n1=mid-low+1,n2=high-mid;
    std::vector<int> left(n1),right(n2);

    //Populate both left and right side 
    //of the original vectors into the new vectors
    for(int i=0;i<n1;i++) left[i]=vec[low+i];
    for(int i=0;i<n2;i++) right[i]=vec[mid+1+i];

    int i=0,j=0,k=low;
    //Compare the shorter one among them and replace them in the original
    while(i<n1 && j<n2){
        if(left[i]>right[j]){
            vec[k]=right[j];
            j++;
        }
        else{
            vec[k]=left[i];
            i++;
        }
        k++;
    }
    //Now, we add the remaining elements if any
    while(i<n1){
        vec[k]=left[i];i++;k++;
    }
    while(j<n2){
        vec[k]=right[j];j++;k++;
    }
}

void mergeSort(std::vector<int>& vec,int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;

        mergeSort(vec,low,mid);       //Left half
        mergeSort(vec,mid+1,high);    //Right half

        merge(vec,low,mid,high);
    }
}

int main(){
    int n;
    std::cout<<"Enter number of elements: ";std::cin>>n;
    std::vector<int> vec(n);
    std::cout<<"Enter elements: ";
    for(int i=0;i<n;i++) std::cin>>vec[i];

    mergeSort(vec,0,vec.size()-1);

    std::cout<<"Sorted vector is: ";
    for(int i=0;i<n;i++) std::cout<<vec[i]<<" ";
}