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

// This class is exported from the dll
class GROUPPROJECT_API CGroupProject {
public:
	CGroupProject(void);
	// TODO: add your methods here.
};

extern GROUPPROJECT_API int nGroupProject;

GROUPPROJECT_API int fnGroupProject(void);

//Declare global custom data type, used to hold a 2d array of ints.
GROUPPROJECT_API int** mazeData;
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

GROUPPROJECT_API void SetMaze(const int** data, int width, int height);

GROUPPROJECT_API int** GetMaze(int& width, int& height);

GROUPPROJECT_API void GetNextPosition(int& xpos, int& ypos);

GROUPPROJECT_API void SetStart(int xpos, int ypos);

GROUPPROJECT_API void GetStart(int& xpos, int& ypos);

GROUPPROJECT_API void SetEnd(int xpos, int ypos);

GROUPPROJECT_API void GetEnd(int& xpos, int& ypos);