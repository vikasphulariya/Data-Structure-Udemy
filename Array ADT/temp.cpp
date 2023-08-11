#include<vector>
#include<iostream>
using namespace std;
void display(vector<int> &x)
{
    if (x.size() == 0)
    {
        printf("Empty Array Nothing to Display\n");
        return;
    }
    for (int i = 0; i < x.size(); i++)
    {
        cout <<"At index: "<<i<<" The value is "<< x[i] << endl;
    }
}

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        int k=0;
        int t=m+n;
        int *arr=new int[t];
        for(int i=0;i<t;i++){
            // if(j>m && k>n){
            //     break;
            // }
            if(j>=m){
                arr[i]=nums2[k];
                k++;
                continue;
            }
            if(k>n){
                arr[i]=nums1[j];
                j++;
                continue;
            }
            int t1=nums1[j];
            int t2=nums2[k];

            if(nums1[j]<nums2[k]){
                arr[i]=nums1[j];
                j++;
            }
            else{
                arr[i]=nums2[k];
                k++;
            }
        }
        // display(arr);
        for(int p=0;p<t;p++){
            nums1[p]=arr[p];
        }
    }
    void deleteAtIndex(vector<int>& nums,int index,int items){
        int n=nums.size();
        for(int i=index;i<n-items;i++){
            if(i==(n-items)) {break;}
            nums[i]=nums[i+items];
        }
    }
    int removeDuplicates(vector<int>& nums) {
        int t=nums.size();
        int n=nums.size();
        int k=0;
        for(int i=0;i<n;i++){
            if(i==(n-1)) {break;}
            if(nums[k]==nums[k+1]){
                int s=1;
                // if(i==(n-1)) {break;}
                while(nums[k]==nums[k+s] && i!=(n-1)){
                    s++;

                    i++;
                }
                i--;
                t=t-(s-1);
                deleteAtIndex(nums,k,s-1);
                for(int j=0;j<s-1;j++){
                    nums.pop_back();
                }
            }
            else k++;
        }
    return t;
    }

  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int placed=0;
        int k=flowerbed.size();
        for(int i=0;i<k;i++){
            if(placed==n){break;}
            if(i==0){

            if(flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                placed++;
            }
                continue;
            }
            if(i==(k-1)){

            if( flowerbed[i]==0 && flowerbed[i-1]==0){
                flowerbed[i]=1;
                placed++;
            }
                break;
            }
            if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                placed++;
                continue;
            }
        }
        if(placed==n)        return true;
        else return false;
    }

    int main(){
        vector<int> arr1{1,0,0,0,1,0,0};
        vector<int> arr2{2,5,6};
        // merge(arr1,3,arr2,3);
        canPlaceFlowers(arr1,2);
        display(arr1);
    }