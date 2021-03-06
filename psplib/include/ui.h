/* psplib/ui.h
   Simple user interface implementation

   Copyright (C) 2007-2008 Akop Karapetyan

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Author contact information: pspdev@akop.org
*/

#ifndef _PSP_UI_H
#define _PSP_UI_H

#include "video.h"
#include "pl_menu.h"
//#include "adhoc.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PspUiMetric
{
  const PspImage *Background;
  const PspFont *Font;
  uint64_t CancelButton;
  uint64_t OkButton;
  int Left;
  int Top;
  int Right;
  int Bottom;
  uint32_t ScrollbarColor;
  uint32_t ScrollbarBgColor;
  int ScrollbarWidth;
  uint32_t TextColor;
  uint32_t SelectedColor;
  uint32_t SelectedBgColor;
  uint32_t StatusBarColor;
  int MenuFps;

  uint32_t DialogFogColor;

  uint32_t BrowserFileColor;
  uint32_t BrowserDirectoryColor;
  uint32_t BrowserScreenshotDelay;
  const char *BrowserScreenshotPath;

  int GalleryIconsPerRow;
  int GalleryIconMarginWidth;

  int MenuItemMargin;
  uint32_t MenuSelOptionBg;
  uint32_t MenuOptionBoxColor;
  uint32_t MenuOptionBoxBg;
  uint32_t MenuDecorColor;

  int TitlePadding;
  uint32_t TitleColor;
  uint32_t TabBgColor;
  int Animate;
} PspUiMetric;

typedef struct PspUiFileBrowser
{
  void (*OnRender)(const void *browser, const void *path);
  int  (*OnOk)(const void *browser, const void *file);
  int  (*OnCancel)(const void *gallery, const void *parent_dir);
  int  (*OnButtonPress)(const struct PspUiFileBrowser* browser,
         const char *selected, uint32_t button_mask);
  const char **Filter;
  void *Userdata;
} PspUiFileBrowser;

typedef struct PspUiMenu
{

  void (*OnRender)(const void *uimenu, const void *item);
  int  (*OnOk)(const void *menu, const void *item);
  int  (*OnCancel)(const void *menu, const void *item);
  int  (*OnButtonPress)(const struct PspUiMenu *menu, pl_menu_item *item,
         uint32_t button_mask);
  int  (*OnItemChanged)(const struct PspUiMenu *menu, pl_menu_item *item,
         const pl_menu_option *option);
  pl_menu Menu;
} PspUiMenu;

typedef struct PspUiGallery
{
  void (*OnRender)(const void *gallery, const void *item);
  int  (*OnOk)(const void *gallery, const void *item);
  int  (*OnCancel)(const void *gallery, const void *item);
  int  (*OnButtonPress)(const struct PspUiGallery *gallery, pl_menu_item* item,
          uint32_t button_mask);
  void *Userdata;
  pl_menu Menu;
} PspUiGallery;

typedef struct PspUiSplash
{
  void (*OnRender)(const void *splash, const void *null);
  int  (*OnCancel)(const void *splash, const void *null);
  int  (*OnButtonPress)(const struct PspUiSplash *splash, uint32_t button_mask);
  const char* (*OnGetStatusBarText)(const struct PspUiSplash *splash);
} PspUiSplash;

#define PSP_UI_YES     2
#define PSP_UI_NO      1
#define PSP_UI_CANCEL  0

#define PSP_UI_CONFIRM 1

char pspUiGetButtonIcon(uint32_t button_mask);

void pspUiOpenBrowser(PspUiFileBrowser *browser, const char *start_path);
void pspUiOpenGallery(PspUiGallery *gallery, const char *title);
void pspUiOpenMenu(PspUiMenu *uimenu, const char *title);
void pspUiSplashScreen(PspUiSplash *splash);

/*int pspUiAdhocHost(const char *name, PspMAC mac);
int pspUiAdhocJoin(PspMAC mac);*/

int  pspUiConfirm(const char *message);
int  pspUiYesNoCancel(const char *message);
void pspUiAlert(const char *message);
void pspUiFlashMessage(const char *message);
const pl_menu_item* pspUiSelect(const char *title, const pl_menu *menu);

void pspUiFadeout();

PspUiMetric UiMetric;

#ifdef __cplusplus
}
#endif

#endif  // _PSP_UI_H
