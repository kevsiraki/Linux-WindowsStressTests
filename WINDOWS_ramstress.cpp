#include<windows.h>
#include<stdio.h>
#include<tchar.h>
#include<iostream>
#include<conio.h>

// Use to convert bytes to MB
#define DIV 1048576

// Use to convert bytes to MB
//#define DIV 1024

// Specify the width of the field in which to print the numbers. 
// The asterisk in the format specifier "%*I64d" takes an integer 
// argument and uses it to pad and right justify the number.
# define WIDTH 7

using namespace std;
int main() {
  MEMORYSTATUSEX statex;
  statex.dwLength = sizeof(statex);
  //uncomment the below line to update memory usage prior to the loop
  // GlobalMemoryStatusEx (&statex); 
  //uncomment below to see all memory info prior to the loop
  /*
    printf (TEXT("There is  %*ld percent of memory in use.\n"),WIDTH, statex.dwMemoryLoad);
    printf (TEXT("There are %*I64d total Mbytes of physical memory.\n"),WIDTH,statex.ullTotalPhys/DIV);
    printf (TEXT("There are %*I64d free Mbytes of physical memory.\n"),WIDTH, statex.ullAvailPhys/DIV);
    printf (TEXT("There are %*I64d total Mbytes of paging file.\n"),WIDTH, statex.ullTotalPageFile/DIV);
    printf (TEXT("There are %*I64d free Mbytes of paging file.\n"),WIDTH, statex.ullAvailPageFile/DIV);
    printf (TEXT("There are %*I64d total Mbytes of virtual memory.\n"),WIDTH, statex.ullTotalVirtual/DIV);
    printf (TEXT("There are %*I64d free Mbytes of virtual memory.\n"),WIDTH, statex.ullAvailVirtual/DIV);
    printf (TEXT("There are %*I64d free Mbytes of extended memory.\n"),WIDTH, statex.ullAvailExtendedVirtual/DIV);
  */
  char input = 'c';
  int * a = nullptr;
  int n = 1000;
  cout << "Windows RAM Stress Test. Press Any Key To Begin. \n";
  getch();
  cout << "Filling up RAM.  Do not exit.\n";
  while (true) {
    GlobalMemoryStatusEx( & statex);
    a = new int[n];
    if ((statex.ullAvailPhys / DIV) <= 2000) //alter the stock value of 4000 to change how much physical DRAM you wish to be left available (in MB).
      break;
  }
  cout << "Press any key to end. \n";
  getch();
  delete[] a; //free up used ram
  a = nullptr;
  system("PAUSE");
  return 0;
}
