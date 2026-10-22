#include <cstdlib>
namespace soduum_cpp {

template <typename t, unsigned long stackLower = 128> // base size of stack to small array;
struct dArray {
	unsigned long size; // size if ins not stack
	unsigned long len; //logic len of array
	t stack[stackLower]; 
	t *heap;
	
	//methods
	void initSize (unsigned long size) {
		this->size = size;
		if (size > stackLower) {
			this->heap = malloc(size * sizeof(t));
		} else {
			this->heap = NULL;
		}
	}

	void push (t added) {
		t *from; // stack or heap
		if (this->heap == NULL) { from = this->stack; } else { from = this->heap; }
	 	
		t *to;	// new heap ptr
		
		if (this->len + 1 <= this->size) {
			from[this->len] = added;
			this->len++; return;
		} 
		
		// else
		unsigned long upSize = this->size * 2; // new size

		to = (t*)malloc(upSize * sizeof(t));
		for (unsigned long i = 0; i < this->len; i++) {
			to[i] = from[i];
		}
		this->size = upSize;
		to[this->len] = added; this->len++;
		free(this->heap);
		this->heap = to;
		}
	}

}


