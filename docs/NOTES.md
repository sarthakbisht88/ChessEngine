## These are the points I learn while working on my project
1. scope resolution > using namespace std to prevent ambiguity in case of large files
2. enum class objects should start with capital to distinct them.
3. uint64_t is unsigned integer with 64-bit
4. camelCase best lol
5. some terminology is preferred because it goes along with Chess FEN like I wanted to write int fiftyMove=0 but I have to write halfMoveClock
6. static_cast is used to convert enum to int and 1ULL is basically "1" unsigned long long integer 
7. CMake acts like a linker, it allows us to run multiple files with 1 command, it is not actual linker though just that it has an executable which can simplify the process of build system.
8. 