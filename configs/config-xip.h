static const unsigned int borderpx  = 2;        /* border pixel of windows */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance    title       tags mask  isfloating   monitor */
	{ "Navigator",             NULL,         NULL,       1 << 7,    0,           0 },
	{ "firefox",               NULL,         NULL,       1 << 7,    0,           0 },
	{ "Bitwarden",             NULL,         NULL,       1 << 3,    0,           0 },
	{ "mainterm",              NULL,         NULL,       1 << 6,    0,           0 },
	{ "Emacs",                 NULL,         NULL,       1 << 1,    0,           1 },
	{ "gvim",                  NULL,         NULL,       1 << 0,    0,           1 },
	{ "Gvim",                  NULL,         NULL,       1 << 0,    0,           1 },
	{ "ProtonMail",            NULL,         NULL,       1 << 4,    0,           0 },
	{ "Thunderbird",           NULL,         NULL,       1 << 5,    0,           0 },
	{ "VirtualBox Machine",    NULL,         NULL,       1 << 1,    0,           0 },
	{ "VirtualBox Manager",    NULL,         NULL,       1 << 1,    0,           0 },
	{ "VirtualBox Manager",    NULL,         NULL,       1 << 1,    0,           0 },
	{ "Telegram",              NULL,         NULL,       1 << 8,    0,           0 },
	{ "Signal",                NULL,         NULL,       1 << 8,    0,           0 },
	{ "Spotify",               NULL,         NULL,       1 << 8,    0,           0 },
};

#include "configs/common.h"
