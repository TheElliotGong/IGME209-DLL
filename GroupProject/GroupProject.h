// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the GROUPPROJECT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// GROUPPROJECT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef GROUPPROJECT_EXPORTS
#define GROUPPROJECT_API __declspec(dllexport)
#else
#define GROUPPROJECT_API __declspec(dllimport)
#endif
/*Authors: Elliot Gong and Michael Xie
* Purpose: Declare functions and variables to be used.
* Restrictions: Must declare the required functions.
* Date: 2/17/2022
*/
// This class is exported from the dll
class GROUPPROJECT_API CGroupProject {
public:
	CGroupProject(void);
	// TODO: add your methods here.
};

extern GROUPPROJECT_API int nGroupProject;

GROUPPROJECT_API int fnGroupProject(void);


//Created a double pointer used to hold the maze data via a 2d array.
GROUPPROJECT_API int** mazeData;
//These int variables hold the maze's width and height, as well as
//the start, end, and current positions.
GROUPPROJECT_API int mazeWidth;
GROUPPROJECT_API int mazeHeight;
GROUPPROJECT_API int startX;
GROUPPROJECT_API int startY;
GROUPPROJECT_API int currentX;
GROUPPROJECT_API int currentY;
GROUPPROJECT_API int endX;
GROUPPROJECT_API int endY;

//Declare GetTeam function.
GROUPPROJECT_API char* GetTeam();
//Declare SetMaze function.
GROUPPROJECT_API bool SetMaze(const int** data, int width, int height);
//Declare GetMaze function.
GROUPPROJECT_API int** GetMaze(int& width, int& height);
//Declare GetNextPosition function.
GROUPPROJECT_API bool GetNextPosition(int& xpos, int& ypos);
//Declare SetStart function.
GROUPPROJECT_API bool SetStart(int xpos, int ypos);
//Declare GetStart function.
GROUPPROJECT_API bool GetStart(int& xpos, int& ypos);
//Declare SetEnd function.
GROUPPROJECT_API bool SetEnd(int xpos, int ypos);
//Declare GetEnd function.
GROUPPROJECT_API bool GetEnd(int& xpos, int& ypos);
