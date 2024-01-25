# Category-Partition and Metamorphic Testing on a Set Covering Solution
**Developer and Author** - Devanshee Kalpeshkumar Vankani\
**StudentID** : 101290994\
**Course** : Software Validation SYSC5105F\
**Guided by** : Dr. Yvan Labiche

This is a testing project for SetCover problem. It includes the implementation of SetCover in SetCover.c and SetCover.h files. The project uses the Google Test (gtest) framework for testing and consists of three types of testing techniques. Gtest is used as a testing framework with signal programming to catch the segmentation fault and abrupt program crashed as our failure case.

## Testing Techniques
These are the Testing techniques covered during the work of project development.
* Category Partitioning: BaseBlock Criteria, EachBlock Criteria, PairwiseBlock Critera
* Metamorphic Testing
* Mutatation Testing

## Project Structure

### Source code, Testing Source Code, and Executables
Given structure illustrates the hierarchy for the Source code for the SetCover problem, TestSuite test files and their Executables.

I've included SetCover_CP_BaseBlock_TestSuite_ProgramFailure.cpp file which has the test cases which are making my local system crash due to the size of file input.

**root**\
|____ SetCover.c\
|____ SetCover.h\
|____ SetCover_CP_BaseBlock_TestSuite.cpp\
|____ SetCover_CP_BaseBlock_TestSuite_Exec.cpp\
|____ SetCover_CP_EachBlock_TestSuite.cpp\
|____ SetCover_CP_EachBlock_TestSuite_Exec.cpp\
|____ SetCover_CP_Pairwise_TestSuite.cpp\
|____ SetCover_CP_Pairwise_TestSuite_Exec.cpp\
|____ SetCover_MT_TestSuite.cpp\
|____ SetCover_MT_TestSuite_Exec.cpp\
|____ SetCover_CP_BaseBlock_TestSuite_ProgramFailure.cpp\

### Testcase input and expected output files
Given structure illustrates the hierarchy for the Test Cases designed for each type of testing techniques for input and exepected_output folder. Where tests/ folder contains the test.txt files containing the input and expected_outputs/ folder contains the output.txt containing the expected output program should give.

**root**\
|____ **tests**/\
|___________ CP_BaseBlock/\
|__________________ test_1.txt\
|__________________ ...\
|___________ ...\
|____ **expected_outputs**/\
|___________ MT/\
|__________________ output_1.txt\
|__________________ ...\
|___________ Mutation/\
|__________________ output_1.txt\
|__________________ ...\
|___________ ...

### Mutation testing
This is the hierarchy for the Mutation testing setup, where mutations/ folder contains total 10 mutants code for SetCover.c file made using mutate.py file. Automation testing is performed by generate_mutation.sh file.

**root**\
|____ **Mutation_Testing**/\
|___________ mutations/\
|__________________ mutated_code_1.c\
|__________________ ...\
|___________ generate_mutation.sh\
|___________ mutate.py

## Coverage Reports and Report PDFs
Screenshots and PDFs for report of the TestCase functions for each test suites are stored in the  
Coverage reports (.html files) and Reports for Testcase functions are provided in the Report_PDFs_And_Images folder

**root**\
|______**CoverageReports**/\
|___________CP_BaseBlock_CoverageReport/\
|___________CP_EachBlock_CoverageReport/\
|___________CP_Pariwise_CoverageReport/\
|___________MT/\
|___________Report_PDFs_And_Images/

### Testing Techniques/ Testing Criteria Document
Each test case is developed using the concepts covered in the class. This document includes the main idea behind creating the test cases based on different selection criterias for Category Partitioning.

[Category Partitioning Document]()

## Installation / Setup / Run program files
- Make sure the machine has gcc/g++ installed for C/C++
- Then Inatall the gtest and gcov and gcovr tools for our project
- run following commands
   * `brew install googletest`
   * `brew install gcov`
   * `brew install gcovr`

### Category Partitioning and Metamorphic Testing
   * Generating .o Files: To generate the .o files, use the following commands: Follow the same steps for       
         1. CP_BaseBlock
         2. CP_EachBlock
         3. CP_Pariwise
         4. MT_TestSuite
- Replace **"Criteria"** with **BaseBlock, EachBlock, Pairwise, MT_TestSuite**

   ```bash
   rm -rf *.gc*
   rm -rf coverage_*.*
   
   g++ -std=c++14 -fprofile-arcs -ftest-coverage -o SetCover_CP_Criteria SetCover.c 
    SetCover_CP_Criteria_TestSuite.cpp $(pkg-config --cflags --libs gtest) -pthread

   ./SetCover_CP_Criteria

- To generate report and coverage run

   ```bash
   gcov SetCover.c
   gcovr -r . --html --html-details -o ./CoverageReports/CP_Criteria_CoverageReport/coverage_report.html

### Mutatation testing
- Change the working directory to **Mutation_Testing**

- For Mutation testing we'e a mutate.py file which will randomly pick a line from the source file and it'll change a character whih can affect the correctness of the code. So far we've 10 mutations and 10 testcase files for it.
- Firstly, I had ran the mutate.py 10 times to create the mutations in mutations/ folder
- Then, I've developed a **generate_mutation.sh** file, which will **automate** all the testin process. It will take each mutated code and it'll compile the SetCover_Mutation_TestSuite.cpp file with mutated code and create a executble file. Now 10 test cases will run against the mutated code and if all test case fails OR program abruptly ends or program rans into infinite loop then it'll make the mutant killed. Otherwise, if one of the test case got passed then the mutant is survived. Analysis is also caught for each of the mutants in the same folder.

- Run the following command to automate the Mutation Testing

   `./generate_mutation.sh`
   
   It'll print all the details of mutants survival and killing.

### Thank You!
Author - Devanshee Kalpeshkumar Vankani