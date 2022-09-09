/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_orange[]      = "#dd8500";
static const char col_green[]       = "#668500";
static const char *colors[][3]      = {
	/*                 fg         bg         border   */
	[SchemeNorm]   = { col_gray3,  col_gray1, col_gray2  },
	[SchemeSel]    = { col_gray4,  col_cyan,  col_orange },
	[SchemeSticky] = { col_gray4,  col_green, col_green },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "s" };

/* layout(s) */
static const float mfact     = 0.66; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      viewmon0,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run",
				  "-H", "/home/lionel/.dmenu-history",
				  "-fn", dmenufont,
				  "-nb", col_gray1,
				  "-nf", col_gray3,
				  "-sb", col_cyan,
				  "-sf", col_gray4,
				  NULL };

static const char *termcmd[]  = { "alacritty", NULL };

#ifndef XK_XF86AudioLowerVolume
# define XK_XF86AudioLowerVolume    0x1008ff11
# define XK_XF86AudioMute           0x1008ff12
# define XK_XF86AudioRaiseVolume    0x1008ff13
#endif

#ifndef XK_XF86MonBrightnessUp
# define XK_XF86MonBrightnessUp     0x1008ff02
# define XK_XF86MonBrightnessDown   0x1008ff03
#endif

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_r,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_b,      banishpointer,  {0} },
	{ MODKEY,                       XK_h,      togglebar,      {0} },
	{ MODKEY,                       XK_n,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_p,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_Left,   setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_Right,  setmfact,       {.f = +0.01} },
	{ MODKEY,                       XK_l,      toggletaglock,  {0} },
	{ MODKEY|ShiftMask,             XK_l,      taglockall,     {0} },
	{ MODKEY|ControlMask,           XK_l,      spawn,          SHCMD("xautolock -locknow") },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_space,  view,           {0} },
	{ MODKEY,                       XK_minus,  togglesticky,   {0} },
	{ MODKEY|ShiftMask,             XK_k,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_Tab,    setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_Tab,    togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_a,      focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_o,      focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_e,      focusbyclass,   {.s = "Gvim" } },
	{ MODKEY,                       XK_w,      focusbyclass,   {.s = "firefox" } },
	{ MODKEY,                       XK_c,      focusbyclass,   {.s = "mainterm" } },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_a,      tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_o,      tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0),
	TAGKEYS(                        XK_2,                      1),
	TAGKEYS(                        XK_3,                      2),
	TAGKEYS(                        XK_4,                      3),
	TAGKEYS(                        XK_5,                      4),
	TAGKEYS(                        XK_6,                      5),
	TAGKEYS(                        XK_7,                      6),
	TAGKEYS(                        XK_8,                      7),
	TAGKEYS(                        XK_s,                      8),

	{ 0,         XK_XF86AudioLowerVolume,      spawn,          SHCMD("volctrl.sh lower") },
	{ 0,         XK_XF86AudioRaiseVolume,      spawn,          SHCMD("volctrl.sh raise") },
	{ 0,         XK_XF86AudioMute,             spawn,          SHCMD("volctrl.sh togglemute") },
	{ 0,         XK_XF86MonBrightnessUp,       spawn,          SHCMD("set-brightness.sh +200") },
	{ 0,         XK_XF86MonBrightnessDown,     spawn,          SHCMD("set-brightness.sh -200") },

	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
