#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef enum {
  VAL_BOOL,
  VAL_NIL,
  VAL_NUMBER,
} ValueType;

typedef struct {
  ValueType type;
  union {
    bool boolean;
    double number;
  } as;
} Value;

#define IS_BOOL(value)    ((value).type == VAL_BOOL)
#define IS_NIL(value)     ((value).type == VAL_NIL)
#define IS_NUMBER(value)  ((value).type == VAL_NUMBER)

// pulls out the boolean from a value
#define AS_BOOL(value)    ((value).as.boolean)
// pulls out the number from a value
#define AS_NUMBER(value)  ((value).as.number)

// creates a value from a boolean
#define BOOL_VAL(value)   ((Value){VAL_BOOL, {.boolean = value}})
// creates a nil value
#define NIL_VAL           ((Value){VAL_NIL, {.number = 0}})
// creates a value from a number
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})

typedef struct {
  int capacity;
  int count;
  Value* values;
} ValueArray;

bool valuesEqual(Value a, Value b);
void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif
