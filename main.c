#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

static void repl() {
  char line[1024];
  for (;;) {
    printf("> ");

    if (!fgets(line, sizeof(line), stdin)) {
      printf("\n");
      break;
    }

    interpret(line);
  }
}
static char* readFile(const char* path) {
  // open the file
  FILE* file = fopen(path, "rb");

  // exit if we can't open file
  if (file == NULL) {
    fprintf(stderr, "Could not open file \"%s\".\n", path);
    exit(74);
  }

  // use fseek and ftell to figure out how many bytes the file is
  fseek(file, 0L, SEEK_END);
  size_t fileSize = ftell(file);

  // take that and rewind it back
  rewind(file);

  // allocate fileSize bytes to a char buffer
  char* buffer = (char*)malloc(fileSize + 1);

  // exit if we can't allocate the memory to read the file
  if (buffer == NULL) {
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(74);
  }

  // use fread to store the file's bytes into the buffer
  size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);

  // if fread fails, then exit
  if (bytesRead < fileSize) {
    fprintf(stderr, "Could not read file \"%s\".\n", path);
    exit(74);
  }

  // end with a null byte ('\0')
  buffer[bytesRead] = '\0';

  fclose(file);
  return buffer;
}

static void runFile(const char* path) {
  char* source = readFile(path);
  InterpretResult result = interpret(source);
  free(source);

  if (result == INTERPRET_COMPILE_ERROR) exit(65);
  if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}

int main(int argc, const char* argv[]) {
  initVM();

  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    runFile(argv[1]);
  } else {
    fprintf(stderr, "Usage: clox [path]\n");
    exit(64);
  }

  freeVM();
  return 0;
}
