#ifndef SETCOVER_H
#define SETCOVER_H

#include <stdbool.h>
#include <stdio.h>

typedef struct Set Set;
typedef struct Solution Solution;

bool GetALine(FILE *f, char buf[]);
int readGameFile(const char *s);
int init_args(int argc, char **argv);
void runSetCover(int argc, char *argv[]);
void echoInit();
void printSubSet(int nSubSetIndex);
void printSolution(Solution* solution);
bool checkSolution(Solution* solution);
bool containsSubSet(Solution* solution, int subSetIndex);
void addSubSet(Solution* solution, int subSetIndex);
void removeSubSet(Solution* solution, int subSetIndex);
void backTrack(Solution* solution);
void backTrack3(Solution* solution, int last);
void backTrack4(Solution* solution, int last, int sum);
void createSolutionStruct();
void copySolutionToBest();
void sortSubSets();
void greedy();
int numberOfUncoveredElements(int subSetIndex);

#endif // SETCOVER_H