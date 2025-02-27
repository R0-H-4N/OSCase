#include "../include/shell.h"
#define MAX_FILES 20
#define MAX_FILE_NAME_LENGTH 32
#define MAX_FILE_CONTENT_LENGTH 512
#define MAX_CHILD_DIR_SIZE 5
#define MAX_DIR_SIZE 10

typedef struct {
	char name[MAX_FILE_NAME_LENGTH];
	char content[MAX_FILE_CONTENT_LENGTH];
	int exists;
} File;

typedef struct {
	char name[MAX_FILE_NAME_LENGTH];
	File files[MAX_FILES];
	int parent;
	int child[MAX_CHILD_DIR_SIZE];
} Directory;

int availStack[MAX_DIR_SIZE];
int availStackTop = 0;

int currentDir = 0;

Directory directories[MAX_DIR_SIZE];

void launch_shell(int n)
{
	string ch = (string) malloc(200);
	int counter = 0;
	int i;
	print("\nWelcome to Pulchowk OS\n");
	print("Enter command 'help' to list the commands accepted\n");

	currentDir = 0;
	directories[0].parent = -1;
	for(i = 0; i < MAX_FILES; i++) {
		directories[0].files[i].exists = 0;
	}
	for(i = 0; i < MAX_CHILD_DIR_SIZE; i++) {
		directories[0].child[i] = -1;
	}
	directories[0].name[0] = 'r';
	directories[0].name[1] = 'o';
	directories[0].name[2] = 'o';
	directories[0].name[3] = 't';
	directories[0].name[4] = '\0';

	for(i = 0; i < MAX_DIR_SIZE; i++) {
		availStack[i] = i;
	}
	availStackTop = 1;

	do
	{
			print("\nPulChowk $ ");
			printpwd();
			print(" )> ");
			ch = readStr();
			if(strEql(ch,"cmd"))
			{
					print("\nYou are allready in cmd. A new recursive shell is opened\n");
					launch_shell(n+1);
			}
			else if(strEql(ch,"clear"))
			{
					clearScreen();
			}
			else if(strEql(ch,"sum"))
			{
				sum();
			}
			else if(strEql(ch,"exit"))
			{
				print("\nGood Bye!\n");
			}
			else if(strEql(ch,"echo"))
			{
				echo();
			}
			else if(strEql(ch,"sort"))
			{
				sort();
			}
			else if(strEql(ch,"fibonaci"))
			{
				fibonaci();
			}
			else if(strEql(ch,"gcd"))
			{
				gcd();
			}
			else if(strEql(ch,"help"))
			{
				help();
			}
			else if(strEql(ch,"color"))
			{
				set_background_color();
			}
			else if(strEql(ch,"multiply"))
			{
				multiply();
			}
			else if(strEql(ch, "readfile"))
			{
				readfile();
			}
			else if(strEql(ch,"createfile"))
			{
				createfile();
			}
			else if(strEql(ch,"deletefile"))
			{
				deletefile();
			}
			else if(strEql(ch, ""))
			{
				print("\n");
			}
			else if(strEql(ch, "ls"))
			{
				ls();
			}
			else if(strEql(ch, "makedir"))
			{
				makedir();
			}
			else if(strEql(ch, "whereami"))
			{
				print("\n");
				printpwd();
				print("\n");
			}
			else if(strEql(ch, "chdir"))
			{
				chdir();
			}
			else if(strEql(ch, "chparent")) 
			{
				chparent();
			}
			else if(strEql(ch, "removedir")) {
				removedir();
			}
			else
			{
					print("\nBad command!\n");
			} 
	} while (!strEql(ch,"exit"));
}

void sum()
{
	print("\nHow many numbers: ");
	int n = str_to_int(readStr());
	int i =0;
	print("\n");
	int arr[n];
	fill_array(arr,n);
	int s = sum_array(arr,n);
	print("Result: ");
	print(int_to_string(s));
	print("\n");
}
void echo()
{
	print("\n");
	string str = readStr();
	print("\n");
	print(str);
	print("\n");
}
void sort()
{
	int arr[100];
	print("\nArray size: ");
	int n = str_to_int(readStr());
	print("\n");
	fill_array(arr,n);
	print("Before sorting:\n");
	print_array(arr,n);
	print("\nOrdre: (1 for increassing/ 0 for decreassing): ");
	int ordre = str_to_int(readStr());
	insertion_sort(arr,n,ordre);
	print("\nAfter sorting:\n");
	print_array(arr,n);
}

void fill_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		print("ARR[");
		print(int_to_string(i));
		print("]: ");
		arr[i] = str_to_int(readStr());
		print("\n");
	}
}
void print_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		print(int_to_string(arr[i]));
		print("   ");
	}
	print("\n");
}
void insertion_sort(int arr[],int n,int ordre)
{
	int i = 0;
	for (i = 1;i<n;i++)
	{
		int aux = arr[i];
		int j = i;
		while((j > 0) && ((aux < arr[j-1]) && ordre ))
		{
			arr[j] = arr[j-1];
			j = j -1;
		}
		arr[j] = aux;
	}
}
int sum_array(int arr[],int n)
{
	int i = 0;
	int s = 0;
	for (i = 0;i<n;i++)
	{
		s += arr[i];
	}
	return s;
}
void fibonaci()
{
	print("\nHow many Elements: ");
	int n = str_to_int(readStr()); 
	print("\n");
	int i = 0;
	for(i =0;i<n;i++)
	{
		print("Fibo ");
		print(int_to_string(i));
		print(" : ");
		print(int_to_string(fibo(i)));
		print("\n");
	}
	
}
int fibo(int n)
{
	if(n <2)
		return 1;
	else 
		return fibo(n-1) + fibo(n-2);
}
int gcd_couple(int a,int b)
{
	if(b == 0)
		return 1;
	if(a % b ==0) 
		return b;
	else 
		return gcd_couple(b,a % b);
}
void gcd()
{
	print("\nHow many numbers: ");
	int n = str_to_int(readStr());
	int i =0;
	print("\n");
	int arr[n];
	int matrix[n][n];
	fill_array(arr,n);
	for (i = 0;i<n;i++)
	{
		matrix[0][i] = arr[i];
	}
	int j = 0;
	for (i =1;i<n;i++)
	{
		for (j=0;j<n-1;j++)
		{
			matrix[i][j] = gcd_couple(matrix[i-1][j] , matrix[i-1][j+1]);
		}
	}
	print("Result: ");
	print(int_to_string(matrix[n-1][0]));
	print("\n");
}
void print_matrix(int matrix[][100],int rows,int cols)
{
	int i =0;
	int j = 0;
	for (i = 0;i<rows;i++)
	{
		for(j =0;j<cols;j++)
		{
			print(int_to_string(matrix[i][j]));
			print("   ");
		}
		print("\n");
	}
}
void set_background_color()
{
	print("\nColor codes : ");
	print("\n0 : black");
	print_colored("\n1 : blue",1,0);
	print_colored("\n2 : green",2,0);
	print_colored("\n3 : cyan",3,0);
	print_colored("\n4 : red",4,0);
	print_colored("\n5 : purple",5,0);
	print_colored("\n6 : orange",6,0);
	print_colored("\n7 : grey",7,0);
	print_colored("\n8 : dark grey",8,0);
	print_colored("\n9 : blue light",9,0);
	print_colored("\n10 : green light",10,0);
	print_colored("\n11 : blue lighter",11,0);
	print_colored("\n12 : red light",12,0);
	print_colored("\n13 : rose",13,0);
	print_colored("\n14 : yellow",14,0);
	print_colored("\n15 : white",15,0);
	
	print("\n\n Text color ? : ");
	int text_color = str_to_int(readStr());
	print("\n\n Background color ? : ");
	int bg_color = str_to_int(readStr());
	set_screen_color(text_color,bg_color);
	clearScreen();
}

void multiply()
{
	print("\nNum 1 :");
	int num1 = str_to_int(readStr());
	print("\nNum 2 :");
	int num2 = str_to_int(readStr());
	print("\nResult : ");
	print(int_to_string(num1*num2));
	print("\n");
}

void help()
{
	print("\ncmd       	: Launch a new recursive Shell");
	print("\nclear     	: Clears the screen");
	print("\nsum       	: Computes the sum of n numbers");
	print("\necho      	: Reprint a given text");
	print("\nsort      	: Sorts a given n numbers");
	print("\nfibonaci  	: Prints the first n numbers of fibonaci");
	print("\ngcd       	: Computes the grand common divider of n given numbers");
	print("\nexit      	: Quits the current shell");
	print("\ncolor     	: Changes the colors of the terminal");
	print("\ncreatefile	: Create a new file");
	print("\nreadfile   : Read an already created file");
	print("\ndeletefile : Delete an already created file");
	print("\nls         : List all files and directories in the current directory");
	print("\nmakedir    : Create a new directory");
	print("\nwhereami   : Print the current directory path");
	print("\nchdir      : Change to a different directory");
	print("\nchparent   : Change to the parent directory");
	print("\nremovedir  : Remove an empty directory");
	
	print("\n\n");
}

void copy_string(char *dest, const char *src, int max) {
	int i = 0;
	while (src[i] != '\0' && i < max - 1) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void createfile() {
	print("\nEnter file name: ");
	string name_input = readStr();
	
	for (int i = 0; i < MAX_FILES; i++) {
		if (directories[currentDir].files[i].exists && strEql(directories[currentDir].files[i].name, name_input)) {
			print("\nFile already exists.\n");
			return;
		}
	}
	
	int freeSlot = -1;
	for (int i = 0; i < MAX_FILES; i++) {
		if (!directories[currentDir].files[i].exists) {
			freeSlot = i;
			break;
		}
	}
	if (freeSlot == -1) {
		print("\nFile system full.\n");
		return;
	}
	
	copy_string(directories[currentDir].files[freeSlot].name, name_input, MAX_FILE_NAME_LENGTH);
	
	print("\nEnter file content: ");
	string content_input = readStr();
	
	copy_string(directories[currentDir].files[freeSlot].content, content_input, MAX_FILE_CONTENT_LENGTH);
	
	directories[currentDir].files[freeSlot].exists = 1;
	print("\nFile created successfully.");
	print("\n");
}

void readfile() {
	print("\nEnter file name to read: ");
	string name_input = readStr();
	
	int found = 0;
	for (int i = 0; i < MAX_FILES; i++) {
		if (directories[currentDir].files[i].exists && strEql(directories[currentDir].files[i].name, name_input)) {
			print("\nFile content: ");
			print(directories[currentDir].files[i].content);
			found = 1;
			break;
		}
	}
	
	if (!found) {
		print("\nFile not found.");
	}
	print("\n");
}

void deletefile() {
	print("\nEnter file name to delete: ");
	string name_input = readStr();
	int found = 0;

	for (int i = 0; i < MAX_FILES; i++) {
		if (directories[currentDir].files[i].exists && strEql(directories[currentDir].files[i].name, name_input)) {
			directories[currentDir].files[i].exists = 0;

			for (int j = 0; j < MAX_FILE_NAME_LENGTH; j++) {
				directories[currentDir].files[i].name[j] = '\0';
			}

			for (int j = 0; j < MAX_FILE_CONTENT_LENGTH; j++) {
				directories[currentDir].files[i].content[j] = '\0';
			}

			print("\nFile deleted successfully.\n");
			found = 1;
			break;
		}
	}

	if (!found) {
		print("\nFile not found.\n");
	}
}

void ls() {
	print("\nDirectories:\n");
	for (int i = 0; i < MAX_CHILD_DIR_SIZE; i++) {
		if (directories[currentDir].child[i] != -1) {
			print(directories[directories[currentDir].child[i]].name);
			print("\n");
		}
	}

	print("\nFiles:\n");
	for (int i = 0; i < MAX_FILES; i++) {
		if (directories[currentDir].files[i].exists) {
			print(directories[currentDir].files[i].name);
			print("\n");
		}
	}
}

void makedir() {
	print("\nEnter directory name: ");
	string name_input = readStr();

	
	for(int i = 0; i < MAX_CHILD_DIR_SIZE; i++) {
		if(directories[currentDir].child[i] != -1 && strEql(directories[directories[currentDir].child[i]].name, name_input)) {
			print("\nDirectory already exists.\n");
			return;
		}
	}

	int emptyChild = -1;
	for(int i = 0; i < MAX_CHILD_DIR_SIZE; i++) {
		if (directories[currentDir].child[i] == -1) {
			emptyChild = i;
			break;
		} 
	}

	if(emptyChild == -1) {
		print("\nCurrent hierarchy can't support any more directories!");
		return;
	}

	
	if(availStackTop >= MAX_DIR_SIZE) {
		print("\nDirectory system full.\n");
		return;
	}

	int freeSlot = availStack[availStackTop];
	availStackTop++;

	
	copy_string(directories[freeSlot].name, name_input, MAX_FILE_NAME_LENGTH);
	for(int i = 0; i < MAX_FILES; i++) {
		directories[freeSlot].files[i].exists = 0;
	}
	for(int i = 0; i < MAX_CHILD_DIR_SIZE; i++) {
		directories[freeSlot].child[i] = -1;
	}
	directories[freeSlot].parent = currentDir;

	directories[currentDir].child[emptyChild] = freeSlot;
}

void chdir() {
	print("\nEnter directory name: ");
	string name_input = readStr();

	int found = 0;
	for(int i = 0; i < MAX_CHILD_DIR_SIZE; i++) {
		if(directories[currentDir].child[i] != -1 && strEql(directories[directories[currentDir].child[i]].name, name_input)) {
			currentDir = directories[currentDir].child[i];
			found = 1;
			break;
		}
	}

	if(!found) {
		print("\nDirectory not found.\n");
	}
}

void chparent() {
	if (directories[currentDir].parent != -1) {
		currentDir = directories[currentDir].parent;
	}
}

void removedir() {
	print("\nEnter directory name to remove: ");
	string name_input = readStr();

	int found = 0;
	for (int i = 0; i < MAX_CHILD_DIR_SIZE; i++) {
		if (directories[currentDir].child[i] != -1 && strEql(directories[directories[currentDir].child[i]].name, name_input)) {
			int dirIndex = directories[currentDir].child[i];

	
			int isEmpty = 1;
			for (int j = 0; j < MAX_FILES; j++) {
				if (directories[dirIndex].files[j].exists) {
					isEmpty = 0;
					break;
				}
			}
			for (int j = 0; j < MAX_CHILD_DIR_SIZE; j++) {
				if (directories[dirIndex].child[j] != -1) {
					isEmpty = 0;
					break;
				}
			}

			if (isEmpty) {
				directories[currentDir].child[i] = -1;
				availStackTop--;
				availStack[availStackTop] = dirIndex;
				print("\nDirectory removed.\n");
			} else {
				print("\nDirectory is not empty.\n");
			}
			found = 1;
			break;
		}
	}

	if (!found) {
		print("\nDirectory not found.\n");
	}
}

void printpwd() {
	int path[MAX_DIR_SIZE];
	int pathSize = 0;
	int current = currentDir;
	while(current != -1) {
		path[pathSize] = current;
		pathSize++;
		current = directories[current].parent;
	}

	for(int i = pathSize - 1; i >= 0; i--) {
		print(directories[path[i]].name);
		print("/");
	}
}
