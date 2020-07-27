#include <windows.h>
#include <process.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;
void task1(void *)
{
    while(1)
    {
        clock_t wakeup = clock() + 50;
        while(clock() < wakeup) {}
        Sleep(50);
    }
}

int main(int, char**)
{
    int ThreadNr;
    cout<<"CPU Torture Test.  Press any key to start. \n";
    getch();
    for(int i=0; i < 200; i++) _beginthread( task1, 0, &ThreadNr );
	cout<<"Press any key to stop torture test. \n";
	getch();
    return 0;
}
