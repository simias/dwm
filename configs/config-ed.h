static const unsigned int borderpx  = 1;        /* border pixel of windows */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                   instance    title       tags mask  isfloating   monitor */
	{ "Firefox",               NULL,       NULL,       1 << 7,    0,           0 },
	{ "mainterm",              NULL,       NULL,       1 << 6,    0,           1 },
	{ "Emacs",                 NULL,       NULL,       1 << 6,    0,           0 },
	{ "SpiderOakONE",          NULL,       NULL,       1 << 8,    0,          -1 },
	{ "VirtualBox Machine",    NULL,       NULL,       1 << 1,    0,           1 },
	{ "VirtualBox Manager",    NULL,       NULL,       1 << 1,    0,           2 },
};

#include "configs/common.h"
