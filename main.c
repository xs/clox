#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
  // declare and initialize chunk
  Chunk chunk;
  initChunk(&chunk);

  // add a constant to the chunk: a double 1.2
  int constant = addConstant(&chunk, 1.2);

  // write two bytes to the chunk; an OpCode then a constant index
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, constant);

  // write OP_RETURN to chunk
  writeChunk(&chunk, OP_RETURN);

  // disassemble (i.e. print the chunk's contents)
  disassembleChunk(&chunk, "test chunk");

  // free memory / clean up
  freeChunk(&chunk);
  return 0;
}
