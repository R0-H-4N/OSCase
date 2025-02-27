#ifndef IDT_H
#define IDT_H

#include "types.h"

#define KERNEL_CS 0x08

// Define the IDT gate structure
typedef struct {
    uint16 low_offset;
    uint16 sel;
    uint8 always0;
    uint8 flags;
    uint16 high_offset;
} __attribute__((packed)) idt_gate_t;

// Define the IDT register structure
typedef struct {
    uint16 limit;
    uint32 base;
} __attribute__((packed)) idt_register_t;

// Number of entries in the IDT
#define IDT_ENTRIES 256

// Declare `idt` and `idt_reg` as extern variables
extern idt_gate_t idt[IDT_ENTRIES];
extern idt_register_t idt_reg;

// Functions declared for setting IDT gate and IDT itself
void set_idt_gate(int n, uint32 handler);
void set_idt();

#endif
