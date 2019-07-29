//#define AnaTypeLex	1
//#define AnaTypeSyn	1
#define MAXTOKENLEN	256

typedef union {
	int number;
	char c;			//TO DO 2
	char *str;
} TOKENVAL;

typedef struct {
	int token;
	TOKENVAL tokenVal;
} TERMINAL;

typedef union {
	int intval;
	char charval;
} EXPVALUE;

typedef struct expValue{
	int type;
	EXPVALUE val;
} EXPVAL;

typedef struct idNode{
	char name[MAXTOKENLEN];
	int type;
	EXPVALUE val;
	struct idNode *next;
} IDTABLE;

//TO DO 4
typedef struct fileIndexNode{
	int run_status;
	long file_index;
	struct fileIndexNode *pre, *next;
} WStack;

//词法分析DFA转换表
static int LexTable[11][10]=
   {{   1, 201, 204,   2,   3,   4,   5, 205,   6, 300},
	{ 101, 101, 101, 101, 101, 101, 101, 101, 101, 101},
	{ 102, 102, 202, 203, 102, 102, 102, 102, 102, 102},
	{ 103, 103, 103, 103, 103, 103, 103, 103, 103, 103},
	{ 104, 104, 104, 104, 104,   4, 104, 104, 104, 104},
	{ 105, 105, 105, 105, 105,   5,   5, 105, 105, 105},
	{   7,   7,   7,   7,   7,   7,   7,   7, 300,   8},
	{ 300, 300, 300, 300, 300, 300, 300, 300,  10, 300},
	{   9,   9,   9,   9,   9,   9,   9,   9,   9,   9},
	{ 300, 300, 300, 300, 300, 300, 300, 300,  10, 300},
	{ 106, 106, 106, 106, 106, 300, 300, 106, 300, 300}};
//TO DO 2

//用于词法分析输出，及语法分析
#define ERR			-1
#define SYN_NUM		1		// int整数
#define SYN_ID		2		// id
#define SYN_CHARVAL	3		// char字符				//TO DO 2
#define SYN_LT		11		// <
#define SYN_GT		12		// >
#define SYN_LE		13		// <=
#define SYN_GE		14		// >=
#define SYN_EQ		15		// ==
#define SYN_NE		16		// !=
#define SYN_ADD		17		// +
#define SYN_SUB		18		// -
#define SYN_MUL		19		// *
#define SYN_DIV		20		// /
#define SYN_PAREN_L	21		// (
#define SYN_PAREN_R	22		// )
#define SYN_BRACE_L	23		// {
#define SYN_BRACE_R	24		// }
#define SYN_COMMA	25		// ,
#define SYN_SEMIC	26		// ;
#define SYN_SET		27		// =
#define SYN_AND		51		// &&
#define SYN_OR		52		// ||
#define SYN_NOT		53		// !
#define SYN_TRUE	54		// TRUE
#define SYN_FALSE	55		// FALSE
#define SYN_INT		56		// int
#define SYN_CHAR	57		// char
#define SYN_IF		58		// if
#define SYN_ELSE	59		// else
#define SYN_WHILE	60		// while
#define SYN_SHOW	61		// show
#define SYN_BREAK	62		//break 				//TO DO 4
#define SYN_CONTINUE	63	//continue 				//TO DO 4

//用于符号表中类型
#define ID_FUN		1		// 函数类型
#define ID_INT		2		// int类型
#define ID_CHAR		3		// char类型
