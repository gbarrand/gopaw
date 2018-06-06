/*
 * This file has been generated by the KUIP compiler.  Do NOT change it!
 *
 * KUIP header: 950303      Generation date: Thu Apr 19 22:18:16 2018
 *
 * Input file: gopawcdf.cdf
 */

#if !defined(F77_LCASE) && !defined(F77_UCASE) && !defined(F77_USCORE)
#  if defined(__EXTENDED__) && !defined(IBM370) && !defined(_IBMR2)
#    define IBM370
#  endif
#  if defined(CRAY) || defined(IBM370) || defined(vms)
#    define F77_UCASE
#  else
#    if ( defined(apollo) || defined(__apollo) ) && defined(APOFTN)
#      define F77_LCASE
#    else
#      define F77_USCORE
#    endif
#  endif
#endif

typedef int     IntFunc();
typedef char*   CharFunc();
typedef char** pCharFunc();
typedef void    SUBROUTINE();
#ifdef IBM370
#  pragma linkage(SUBROUTINE,FORTRAN)
#endif

extern void klnkmenu();
extern void klnkbrcl();
extern void klnkkmcl();
extern void klnkicon();
extern void klnkbutt();

typedef unsigned long KmPixmap; /* Pixmap from <X11/X.h>                   */
 typedef void *KmWidget;         /* Widget from <X11/Intrinsic.h>           */
 typedef void *KmCalldata;       /* XmAnyCallbackStruct from <Motif/Xm.h>   */
                                 /*                                         */
 typedef enum {                  /*                                         */
   BRACT_OPEN = 0,               /*                                         */
   BRACT_ROOT = 1,               /*                                         */
   BRACT_CONT = 2,               /*                                         */
   BRACT_GRAF = 3                /*                                         */
 } BrActTag;                     /*                                         */
                                 /*                                         */
 typedef enum {                  /*                                         */
   BrActUpdate    = 0x01,        /* browser window has to be updated ('!')  */
   BrActSeparator = 0x02,        /* put separator in menu ('/')             */
   BrActToggle    = 0x04,        /* register as toggle button               */
   BrActToggleOn  = 0x08,        /* toggle state is on                      */
   BrActSensitive = 0x10         /* button is sensitive                     */
 } BrActFlag;                    /*                                         */
                                 /*                                         */ 

typedef struct _BrAction {      /*                                         */ 
  struct _BrAction *next;       /* link to next action binding             */ 
  BrActFlag   flags;            /*                                         */ 
  char       *text;             /* text line in menu                       */ 
  char       *user_text;        /* user text overriding CDF text (malloced)*/ 
  char       *accel;            /* accelerator                             */ 
  char       *exec;             /* action commands                         */ 
  SUBROUTINE *call_F;           /* action routine                          */ 
  IntFunc    *call_C;           /* action function                         */ 
  BrActTag    tag;              /* for which window the action is defined  */ 
  struct _BrClass *class;       /* pointer to BrClass in case of open menu */
 } BrAction;                     /*                                         */
                                 /*                                         */
 typedef struct _BrClass {       /*                                         */
   struct _BrClass *next;        /* link to next browsable class            */
   char       *name;             /* unique identifier name                  */
   char       *title;            /* title for popup menu (maybe NULL)       */
   SUBROUTINE *scan_km_F;        /* user function scanning the directory    */
   pCharFunc  *scan_km_C;        /* user function scanning the directory    */
   SUBROUTINE *scan_br_F;        /* user function scanning for browsables   */
   pCharFunc  *scan_br_C;        /* user function scanning for browsables   */
   BrAction   *root;             /* list of actions in root window          */
   BrAction   *open;             /* list of actions in open menu            */
 } BrClass;                      /*                                         */
                                 /*                                         */ 

typedef struct _KmIcon {        /*                                         */ 
  struct _KmIcon *next;         /* link to next icon                       */ 
  char       *name;             /* unique identifier name                  */ 
  int         width;            /* width of the pixmap                     */ 
  int         height;           /* height of the pixmap                    */ 
  char       *bitmap;           /* bitmap data                             */ 
  KmPixmap    pix;              /* filled in Motif part                    */ 
  KmPixmap    hi_pix;           /* high lighted pixmap                     */
 } KmIcon;                       /*                                         */
                                 /*                                         */
 typedef struct _KmClass {       /*                                         */
   struct _KmClass *next;        /* link to next object class               */
   int         is_dir;           /* flag if class has is a directory        */
   char       *name;             /* unique identifier name                  */
   char       *title;            /* title for popup menu (maybe NULL)       */
   char       *big_icon;         /* name of the big icon                    */
   KmIcon     *bicon;            /* pointer to the big icon structure       */
   char       *sm_icon;          /* name of the small icon                  */
   KmIcon     *sicon;            /* pointer to the small icon structure     */
   SUBROUTINE *user_icon_F;      /* user function to return icon bitmap     */
   IntFunc    *user_icon_C;      /* user function to return icon bitmap     */
   BrAction   *cont;             /* list of actions in content window       */
   BrAction   *graf;             /* list of actions in graphics window      */
   int         obj_count;        /* number of objects in content window     */
 } KmClass;                      /*                                         */
                                 /*                                         */ 

typedef enum {                  /*                                         */ 
  KmButtSensitive       = 0x00, /* sensitive button                        */ 
  KmButtNonSensitive    = 0x01, /* non-sensitive button ('NS')             */ 
  KmButtToggleSensitive = 0x02, /* toggle-sensitive button ('TS')          */ 
  KmButtSensitivityMask = 0x03, /* mask for sensitivity type               */ 
  KmButtSeparator       = 0x04, /* put separator in menu ('/')             */ 
  KmButtBrowser         = 0x08  /* button is in main browser ('BR')        */
 } KmButtFlag;                   /*                                         */
                                 /*                                         */
 typedef struct _KmButton {      /*                                         */
   struct _KmButton *next;       /* button label or menu item               */
   char       *menu;             /* menu name or NULL for buttons           */
   char       *label;            /* button label or menu item               */
   SUBROUTINE *call_F;           /* callback routine (FORTRAN)              */
   IntFunc    *call_C;           /* callback routine (C)                    */
   char       *action;           /* name of callback routine                */
   char       *mnemo;            /* button mnemonic                         */
   char       *accel;            /* button accelerator                      */
   char       *accel_text;       /* button accelerator text                 */
   KmButtFlag  flags;            /* sensitivity type etc.                   */
   KmWidget    widget;           /* Motif widget ID                         */
 } KmButton;                     /*                                         */
                                 /*                                         */ 

struct {                        /*                                         */ 
  /* indirect calls to avoid linking HIGZ                                  */ 
  IntFunc    *graf_info_C;      /* pass display, open and close (ixmotif)  */ 
  SUBROUTINE *graf_size_F;      /* resize window (IGRSIZ)                  */ 
  SUBROUTINE *graf_pick_F;      /* identifying graphics objects (IGOBJ)    */ 
  SUBROUTINE *graf_attr_F;      /* set attributes (IGSET)                  */ 
  SUBROUTINE *graf_close_F;     /* close workstation (ICLWK)               */ 
  /* optional routines for Motif customization                             */ 
  pCharFunc  *user_FallBk_C;    /* get application fallbacks               */ 
  IntFunc    *user_TopWid_C;    /* pass toplevel widget identifiers        */
 } klnkaddr;                     /*                                         */ 

typedef enum {                  /*                                         */ 
  KmFLAG_FORGET = 0x01,         /* last value is not kept for Motif panels */ 
  KmFLAG_MINUS  = 0x02,         /* -VALUE is not an abbrev for CHOPT=VALUE */ 
  KmFLAG_QUOTE  = 0x04,         /* do not remove quotes                    */ 
  KmFLAG_VARARG = 0x08,         /* append additional args to this param.   */ 
  KmFLAG_CONST  = 0x10,         /* do not allow to assign a value          */ 
  KmFLAG_HIDDEN = 0x20,         /* do not show in menus                    */ 
  KmFLAG_SEPARATE = 0x40        /* treat arguments as separate tokens      */
 } KmParFlag;                    /*                                         */
                                 /*                                         */
 typedef enum {                  /*                                         */
   KmTYPE_CHAR   = 'C',          /* character string                        */
   KmTYPE_FILE   = 'F',          /* file name                               */
   KmTYPE_INT    = 'I',          /* integer                                 */
   KmTYPE_OPTION = 'O',          /* option                                  */
   KmTYPE_REAL   = 'R'           /* real                                    */
 } KmParType;                    /*                                         */
                                 /*                                         */ 

typedef struct {                /* file name                               */ 
  char         *filter_default; /* filter wildcard                         */ 
  char         *filter_current; /* current filter                          */
 } KmParFile;                    /*                                         */
                                 /*                                         */
 typedef struct {                /*                                         */
   char         *range_lower;    /* lower value of range                    */
   char         *range_upper;    /* upper value of range                    */
   char         *slider_lower;   /* lower limit for slider                  */
   char         *slider_upper;   /* upper limit for slider                  */
   int           decimals;       /* number of decimals used for slider      */
 } KmParInt;                     /*                                         */
                                 /*                                         */
 typedef struct {                /* option                                  */
   char        **text;           /* explanations (parallel to range_value)  */
   int          *mutex;          /* mutex group to which text belongs       */
   int          *radio;          /* radio group to which text belongs       */
 } KmParOption;                  /*                                         */
                                 /*                                         */ 

typedef KmParInt KmParReal;     /* real and int have the same fields       */ 
                                /*                                         */
 typedef struct {                /*                                         */
   char         *name;           /* parameter name                          */
   int           abbrev;         /* minimum length that name is recognized  */
   char         *prompt;         /* prompt string                           */
   char         *dfault;         /* default value                           */
   char         *last;           /* last value for Motif panel (malloced)   */
   int           width;          /* width of input field                    */
   int           range_count;    /* number of items in range_value          */
   char        **range_value;    /* list of allowed values                  */
   int           select_count;   /* number of items in select_count         */
   char        **select_value;   /* list of values for selection box        */
   KmParFlag     flags;          /* special flags                           */
   KmParType     type;           /* parameter type                          */
   void        *ptype;           /* structure pointer selected by type      */
 } KmParameter;                  /*                                         */
                                 /*                                         */ 

typedef struct _KmCommand {     /*                                         */ 
  struct _KmCommand *next;      /* link to next command                    */ 
  char         *path;           /* command path                            */ 
  char         *name;           /* command name                            */ 
  int           hidden;         /* flag if command is invisible            */ 
  int           level;          /* depth of submenus                       */ 
  int           total;          /* total number of parameters              */ 
  int           mandatory;      /* number of mandatory parameters          */ 
  KmParameter **par;            /* list of total parameter descriptions    */ 
  int           list_par;       /* index+1 of parameter taking a list      */ 
  int           xcount;         /* count number of action calls            */ 
  SUBROUTINE   *action_F;       /* action routine                          */ 
  IntFunc      *action_C;       /* action routine                          */ 
  SUBROUTINE   *user_help_F;    /* user help routine                       */ 
  pCharFunc    *user_help_C;    /* user help routine                       */ 
  int          nguidance;       /* number of lines in guidance text        */ 
  char        **guidance;       /* help text                               */ 
  int          nkeyword;        /* number of lines for keywords            */ 
  char        **keyword;        /* list of keywords                        */ 
  int          nhlink;          /* number of lines for links               */ 
  char        **hlink;          /* list of links                           */ 
  int           argc;           /* number of arguments entered             */ 
  char        **argv;           /* argc argument values                    */ 
  char         *argline;        /* argument line as entered                */ 
  int          *argoffs;        /* argc offsets into argline for KUGETE    */
 } KmCommand;                    /*                                         */ 

typedef struct _KmMenu {        /*                                         */ 
  struct _KmMenu *next;         /* link to next menu                       */ 
  struct _KmMenu *down;         /* link to submenu                         */ 
  char         *path;           /* path of parent menu                     */ 
  char         *name;           /* menu name                               */ 
  int           level;          /* depth of submenus                       */ 
  KmCommand    *cmds;           /* link to first command                   */ 
  int          nguidance;       /* number of lines in guidance text        */ 
  char        **guidance;       /* help text                               */ 
  int          nkeyword;        /* number of lines for keywords            */ 
  char        **keyword;        /* list of keywords                        */ 
  int          nhlink;          /* number of lines for links               */ 
  char        **hlink;          /* list of links                           */
 } KmMenu;                       /*                                         */
                                 /*                                         */
 extern void klnkbrcl();         /*                                         */
 extern void klnkicon();         /*                                         */
 extern void klnkkmcl();         /*                                         */
 extern void klnkmenu();         /*                                         */
                                 /*                                         */ 

#ifdef F77_LCASE
#  define gopaw_kuip_def_ gopaw_kuip_def
#endif

#ifdef F77_UCASE
#  define gopaw_kuip_def_ GOPAW_KUIP_DEF
#endif

#ifdef IBM370
#  pragma linkage(GOPAW_KUIP_DEF,FORTRAN)
#endif

extern void gopaw_kuip_def_();

extern int gopaw_kuip();

void gopaw_kuip_def_()
{

static KmParameter _SESSION_PYTHON_FILE = { "FILE", 4, ".py file name",
 (char*)0, (char*)0, 20, 0, (char**)0, 0, (char**)0, (KmParFlag)0,
 KmTYPE_CHAR,  (void*)0 };
static KmParameter *_SESSION_PYTHON_parameters[] = { &_SESSION_PYTHON_FILE };
static char *_SESSION_PYTHON_guidance[] = { "Rename a local file." };
static char *_SESSION_PYTHON_keyword[] = { "Execute", "Python", ".py", "file."
 };
static KmCommand _SESSION_PYTHON = {  (KmCommand*)0, "/SESSION/PYTHON",
 "PYTHON", 0, 1, 1, 1, _SESSION_PYTHON_parameters, 0, 0, (SUBROUTINE*)0,
 gopaw_kuip, (SUBROUTINE*)0, (pCharFunc*)0, 1, _SESSION_PYTHON_guidance, 4,
 _SESSION_PYTHON_keyword, 0, (char**)0, 0, (char**)0, (char*)0, (int*)0 };

static KmParameter _SESSION_MOVE_FROM = { "FROM", 4, "Old file name",
 (char*)0, (char*)0, 20, 0, (char**)0, 0, (char**)0, (KmParFlag)0,
 KmTYPE_CHAR,  (void*)0 };
static KmParameter _SESSION_MOVE_TO = { "TO", 2, "New file name", (char*)0,
 (char*)0, 20, 0, (char**)0, 0, (char**)0, (KmParFlag)0, KmTYPE_CHAR, 
 (void*)0 };
static KmParameter *_SESSION_MOVE_parameters[] = { &_SESSION_MOVE_FROM,
 &_SESSION_MOVE_TO };
static char *_SESSION_MOVE_guidance[] = { "Rename a local file." };
static char *_SESSION_MOVE_keyword[] = { "Rename", "move" };
static KmCommand _SESSION_MOVE = { &_SESSION_PYTHON, "/SESSION/MOVE", "MOVE",
 0, 1, 2, 2, _SESSION_MOVE_parameters, 0, 0, (SUBROUTINE*)0, gopaw_kuip,
 (SUBROUTINE*)0, (pCharFunc*)0, 1, _SESSION_MOVE_guidance, 2,
 _SESSION_MOVE_keyword, 0, (char**)0, 0, (char**)0, (char*)0, (int*)0 };

static char *_SESSION_ELAPSED_guidance[] = {
 "Print elapsed time since last NOW." };
static KmCommand _SESSION_ELAPSED = { &_SESSION_MOVE, "/SESSION/ELAPSED",
 "ELAPSED", 0, 1, 0, 0, (KmParameter**)0, 0, 0, (SUBROUTINE*)0, gopaw_kuip,
 (SUBROUTINE*)0, (pCharFunc*)0, 1, _SESSION_ELAPSED_guidance, 0, (char**)0, 0,
 (char**)0, 0, (char**)0, (char*)0, (int*)0 };

static char *_SESSION_NOW_guidance[] = {
 "Set session inlib::atime to \"now\"." };
static KmCommand _SESSION_NOW = { &_SESSION_ELAPSED, "/SESSION/NOW", "NOW", 0,
 1, 0, 0, (KmParameter**)0, 0, 0, (SUBROUTINE*)0, gopaw_kuip, (SUBROUTINE*)0,
 (pCharFunc*)0, 1, _SESSION_NOW_guidance, 0, (char**)0, 0, (char**)0, 0,
 (char**)0, (char*)0, (int*)0 };

static char *_VIEWER_PAGE_SET_LAYOUT_guidance[] = { "Set layout of the page."
 };
static KmCommand _VIEWER_PAGE_SET_LAYOUT = {  (KmCommand*)0,
 "/VIEWER/PAGE/SET_LAYOUT", "SET_LAYOUT", 0, 2, 0, 0, (KmParameter**)0, 0, 0,
 (SUBROUTINE*)0, gopaw_kuip, (SUBROUTINE*)0, (pCharFunc*)0, 1,
 _VIEWER_PAGE_SET_LAYOUT_guidance, 0, (char**)0, 0, (char**)0, 0, (char**)0,
 (char*)0, (int*)0 };

static char *_VIEWER_PAGE_guidance[] = { "To work on a page." };
static KmMenu _VIEWER_PAGE = {  (KmMenu*)0,  (KmMenu*)0, "/VIEWER/PAGE",
 "PAGE", 2, &_VIEWER_PAGE_SET_LAYOUT, 1, _VIEWER_PAGE_guidance, 0, (char**)0,
 0, (char**)0 };

static char *_VIEWER_SYNCHRONIZE_guidance[] = {
 "Force a graphics synchronization with the server (if any)." };
static KmCommand _VIEWER_SYNCHRONIZE = {  (KmCommand*)0,
 "/VIEWER/SYNCHRONIZE", "SYNCHRONIZE", 0, 1, 0, 0, (KmParameter**)0, 0, 0,
 (SUBROUTINE*)0, gopaw_kuip, (SUBROUTINE*)0, (pCharFunc*)0, 1,
 _VIEWER_SYNCHRONIZE_guidance, 0, (char**)0, 0, (char**)0, 0, (char**)0,
 (char*)0, (int*)0 };

static char *_VIEWER_RENDER_guidance[] = { "Force a redraw." };
static KmCommand _VIEWER_RENDER = { &_VIEWER_SYNCHRONIZE, "/VIEWER/RENDER",
 "RENDER", 0, 1, 0, 0, (KmParameter**)0, 0, 0, (SUBROUTINE*)0, gopaw_kuip,
 (SUBROUTINE*)0, (pCharFunc*)0, 1, _VIEWER_RENDER_guidance, 0, (char**)0, 0,
 (char**)0, 0, (char**)0, (char*)0, (int*)0 };

static char *_VIEWER_guidance[] = { "To work on a viewer widget." };
static KmMenu _VIEWER = {  (KmMenu*)0, &_VIEWER_PAGE, "/VIEWER", "VIEWER", 1,
 &_VIEWER_RENDER, 1, _VIEWER_guidance, 0, (char**)0, 0, (char**)0 };

static char *_SESSION_guidance[] = { "To work on the session." };
static KmMenu _SESSION = { &_VIEWER,  (KmMenu*)0, "/SESSION", "SESSION", 1,
 &_SESSION_NOW, 1, _SESSION_guidance, 0, (char**)0, 0, (char**)0 };

  klnkmenu( &_SESSION, 950303 );
}


