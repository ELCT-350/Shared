#include <iostream> //places contents of iostream header here (includes definitions of classes and functions which
                    //we'll use to interface with the screen. Here, io stands for input/output)
#include <fstream> //file i/o streams

using namespace std; //indicates that we will be using types declared under the std (standard) namespace.
                     //Namespaces are used to avoid name collisions. Think of them like lastnames. Two people can be
                     //called John, and you differentiate them by their lastname. Two types can have the same name if
                     //are in separate namespaces.

enum ErrorCodes
{
  OK = 0, //Error code of zero if everything was OK
  Overflow = 1, //Error code of 1 if an overflow occurred during the computation
  FailedToRead = 2
};

int computeFactorial(istream& inputStream, ostream& output)
{
  short input;
  inputStream >> input;

  //We're going to check for a special case. The factorial of 0 is 1.
  //Since the factorial of 1 is also 1, we can group that in here.
  if(input <= 1)
  {
    //We output the special-case answer
    output << "The factorial of " << input << " is " << 1 << endl;
    return OK; //We can end the program early
  }

  //Though the input is small, the output can be very large, so we'll make it a long long type to decreate the odds of
  //overflow
  unsigned long long factorial = input;
  for(auto factor = factorial - 1; factor > 1; --factor)
  {
    auto factorialTest = factorial * factor;
    if(factorialTest < factorial) //this will only happen if an overflow occurred in the multiplication
    {
      cout << "An overflow occurred while computing the factorial of " << input << ". Exiting...";
      return Overflow; //We'll exit with an error code since we were unable to compute the answer
    }

    //Since we didn't exit, an overflow did not occur, and we can replace our current factorial value with the 
    //factorialTest, and continue the loop
    factorial = factorialTest;
  }

  //We output the special-case answer
  output << "The factorial of " << input << " is " << factorial << endl;
  return OK;
}

/**
 * The entry point function is the function that is automatically called when the executable is run. In C++ its
 * signature is such that it returns an integer, and takes in an integer and an array of strings as arguments.
 * These are the command-line arguments invoked when running the program.
 * 
 * @param[in] argc the number of command-line arguments (will be at least 1)
 * @param[in] argv an array containing the command-line arguments (the 0th value in the array will always be the
 * program name
 *
 * @return the error code (if the program exited cleanly, it should return 0. Otherwise, return an integer
 * corresponding to the error that occurred.
 **/
int main(int argc, char* argv[])
{
  //From screen
  cout << "Enter a number: ";

  ifstream input("input.txt");
  ofstream output("output.txt");
  return computeFactorial(input, output);
}
