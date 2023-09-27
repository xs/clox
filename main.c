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

  // reuse the constant var to add a new double 3.4
  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // add the top two on the stack (1.2  + 3.4) = (4.6)
  writeChunk(&chunk, OP_ADD, 123);

  // add a new constant: 5.6
  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // divide the top two on the stack (4.6 / 5.6) = 0.821429
  writeChunk(&chunk, OP_DIVIDE, 123);

  // add a NEGATE unary instruction
  writeChunk(&chunk, OP_NEGATE, 123);

  // write OP_RETURN to chunk
  writeChunk(&chunk, OP_RETURN, 123);

  // disassemble (i.e. print the chunk's contents)
  // disassembleChunk(&chunk, "test chunk");

  // actually do the interpreting
  interpret(&chunk);

  // free memory / clean up
  freeVM();
  freeChunk(&chunk);
  return 0;
}
