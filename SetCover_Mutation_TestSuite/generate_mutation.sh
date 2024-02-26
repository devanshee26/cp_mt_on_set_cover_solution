#!/bin/sh

provided=11

rmdir mutations
mkdir mutations 2>/dev/null
cp "./../SetCover.h" "./mutations/"
rm -rf ./Output*

i=1
total_survived=0
while [ $i -ne $provided ]
do
	# python3 mutate.py ./../SetCover.c mutations/mutated_code_$i.c
	# gcc mutated_code/$i.c 2>/dev/null

    rm -rf *.gc* 
    rm -rf coverage_*.*
    g++ -std=c++14 -fprofile-arcs -ftest-coverage -o SetCover_Mutation_Exec_$i mutations/mutated_code_$i.c ./../SetCover_Mutation_TestSuite.cpp $(pkg-config --cflags --libs gtest) -pthread
    "./SetCover_Mutation_Exec_$i" &
    pid=$!
    sleep 10
    if ps -p $pid > /dev/null; then
        echo "Timeout reached"
        echo "Mutation $i is killed\n"
        kill -9 $pid
    else
        "./SetCover_Mutation_Exec_$i" > /dev/null 2>&1
        if [ $? -eq 0 ]; then
            echo "Mutation $i is killed\n"
        else
            echo "Mutation $i is survived\n"
            total_survived=$(($total_survived+1))
        fi
        "./SetCover_Mutation_Exec_$i" > "Output_Mutation_$i.txt"
    fi

    rm -rf ./SetCover_Mutation_*
    rm -rf ./*.gc*

    i=$(($i+1))

done
left=$((10-$total_survived))
printf "Total 10 mutants were created for the project\n"
printf "\e[32mTotal $left Mutations killed\e\n[0m"
printf "\e[31mTotal $total_survived Mutation survived out of 10\n\e[0m"
printf "\e[32mMutation survival rate is just $(($left/10)) in the program\n\e[0m"