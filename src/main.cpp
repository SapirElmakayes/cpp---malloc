#include <iostream>
#include <string.h>
#include "memoryManager.h"

#define SIZE_FLAG "-S"
#define SIZE_FLAG_INDEX 1
#define SIZE_FLAG_VALUE_INDEX 2
#define NUM_OF_ARGUMENTS 3

#define EXIT_ERROR_ALLOCATION 1
#define EXIT_ERROR_ARGS 2

// A global memory manager to the whole program
MemoryManager gMemoryManager;

int main(int argc, char* argv[]) {
	if (argc != NUM_OF_ARGUMENTS) {
		std::cout << "Error: -S size [size of heap in bytes] is missing" << std::endl;
		return EXIT_ERROR_ARGS;
	}

	if (strcmp(argv[SIZE_FLAG_INDEX], SIZE_FLAG) != 0) {
		std::cout << "Error: " << argv[SIZE_FLAG_INDEX] << " command is not supported" << std::endl;
		return EXIT_ERROR_ARGS;
	}

	int buffer_size_in_bytes = std::stoi(argv[SIZE_FLAG_VALUE_INDEX]);

	gMemoryManager.initialize(buffer_size_in_bytes);

	// Add your code here...

	return 0;
}

// Overloading new and delete
void* operator new (size_t size) {
	return gMemoryManager.allocate(size);
}
 
void* operator new[] (size_t size) {
	return gMemoryManager.allocate(size);
}
 
void operator delete (void* pointerToDelete) {
	gMemoryManager.free(pointerToDelete);
}
 
void operator delete[] (void* arrayToDelete) {
	gMemoryManager.free(arrayToDelete);
}