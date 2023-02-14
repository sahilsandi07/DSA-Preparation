#include<bits/stdc++.h>
using namespace std;

void merge(int *array, int start_ind, int end_ind){

    int mid_ind = (start_ind + end_ind)/2;

    //find length 
    int len1 = mid_ind - start_ind + 1;
    int len2 = end_ind - mid_ind;

    //create two arrays of length len1 and len2
    int *first = new int [len1];
    int *second = new int [len2];

    //copy values
    int maxArrayIndex = start_ind;

    for (int i=0; i<len1; i++){
        first[i] = array[maxArrayIndex++];
    }

    maxArrayIndex = mid_ind + 1;

    for (int i=0; i<len2; i++){
        second[i] = array[maxArrayIndex++];
    }

    // Merge Two Sorted Arrays
    int index1 = 0, index2 = 0; 
    maxArrayIndex = start_ind;

    while (index1 < len1 && index2 < len2){
        if (first[index1] < second[index2]){
            array[maxArrayIndex++] = first[index1++];
        }
        else {
            array[maxArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1){
        array[maxArrayIndex++] = first[index1++];
    }

    while (index2 < len2){
        array[maxArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}


void mergeSort(int *array, int start_ind, int end_ind){

    //pehle base case likhna ha
    if (start_ind >= end_ind){
        return;
    }

    int mid_ind = (start_ind + end_ind) / 2;

    //left part sort krna ha
    mergeSort(array, start_ind, mid_ind);

    //right part sort krna hai
    mergeSort(array, mid_ind+1, end_ind);

    //Merge Arrays
    merge(array, start_ind, end_ind);

}

int main(){
    
    int array[] = {2,5,12,34,12,2,33,44,5,5,5,432,2,2,2,2};
    
    int n = 16;

    mergeSort(array, 0, n-1);

    for (int i=0; i<n; i++){
        cout << array[i] <<" ";
    }
    cout << endl;

}