#include <iostream>
template <typename T>
void bubbleSort(T array[],int arraySize){
    for (int i = 0; i < arraySize; ++i) {
        bool swapped = false;

        //compare the adjacent elements
        for (int j = 0; j < arraySize; ++j) {

            if(array[j] > array[j+1]){
                // swap them
                T temp =  array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                swapped = true;
            }
        }
        //if no number was swapped that means array is sorted now, break the loop.
        if(swapped == false){
        break;
        }
    }
}
