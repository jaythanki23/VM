#include <stdio.h>
#include <iostream>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

using namespace std;

#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX];

enum {
  R_R0 = 0,
  R_R1,
  R_R2,
  R_R3,
  R_R4,
  R_R5,
  R_R6,
  R_R7,
  R_PC,
  R_COND,
  R_COUNT,
};

uint16_t reg[R_COUNT];

enum {
  OP_BR = 0,
  OP_ADD,
  OP_LD,
  OP_ST,
  OP_JSR,
  OP_AND,
  OP_LDR,
  OP_STR,
  OP_RTI,
  OP_NOT,
  OP_LDI,
  OP_STI,
  OP_JMP,
  OP_RES,
  OP_LEA,
  OP_TRAP
};

enum {
  FL_POS = 1 << 0,
  FL_ZERO = 1 << 1,
  FL_NEG = 1 << 2
};

uint16_t sign_extend(uint16_t x, int bit_count) {
  if ((x >> (bit_count - 1)) & 1) {
      x |= (0xFFFF << bit_count);
  }
  return x;
}

void update_flag(uint16_t r) {
  if(reg[r] == 0) {
    reg[R_COND] = FL_ZERO;
  }
  else if (reg[r] >> 15) {
    reg[R_COND] = FL_NEG;
  }
  else {
    reg[R_COND] = FL_POS;
  }
}

uint16_t mem_read(uint16_t address) {};


int main(int argc, const char* argv[]) {
  if(argc < 2) {
    printf("lc3 [image-file1] ...\n");
    exit(2);
  }

  for(int j = 1; j < argc; j++) {
    // read_image
  }


  reg[R_COND] = FL_ZERO;

  enum {PC_START = 0x3000 };
  reg[R_PC] = PC_START;
  
  bool running = true;
  while(running) {
    // FETCH
    uint16_t instr = mem_read(reg[R_PC]++);
    uint16_t op = instr >> 12;

    switch (op)
    {
      case OP_ADD:
        uint16_t r0 = (instr >> 9) & 0x7;
        uint16_t r1 = (instr >> 6) & 0x7;
        uint16_t imm_flag = (instr >> 5) & 0x1;

        if(imm_flag) {
          uint16_t imm5 = sign_extend(instr & 0x1F, 5);
          reg[r0] = reg[r1] + imm5;
        } else {
          uint16_t r2 = instr & 0x7;
          reg[r0] = reg[r1] + reg[r2];
        }

        update_flag(r0);
        
      case OP_AND:
        break;
      case OP_NOT:
        break;
      case OP_BR:
        break;
      case OP_JMP:
        break;
      case OP_JSR:
        break;
      case OP_LD:
        break;
      case OP_LDI:
        break;
      case OP_LDR:
        break;
      case OP_LEA:
        break;
      case OP_ST:
        break;
      case OP_STI:
        break;
      case OP_TRAP:
        break;
      case OP_RES:
        break;
      case OP_RTI:
        break;
      
      default:
        break;
    }
  }
}