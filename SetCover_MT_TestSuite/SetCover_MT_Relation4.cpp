#include "SetCover.h"
#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include<stdio.h>
#include <setjmp.h>
#include <signal.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool areVectorsEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
    // Check if the sizes are equal
    if (v1.size() != v2.size()) {
        return false;
    }

    // Iterate through each vector element
    for (size_t i = 0; i < v1.size(); ++i) {
        // Check if the elements match
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    // Vectors are equal
    return true;
}

bool areVectorOfVectorsEqual(const std::vector<std::vector<int> >& vec1, const std::vector<std::vector<int> >& vec2) {
    // Check if the sizes are equal
    if (vec1.size() != vec2.size()) {
        return false;
    }

    for (size_t i = 0; i < vec1.size(); ++i) {
        bool anyTrue = false;
        for (size_t j = 0; j < vec2.size(); ++j) {
            if (areVectorsEqual(vec1[i], vec2[j])) {
                anyTrue = true;
                break;
            }
        }
        if(!anyTrue){
            return false;
        }
    }
    return true;
}

bool isSame(string s1, string s2) {
    std::string inputString1 = s1;
    std::string inputString2 = s2;

    // Create a vector to store arrays of numbers
    std::vector< std::vector<int> > arrayOfArrays1;
    std::vector< std::vector<int> > arrayOfArrays2;
    // Create a string stream to process the input string
    std::istringstream iss1(inputString1);
    std::istringstream iss2(inputString2);

    // Skip the first line
    std::string line;
    std::getline(iss1, line);
    std::getline(iss1, line);
    std::getline(iss2, line);
    std::getline(iss2, line);

    // Process each line
    while (std::getline(iss1, line)) {
        // Create a vector to store numbers in the current line
        std::vector<int> numbers;

        // Create a string stream for the current line
        std::istringstream lineStream(line);

        // Skip the first 4 characters
        lineStream.ignore(4);

        // Process numbers in the current line
        int number;
        while (lineStream >> number) {
            numbers.push_back(number);
        }

        // Add the vector of numbers to the array of arrays
        arrayOfArrays1.push_back(numbers);
    }

    while (std::getline(iss2, line)) {
        // Create a vector to store numbers in the current line
        std::vector<int> numbers;

        // Create a string stream for the current line
        std::istringstream lineStream(line);

        // Skip the first 4 characters
        lineStream.ignore(4);

        // Process numbers in the current line
        int number;
        while (lineStream >> number) {
            numbers.push_back(number);
        }

        // Add the vector of numbers to the array of arrays
        arrayOfArrays2.push_back(numbers);
    }

    // // Print the result
    // for (const auto& array : arrayOfArrays1) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // // Print the result
    // for (const auto& array : arrayOfArrays2) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }
    for (auto& vec : arrayOfArrays1) {
        std::sort(vec.begin(), vec.end());
    }

    for (auto& vec : arrayOfArrays2) {
        std::sort(vec.begin(), vec.end());
    }

    // printf("gi\n");

    // // Print the result
    // for (const auto& array : arrayOfArrays1) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // // Print the result
    // for (const auto& array : arrayOfArrays2) {
    //     for (int number : array) {
    //         std::cout << number << " ";
    //     }
    //     std::cout << std::endl;
    // }

    bool allVectorsEqual = areVectorOfVectorsEqual(arrayOfArrays1, arrayOfArrays2);
    return allVectorsEqual;
}

jmp_buf jump_buffer;

void handle_signal(int sig) {
    longjmp(jump_buffer, 1);
}

void register_signal_handler() {
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, nullptr);
}

class SetCoverTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Register the signal handler at the beginning of each tes
        printf("hi");
        register_signal_handler();
    }

    void TearDown() override {
        // Reset signal handler to default at the end of each test
        signal(SIGSEGV, SIG_DFL);
    }
};

// Test case 1
TEST(Metamorphic_Testing_Relation4, TestCase1) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_1.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 2
TEST(Metamorphic_Testing_Relation4, TestCase2) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_2.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 3
TEST(Metamorphic_Testing_Relation4, TestCase3) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_3.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        // Run SetCover function
        testing::internal::CaptureStdout();  // Redirect stdout to a buffer
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 4
TEST(Metamorphic_Testing_Relation4, TestCase4) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_4.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 5
TEST(Metamorphic_Testing_Relation4, TestCase5) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_5.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 6
TEST(Metamorphic_Testing_Relation4, TestCase6) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_6.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 7
TEST(Metamorphic_Testing_Relation4, TestCase7) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_7.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 8
TEST(Metamorphic_Testing_Relation4, TestCase8) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_8.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 9
TEST(Metamorphic_Testing_Relation4, TestCase9) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_9.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 10
TEST(Metamorphic_Testing_Relation4, TestCase10) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_10.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 11
TEST(Metamorphic_Testing_Relation4, TestCase11) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_11.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 12
TEST(Metamorphic_Testing_Relation4, TestCase12) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/MetamorphicTesting/Relation4/test_12.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/MetamorphicTesting/output_4b.txt";

        testing::internal::CaptureStdout();  // Redirect stdout to a buffer

        // Run SetCover function
        runSetCover(argc, const_cast<char**>(testArgs));
        // Capture the output
        std::string actualOutput = testing::internal::GetCapturedStdout();
        printf("output \n %s \n", actualOutput.c_str());

        // Read expected output
        std::ifstream expectedOutputFile(expectedOutputFileName);
        std::stringstream expectedOutputBuffer;
        expectedOutputBuffer << expectedOutputFile.rdbuf();

        // Compare actual and expected output
        ASSERT_TRUE(isSame(actualOutput, expectedOutputBuffer.str()));
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Add more test cases as needed
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}