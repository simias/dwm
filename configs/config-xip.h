/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "e", "c", "w", "s" };

static const unsigned int borderpx  = 2;        /* border pixel of windows */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance    title       tags mask  isfloating   monitor */
	{ "Firefox",      NULL,       NULL,       1 << 7,    0,           -1 },
	{ "mainterm",     NULL,       NULL,       1 << 6,    0,           -1 ,}
	{ "Emacs",        NULL,       NULL,       1 << 5,    0,           -1 },
	{ "SpiderOakONE", NULL,       NULL,       1 << 4,    0,           -1 },
};

#include "configs/common.h"
