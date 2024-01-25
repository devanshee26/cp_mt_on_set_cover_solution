#include "SetCover.h"
#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include<stdio.h>
#include <setjmp.h>
#include <signal.h>

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

// extern "C" {
//     #include "SetCover.h"
// }

// Test case 1
TEST(CategoryPartition_EachBlockCriteria, TestCase1) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_1.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_1.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 2
TEST(CategoryPartition_EachBlockCriteria, TestCase2) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_2.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_2.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 3
TEST(CategoryPartition_EachBlockCriteria, TestCase3) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_3.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_3.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 4
TEST(CategoryPartition_EachBlockCriteria, TestCase4) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_4.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_4.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 5
TEST(CategoryPartition_EachBlockCriteria, TestCase5) {  
    // register_signal_handler();  
    // if (setjmp(jump_buffer) == 0) {
    //     const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_5.txt" };
    //     int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
    //     std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_5.txt";

    //     testing::internal::CaptureStdout();  // Redirect stdout to a buffer

    //     // Run SetCover function
    //     runSetCover(argc, const_cast<char**>(testArgs));
    //     // Capture the output
    //     std::string actualOutput = testing::internal::GetCapturedStdout();
    //     printf("output \n %s \n", actualOutput.c_str());

    //     // Read expected output
    //     std::ifstream expectedOutputFile(expectedOutputFileName);
    //     std::stringstream expectedOutputBuffer;
    //     expectedOutputBuffer << expectedOutputFile.rdbuf();

    //     // Compare actual and expected output
    //     EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    // }
    // else {
    //     std::string actualOutput = testing::internal::GetCapturedStdout();
    //     FAIL() << "Segmentation fault detected.";
    // }
    // signal(SIGSEGV, SIG_DFL);
    FAIL();
}

// Test case 6
TEST(CategoryPartition_EachBlockCriteria, TestCase6) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_6.jpeg" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_6.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 7
TEST(CategoryPartition_EachBlockCriteria, TestCase7) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_7.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_7.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 8
TEST(CategoryPartition_EachBlockCriteria, TestCase8) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_8.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_8.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 9
TEST(CategoryPartition_EachBlockCriteria, TestCase9) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_9.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_9.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
    }
    else {
        std::string actualOutput = testing::internal::GetCapturedStdout();
        FAIL() << "Segmentation fault detected.";
    }
    signal(SIGSEGV, SIG_DFL);
}

// Test case 10
TEST(CategoryPartition_EachBlockCriteria, TestCase10) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_EachBlock/test_10.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_EachBlock/output_10.txt";

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
        EXPECT_EQ(actualOutput, expectedOutputBuffer.str());
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