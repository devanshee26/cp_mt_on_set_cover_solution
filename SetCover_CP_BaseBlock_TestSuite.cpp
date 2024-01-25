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
TEST(CategoryPartition_BaseBlockCriteria, TestCase1) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_1.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_1.txt";

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
TEST(CategoryPartition_BaseBlockCriteria, TestCase2) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_2.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_2.txt";

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
TEST(CategoryPartition_BaseBlockCriteria, TestCase3) {
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_3.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_3.txt";

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
TEST(CategoryPartition_BaseBlockCriteria, TestCase4) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_4.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_4.txt";

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
TEST(CategoryPartition_BaseBlockCriteria, TestCase5) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_5.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_5.txt";

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

// Test case 6
TEST(CategoryPartition_BaseBlockCriteria, TestCase6) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_1.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_1.txt";

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
TEST(CategoryPartition_BaseBlockCriteria, TestCase7) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_7.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_7.txt";

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
TEST(CategoryPartition_BaseBlockCriteria, TestCase8) { 
    FAIL();
}

// Test case 9
TEST(CategoryPartition_BaseBlockCriteria, TestCase9) { 
    FAIL();
}

// Test case 10
TEST(CategoryPartition_BaseBlockCriteria, TestCase10) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_10.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_10.txt";

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

// Test case 11
TEST(CategoryPartition_BaseBlockCriteria, TestCase11) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_11.jpeg" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_11.txt";

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

// Test case 12
TEST(CategoryPartition_BaseBlockCriteria, TestCase12) {   
    register_signal_handler(); 
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_12.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_12.txt";

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

// Test case 13
TEST(CategoryPartition_BaseBlockCriteria, TestCase13) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_13.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_13.txt";

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

// Test case 14
TEST(CategoryPartition_BaseBlockCriteria, TestCase14) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_14.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_14.txt";

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

// Test case 15
TEST(CategoryPartition_BaseBlockCriteria, TestCase15) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_15.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_15.txt";

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

// Test case 16
TEST(CategoryPartition_BaseBlockCriteria, TestCase16) {  
    register_signal_handler();  
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_16.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_16.txt";

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

// Test case 17
TEST(CategoryPartition_BaseBlockCriteria, TestCase17) { 
    register_signal_handler();   
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_17.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_17.txt";

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

// Test case 18
TEST(CategoryPartition_BaseBlockCriteria, TestCase18) {    
    register_signal_handler();
    if (setjmp(jump_buffer) == 0) {
        const char *testArgs[] = { "SetCover.c", "-f", "tests/CP_BaseBlock/test_18.txt" };
        int argc = sizeof(testArgs) / sizeof(testArgs[0]);
    
        std::string expectedOutputFileName = "expected_outputs/CP_BaseBlock/output_18.txt";

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