#include <chrono>
#include <cstdlib>
#include <functional>
#include <iostream>
using namespace std;


/**
 * Time the execution of a factorial function.
 *
 * Students using g++ on Windows should modify this function as shown in
 * https://memorialu.gitlab.io/Engineering/ECE/Teaching/data-structures/website/resources/windows-time.
 */
void timeFactorialFunction(std::function<long (int)>, int n);


//! Calculate the factorial of a number, recursively.
long recursive(int n);

//! Calculate the factorial of a number, iteratively.
long iterative(int n);


//argv vector contain the string value by user entered on the commend line
//argc is the number of strings pointed to by argv vector
int main(int argc, char *argv[])
{
    //if only entered an executable file in the commend line, return 1.
	if (argc < 2)
	{
		cerr << "Usage:  " << argv[0] << " <n>\n"; //standard error stream
        return 1;
	}

    //Parses the string argv[1] interpreting its content as an integral number of base 10
    //And assign this value to int n
	char *end;

	int n = strtol(argv[1], &end, 10);
	if (*end != '\0')//if argv[1] contain a character
    {
        cerr << "Invalid value of n: '" << argv[1] << "'\n";
        return 1;
    }


	cout << "Recursive: ";
	timeFactorialFunction(recursive, n);

	cout << "Iterative: ";
	timeFactorialFunction(iterative, n);

	return 0;
}


void timeFactorialFunction(std::function<long (int)> f, int n)
{
	long result;

	auto start = chrono::high_resolution_clock::now();
	result = f(n);
	auto end = chrono::high_resolution_clock::now();

	cout << "Calculated " << n << "! = " << result
		<< " in " << (end - start).count() << " ns\n";
}


long recursive(int n){
    if(n > 1)
        return n * recursive(n - 1);
    else
        return 1;
}


long iterative(int n){
    long fact = 1;
    for(int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}
