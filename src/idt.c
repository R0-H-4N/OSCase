#include "../include/idt.h"
#include "../include/util.h"

// Define the IDT array and IDT register in one place
idt_gate_t idt[IDT_ENTRIES];  // Definition of the IDT array
idt_register_t idt_reg;        // Definition of the IDT register

// Function to set a specific IDT gate
void set_idt_gate(int n, uint32 handler) {
    idt[n].low_offset = low_16(handler);
    idt[n].sel = KERNEL_CS;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;  // Set flags for present, privilege level, and type
    idt[n].high_offset = high_16(handler);
}

// Function to initialize the IDT
void set_idt() {
    idt_reg.base = (uint32) &idt;  // Set base address of IDT
    idt_reg.limit = IDT_ENTRIES * sizeof(idt_gate_t) - 1;  // Set the limit of the IDT
    __asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));  // Load the IDT using the lidt instruction
}
