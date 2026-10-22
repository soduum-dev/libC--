#include <cstdlib>
namespace soduumpp {

template <typename T, unsigned long stackLower = 128> // base size of stack to small array;
struct dArray {
	unsigned long size; // size if ins not stack
	unsigned long len; //logic len of array
	T stack[stackLower]; 
	T *heap;
	
	//methods
	void initSize (unsigned long size) {
		if (size > stackLower) { 
			this->size = size;
			this->heap = (T*)malloc(size * sizeof(T)); // malloc check!!!

		} else {
			this->size = stackLower;
			this->heap = NULL;
		}
	}
	T* Source () {
		if (this->heap == NULL) { return this->stack; }
		return this->heap;
	}
	
	void push (T added) {
		T *from; // stack or heap
	 	from = this->Source();

		T *to;	// new heap ptr
		
		if (this->len + 1 <= this->size) {
			from[this->len] = added;
			this->len++; return;
		} 
		
		// else
		unsigned long upSize = this->size * 2; // new size
		to = (T*)malloc(upSize * sizeof(T));
		
		for (unsigned long i = 0; i < this->len; i++) {
			to[i] = from[i];
		}
		this->size = upSize;
		to[this->len] = added; this->len++;
		free(this->heap);
		this->heap = to;
		}
	};

}


