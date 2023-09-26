#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
  initVM();

  // declare and initialize chunk
  Chunk chunk;
  initChunk(&chunk);

  // add a constant to the chunk: a double 1.2
  int constant = addConstant(&chunk, 1.2);

  // write two bytes to the chunk; an OpCode then a constant index
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // write OP_RETURN to chunk
  writeChunk(&chunk, OP_RETURN, 123);

  // disassemble (i.e. print the chunk's contents)
  disassembleChunk(&chunk, "test chunk");

  // free memory / clean up
  freeVM();
  freeChunk(&chunk);
  return 0;
}
