# Unit Testing Assignment

# Part A - Date

### Running the tests

To see how tests work, compile the tests, then run the executable.

```
make

# Run google tests
./date_unittest

# Run main
./date
```

Below are some of the mutants that the tests needed to find:

 * __Mutant:__ Dates from GetDate are missing a character
 * __Mutant:__ Some dates don't have leading zeroes
 * __Mutant:__ Today's date month off by one
 * __Mutant:__ Dates from GetUsDate are not in the right format (same as GetDate?)
 * __Mutant:__ operator-: Probably a copy paste error
 * __Mutant:__ Days between calculation seems to be much larger than it should be
 * __Mutant:__ A test failed on the correct version of the program
 * __Mutant:__ Developer thought months should be zero-indexed
 * __Mutant:__ Dates constructed with epoch are about 70 years in the future
 * __Mutant:__ 1/1/2016 to 3/1/2016 is 60 days, but this version returns 59

***Note:*** To get perfect score, I needed to test for more mutants, so it was important to test above and beyond those tests above.

### Ensuring tests pass on correct version

Included is the correct implementation to be able to test against. To run against the correct implementation, edit the following line in the _Makefile_ to the desired file (e.g. `date.correct.cc`) and run the tests:

```
12 ....
13 ##### EDIT ME!!! #####################
14 MAINDATEFILE = date.correct.cc
15 ######################################
16 ....
```

If the tests are good, they should pass when run against the correct version.

To revert back to the incorrect version of date.cc:

```
12 ....
13 ##### EDIT ME!!! #####################
14 MAINDATEFILE = date.cc
15 ######################################
16 ....
```

# Part B - Queue

This part was similar to part A with a couple of key differences:
* I was not given the implementation file, only the header file
* There were a lot more mutants
* Hints were more vague and less helpful

### Provided Files

For this part, I was not provided the actual `queue.cc` file, but I was provided `queue.h` (it's in 
the `include` folder).  I used `queue.h` to figure out what functions of the Queue class are and how
they should be called.

Additionally, I was provided `queue.o`, a compiled version of `queue.cc` that 
I used to locally run my programs. I was allowed to assume that `queue.o` is the correct version of the 
code.

I was also provided a template `main.cc` file that shows example usage of the Queue class. I was free 
to edit this file as much as I wanted (I wouldn't be submitting it anyways). I could compile and 
run the code I wrote in `main.cc` with:

(*code templates assume you are in the current directory*)
```
make

./queue
```
I used the `main.cc` file to clarify any questions or confusions about the expected behavior of the
Queue class.

Finally, I was provided a template `queue_unittest.cc` file. I had to fill this file out 
with my own unit tests and submit it. At any time, I could run my tests against the 
correct version of the code with:
```
make

./queue_unittest
```
Since it is being run against the *correct* version of the code, all of my tests should *pass*. If 
my tests did not *pass* when I ran it locally, then that means that my tests were not correctly using
the Queue class. 

## **Submission**

If my tests did not *pass* against the *correct* version of 
the code, I would not have received any points for catching the mutants.

