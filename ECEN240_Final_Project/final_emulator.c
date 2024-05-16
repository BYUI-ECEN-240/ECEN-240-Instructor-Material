/* This program emulates the 4-bit processor done for ECEN-240
Inputs:
    Argument 1:
        MicroCODE-ROM  Selector  -- This points to the organization of the outputs that control the circuit
    Argument 2:
        OpCode Filename  -- This is a text file with one line per opcode/operands
    (Optional -- OPCODE Mapping)
Outputs:
    Register File Contents
    LCD Contents
*/




#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define REG_COUNT 8  // Number of registers
#define MAX_INSTRUCTION_LENGTH 4

typedef enum {
    NOP, LD, MOV, DISP, XOR, AND, OR, ADD, SUB, INVALID
} OpcodeType;

int regs[REG_COUNT];  // Array to store register values
char display[100];      // String to store output for DISP instruction
int pc = 0;            // Program counter

const char *mnemonics[] = {"NOP", "LD", "MOV", "DISP", "XOR", "AND", "OR", "ADD", "SUB"};


void cut_at_first_whitespace(char str[]) {
    int i = 0;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t') {
        i++;
    }
    str[i] = '\0'; // Terminate the string at the first whitespace
}


OpcodeType getOpcodeType(const char *instruction) {
    printf("getopcode: %s\n\r",instruction);
    char theOpcode[100];
    strcpy(theOpcode,instruction);
    cut_at_first_whitespace(theOpcode);
    for (int i = 0; i < sizeof(mnemonics) ; i++) {
        if (strcmp(theOpcode, mnemonics[i]) == 0) {
            return i;
        }
    }
    return INVALID;
}


int parseOperands(const char *instruction,int *operands) {
    int numOperands = 0;
    char *token = strtok((char *)instruction, ", ");
    while (token && numOperands < MAX_INSTRUCTION_LENGTH) {
        operands[numOperands] = atoi(token);
        numOperands++;
        token = strtok(NULL, ", ");
    }
    return numOperands;
}

void executeOpcode(OpcodeType theOpcode, int operands[MAX_INSTRUCTION_LENGTH]) {
    switch (theOpcode) {
        case NOP:
            break;
        case LD:
            if (operands[0] >= REG_COUNT) {
                // Handle invalid register number
            } else {
                regs[operands[0]] = operands[1] & 0xF;
                printf("Got LC:  Loading into regs[%d] value: %d\n\n",operands[0],operands[1]);
            }
            break;
        case MOV:
            if (operands[0] >= REG_COUNT || operands[1] >= REG_COUNT) {
                // Handle invalid register number
            } else {
                regs[operands[1]] = regs[operands[0]] & 0xF;
            }
            break;
        case DISP:
            if (operands[0] >= REG_COUNT || operands[1] >= REG_COUNT) {
                // Handle invalid register number
            } else {
                // Concatenate characters based on register values (modify for desired output)
                sprintf(display, "%c", ((regs[operands[0]] & 0xF) << 4) | (regs[operands[1]] & 0xF));
            }
            break;
        // Add cases for XOR, AND, OR, ADD, SUB
        default:
            // Handle invalid instruction theOpcode
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <opcode_file Name>\n", argv[0]);
        return 1;
    }
    printf("Reading in file: %s\n\r",argv[1]);
    FILE *codeFile = fopen(argv[1], "r");
    if (codeFile == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // Read program code from file (modify for your specific code format)
    char code[1000];
    while (fgets(code, sizeof(code), codeFile) != NULL) {
        // Process each line of code
        int operands[MAX_INSTRUCTION_LENGTH];
        OpcodeType theOpcode = getOpcodeType(code);
        printf("Opcode theOpcode is: %u\n\r",theOpcode);
        int numOperands = parseOperands(code, &operands);

        if (theOpcode != INVALID && numOperands >= 1 && numOperands <= MAX_INSTRUCTION_LENGTH) {
            executeOpcode(theOpcode, operands);
            pc++;  // Increment program counter after successful execution
        } else {
            // Handle invalid instruction or
        }
    }

    /*  Done reading the opcodes, so just dump the registers*/
    for(int reg=0;reg<=REG_COUNT;reg++)
    { printf("Reg[%d]: %d\n\r", reg,regs[reg]); }

}
