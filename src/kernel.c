#include "../include/kb.h"
#include "../include/isr.h"
#include "../include/idt.h"
#include "../include/util.h"
#include "../include/shell.h"
kmain()
{
	int i = 100000000, j = 100000000, k = 100000000, l = 100000000, m = 100000000, n = 100000000;
	isr_install();
	clearScreen();
	print("\n\n\n");
    print("  PPPPP   U   U  L      CCCCC  H   H   OOO   W   W  K   K    \n");
    print("  P   P   U   U  L      C      H   H  O   O  W   W  K  K     \n");
    print("  PPPPP   U   U  L      C      HHHHH  O   O  W W W  KKK      \n");
    print("  P       U   U  L      C      H   H  O   O  W W W  K  K  \n");
    print("  P       UUUUU  LLLLL  CCCCC  H   H   OOO   W   W  K   K     \n");
    print("\n");
    print("                      OOO   SSSSS  \n");
    print("                     O   O  S          \n");
    print("                     O   O  SSSSS   \n");
    print("                     O   O      S       \n");
    print("                      OOO   SSSSS   \n");
	print("\n\n");
	print("  Modified by:\n");
	print("  Prabin Adhikari, Nirajan Sah, Sagar Giri, Rohan Thapa");
	for(; i > 0; i--) {
		for(; j > 0; j--) {
			for(; k > 0; k--) {
				for(; l > 0; l--){
					for(; m > 0; m--) {
						for(; n > 0; n--);
					}
				}
			}
		}
	}
	clearScreen();
    launch_shell(0);    
}
