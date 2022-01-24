# Word Search Puzzle Solver
## IF2211 Strategi Algoritma
### Firizky Ardiansyah (`13520095`)

This is a program to solve a well-known puzzle called the word search problem. If you don't familiar with the puzzle, you can read more information about the puzzle on https://en.wikipedia.org/wiki/Word_search. 

This solver uses brute force technique to find all of the solutions. It will provide a summarized solution (all words in one block), a detailed solution (analysis result of every word), as well as time executed and the number of comparisons it took.


## How to Use
> <b>Notes :</b> 
> The excecutable file on bin directory is originally compiled using makefile on windows operating system, it is recommended to recompile the source file.

Programming language used in this program is C++14, make sure you have installed C++ compiler on your computer. Read link below for more information about C++ compiler
 https://www.cs.odu.edu/~zeil/cs250PreTest/latest/Public/installingACompiler/


1. If you have bash on your computer or using linux as operating system, recompile it using command
```
make all
```
2. If you dont have bash and you dont use linux as operating system type this on terminal
```
g++ -w -std=c++14 ./src/main.cpp -o ./bin/WordSearchPuzzle
```
3. To run the program type
```
./bin/WordSearchPuzzle
```
4. Done.


