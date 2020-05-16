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



/* Q1: Convert the add() and average() functions to function templates. Compile the project again — what symbols do you see in templates.o[bj] now?
 * A: I after convert add() and average() functions to function templates, I saw huge amount of symbol information. Away more then before.
 *
 * Q2:Try to call average() with the types int, double and string from the main() function in template-math.cpp. What errors do you see? Why? Fix what you can (and remove what is fundamentally impossible).
 * A: when I converted the template function of average and compiled the code, and call function with double. I got an error of following;
 *  Undefined symbols for architecture x86_64:
 *
 *  "double add<double>(double, double)", referenced from:
 *  _main in template-math.o
 *  "int average<int>(std::__1::vector<int, std::__1::allocator<int> >)", referenced from:
 *  _main in template-math.o
 *        ld: symbol(s) not found for architecture x86_64
 *  clang: error: linker command failed with exit code 1 (use -v to see invocation)
 *
 * My solution was keep all Definition and Declaration to templates.h file. Then problem was solved.
 * With template classes both the definition and implementation must be in the same compilation unit. But I don't know Why..
 *
 * Q3:What result does average({ 1, 2, 3, 4 }) give? Why? Modify this call to explicitly pass a double type to the template parameter and check that it now returns the correct value.
 * A: When I call average({ 1, 2, 3, 4 })
 *    The IDE gave an error: "No matching function for call to 'average' candidate template ignored: couldn't infer template argument 'Y'"
 *    I think its because the function template can only take the argument as a variable parameter.
 *    After I call:
 *      vector<double> a = {1,2,3,4};
 *      cout << "Average of Array a = " << average(a)<<"\n";
 *    It returns "Average of Array a = 2.5" which is correct.
 *
 * Q4:Move the implementation of add() and average() to templates.h. Now make everything compile and run again. This is a common pattern with templates (including the standard template library): you need to put template implementations in header files so that the compiler can instantiate new versions of functions and classes when compiling code that uses the templates. Try explaining this to your neighbour.
 * A: Solved the problem in Q2 by google. Here would be the reason of error happened in Q2
 *
 * Q5: Modify main() to call average() with the types int, double and string. What errors do you see? Why?
 * A: When I call average with type string, there is error of following:
 * This because the compiler can not calculate the average of char or number string
     * ./templates.h:56:16: error: invalid operands to binary expression
     *       ('std::__1::basic_string<char>' and
     *       'std::__1::vector<std::__1::basic_string<char>,
     *       std::__1::allocator<std::__1::basic_string<char> > >::size_type'
     *       (aka 'unsigned long'))
     *     return sum / values.size();
     *            ~~~ ^ ~~~~~~~~~~~~~
     * template-math.cpp:82:40: note: in instantiation of function template
     *       specialization 'average<std::__1::basic_string<char> >' requested here
     *     cout << "Average of Array a = " << average(a)<<"\n";
 *
 * CLASS TEMPLATES:
 * Q1:Convert class GrowableArray into a template that takes a template parameter typename T instead of assuming it will always hold double values. Is there any reason why the new GrowableArray template couldn’t hold non-numeric values like std::string values?
 * A:My new GrowableArray template couldn’t hold non-numeric values like std::string values?
 * but the compiler print libc++abi.dylib: terminating with uncaught exception of type std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >
 *
 * Q1:Instantiate a couple of GrowableArray objects in main() with different types, e.g., GrowableArray<int>, GrowableArray<string> and GrowableArray<vector<GrowableArray<double>>>. Add values to them and check that they work.
 * A: GrowableArray<int> and GrowableArray<string> are working. But GrowableArray<vector<GrowableArray<double> not working.
 *
 *
 */




#include <iostream>
#include "templates.h"
using namespace std;


int main()
{
	string x = "1.0", y = "1.0";
	cout << "x + y = " << add(x, y) << "\n";

//    vector<string> a = {"1","2","3","4"};
//    cout << "Average of Array a = " << average(a)<<"\n";

    GrowableArray<int> A = GrowableArray<int>();
//    GrowableArray<vector> B = GrowableArray<vector>();
    GrowableArray<string> C = GrowableArray<string>();
    A<<1<<2<<3<<0<<1<<2<<3<<0<<1<<2<<3<<0;
//    B<<1<<2<<3<<0<<1<<2<<3<<0<<1<<2<<3<<0;
    C<<"a"<<"b"<<"c"<<"a"<<"b"<<"c""a"<<"b"<<"c"<<"a"<<"b"<<"c";

//    for (auto j = 0; j <= 8 ; j++) {
//        A<<j+0.9;
//        cout<<A[j];
//    }
//    cout<<"\n";

    for (auto i = 0; i <= 12 ; i++) {
        cout<<A[i]<<"\n";
    }

//    for (auto j = 0; j <= 12 ; j++) {
//        cout<<B[j]<<"\n";
//    }

    for (auto k = 0; k <= 12 ; k++) {
	    cout<<A[k]<<"\n";
    }

    return 0; 
}
