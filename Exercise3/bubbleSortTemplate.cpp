#include <iostream>
template <typename T>
T bubbleSort(T array[],int arraySize){
    for (int i = 0; i < arraySize; ++i) {
        bool swapped = false;

        for (int j = 0; j < arraySize; ++j) {

            if(array[j] > array[j+1]){
               T temp =  *array[j];
               *array[j] = *array[j+1];
               *array[j+1] = *temp;
               swapped = true;
            }
        }

    if(swapped == false){
        break;
    }
    }

}
