/*
 * Copyright 2018 Jonathan Anderson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//swap two pointer's value
template<typename T>
static void swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

//Print vector
template<typename It>
void print(const It& begin, const It& end){
    for (auto i = begin; i != end  ; ++i) {
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";
}

template<typename Iter, typename Comparator>
void bubbleSort(const Iter& begin, const Iter& end, Comparator compareFn)
{
}

template<typename Iter, typename Comparator>
void insertionSort(const Iter& begin, const Iter& end, Comparator compareFn)
{
    if(compareFn(*std::next(begin, 1),*begin ))
    {
        swap(*begin, *std::next(begin, 1));;
    }

    for (auto unSortedNum = std::next(begin,1); unSortedNum != end; unSortedNum++ )
    {
        // keep unSortedNum pointing to same value,
        // move currentSortNum iterator to left with index value by using prev(unSortedNum,index)
        int index = 0;
        for (auto sortedNum = std::prev(unSortedNum,1); sortedNum != begin; sortedNum--)
        {
            std::cout<<"currentSortNum: "<<*std::prev(unSortedNum,index)<<"\n";

            if(compareFn(*std::prev(unSortedNum,index),*sortedNum))//compare
            {
                swap(*std::prev(unSortedNum,index), *sortedNum);    //swap the value of two iterator
                index++;//keep unSortedNum pointing to same value,
            }
            else
            {
                std::cout<<*std::prev(unSortedNum,index)<<">"<<*sortedNum<<"\n";    //for testing
                break;
            }
            print(begin,end);       //for testing
        }
    }
}

//radixSort template
template <typename T>
void radixSort(T *arr, T n, T maxDigit) {
    T i, j = 1, x, index, temp, count = 0;
    std::vector<T> pocket[10];      //radix of decimal number is 10
    for(i = 0; i< maxDigit; i++) {
        x=pow(10, i+1);

        for(j = 0; j<n; j++) {
            temp = arr[j] % x;
            index = temp/pow(10, i);      //find index for pocket vector
            pocket[index].push_back(arr[j]);
        }
        count = 0;
        for(j = 0; j<10; j++) {
            //delete from linked lists and store to array
            while(!pocket[j].empty()) {
                arr[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}
