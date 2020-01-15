#include <iostream> //places contents of iostream header here (includes definitions of classes and functions which
                    //we'll use to interface with the screen. Here, io stands for input/output)

using namespace std; //indicates that we will be using types declared under the std (standard) namespace.
                     //Namespaces are used to avoid name collisions. Think of them like lastnames. Two people can be
                     //called John, and you differentiate them by their lastname. Two types can have the same name if
                     //are in separate namespaces.

enum ErrorCodes
{
  OK = 0, //Error code of zero if everything was OK
  Overflow = 1 //Error code of 1 if an overflow occurred during the computation
};

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
  //First we describe what the program does
  cout << "This program will compute the factorial of a number" << endl;

  //In order for it to be feasible to compute the factorial, the input needs to be small, so we'll be ok with a short
  short input;

  //We're going to tell cin to throw an exception if the operation fails (for instance, if the user types a string
  //instead of a number, for instance)
  cin.exceptions(ios::failbit);

  bool failure;
  do
  {
    try
    {
      //Now we ask the user to input a number. Note the lack of and endl statement, as we want the cursor to remain
      //in the same line
      cout << "Enter a positive number: ";
      cin >> input;

      //if we got to this point, there were no exceptions thrown, but the user could have typed a negative number.
      //Let's check for that and act accordingly.
      if(input < 0)
      {
        cout << "You've entered a negative number. Please enter a positive number." << endl;
        failure = true; //We're failed to get a good input, so we'll loop again

        //cin would have retrieved the first thing the user typed before a whitespace, and tried to place it in input.
        //The rest that the user typed, including the newline character from pressing enter, is still in the buffer.
        //We're going to tell it to ignore everything in the buffer up to to the maximum stream size, or until it
        //finds the endline character \n (which will definitely be before the maximum stream size)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      else
        failure = false; //if it got to this point, we were successful in getting a number from the user.
    }
    catch(const exception& excp)
    {
      //We're going to explain to the user there was a problem, and display the text of the exception
      cout << endl << "There was a problem with your input (" << excp.what() << "). Please try again." << endl;
      failure = true; //if we caught the exception, we failed to get a number, so we need to loop and ask once again

      //Since an error occurred, we need to clear the error flags from cin
      cin.clear();

      //cin would have retrieved the first thing the user typed before a whitespace, and tried to place it in input.
      //The rest that the user typed, including the newline character from pressing enter, is still in the buffer.
      //We're going to tell it to ignore everything in the buffer up to to the maximum stream size, or until it
      //finds the endline character \n (which will definitely be before the maximum stream size)
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
  while(failure);

  //We're going to check for a special case. The factorial of 0 is 1.
  //Since the factorial of 1 is also 1, we can group that in here.
  if(input <= 1)
  {
    //We output the special-case answer
    cout << "The factorial of " << input << " is " << 1 << endl;
    return OK; //We can end the program early
  }

  //Though the input is small, the output can be very large, so we'll make it a long long type to decreate the odds of
  //overflow
  unsigned long long factorial = input;
  for(auto factor = factorial - 1; factor > 1; --factor)
  {
    auto factorialTest = factorial * input;
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
  cout << "The factorial of " << input << " is " << factorial << endl;
  return OK;
}
