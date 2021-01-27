; Multilanguage + modernUI instaler
; 
; (c) MitasVit
;
; Testing version


;--------------------------------
; General
!include "MUI2.nsh"
!include "WinMessages.nsh"
;--------------------------------



;--------------------------------
; Configuration
  
  Name "Projectant v.1.0.0"
  OutFile "Projectant_v.1.0.0_Instal_Win.exe"

  ShowInstDetails show
  ;XPStyle on
  Unicode true

  BrandingText "Projectant game v.1.0.0"

  InstallDir "$LOCALAPPDATA\Modern UI Test"
  
  InstallDirRegKey HKCU "Software\Modern UI Test" ""

  RequestExecutionLevel admin

;--------------------------------



;--------------------------------
;Interface Configuration
  
  Icon "C:\Users\Uzivatel\Desktop\logo.ico"
  !define MUI_ICON "C:\Users\Uzivatel\Desktop\logo.ico"
  !define MUI_HEADERIMAGE
  !define MUI_HEADERIMAGE_BITMAP "${NSISDIR}\Contrib\Graphics\Header\orange.bmp" ; optional
  !define MUI_ABORTWARNING

  !define MUI_LANGDLL_ALLLANGUAGES

;--------------------------------



;--------------------------------
;Language Selection Dialog Settings

  ;!define MUI_LANGDLL_REGISTRY_ROOT "HKCU" 
  ;!define MUI_LANGDLL_REGISTRY_KEY "Software\Modern UI Test" 
  ;!define MUI_LANGDLL_REGISTRY_VALUENAME "Installer Language"

;--------------------------------



;--------------------------------
;Pages
  !insertmacro MUI_PAGE_WELCOME
 ; !insertmacro MUI_PAGEDECLARATION_LICENSE "${NSISDIR}\Docs\Modern UI\Lice.txt"
  !insertmacro MUI_PAGE_COMPONENTS
  !insertmacro MUI_PAGE_DIRECTORY
  !insertmacro MUI_PAGE_INSTFILES
  !insertmacro MUI_PAGE_FINISH
  
  !insertmacro MUI_UNPAGE_WELCOME
  !insertmacro MUI_UNPAGE_CONFIRM
  !insertmacro MUI_UNPAGE_COMPONENTS
  !insertmacro MUI_UNPAGE_DIRECTORY
  !insertmacro MUI_UNPAGE_INSTFILES
  !insertmacro MUI_UNPAGE_FINISH
;--------------------------------



;--------------------------------
;Languages
 
  !insertmacro MUI_LANGUAGE "English" ; The first language is the default language
  !insertmacro MUI_LANGUAGE "French"
  !insertmacro MUI_LANGUAGE "German"
  !insertmacro MUI_LANGUAGE "Spanish"
  !insertmacro MUI_LANGUAGE "Italian"
  !insertmacro MUI_LANGUAGE "Dutch"
  !insertmacro MUI_LANGUAGE "Danish"
  !insertmacro MUI_LANGUAGE "Swedish"
  !insertmacro MUI_LANGUAGE "Norwegian"
  !insertmacro MUI_LANGUAGE "Finnish"
  !insertmacro MUI_LANGUAGE "Greek"
  !insertmacro MUI_LANGUAGE "Russian"
  !insertmacro MUI_LANGUAGE "Portuguese"
  !insertmacro MUI_LANGUAGE "Polish"
  !insertmacro MUI_LANGUAGE "Ukrainian"
  !insertmacro MUI_LANGUAGE "Czech"
  !insertmacro MUI_LANGUAGE "Slovak"
  !insertmacro MUI_LANGUAGE "Croatian"
  !insertmacro MUI_LANGUAGE "Bulgarian"
  !insertmacro MUI_LANGUAGE "Hungarian"
  !insertmacro MUI_LANGUAGE "Romanian"
  !insertmacro MUI_LANGUAGE "Latvian"
  !insertmacro MUI_LANGUAGE "Macedonian"
  !insertmacro MUI_LANGUAGE "Estonian"
  !insertmacro MUI_LANGUAGE "Turkish"

;--------------------------------



;--------------------------------
;Reserve Files
  
  ;If you are using solid compression, files that are required before
  ;the actual installation should be stored first in the data block,
  ;because this will make your installer start faster.
  
  !insertmacro MUI_RESERVEFILE_LANGDLL

;--------------------------------



;--------------------------------
;Installer Sections

Section "Sekce 1" SecDummy

  SetOutPath "$INSTDIR"
  
  ;ADD YOUR OWN FILES HERE...
  
  ;Store installation folder
  WriteRegStr HKCU "Software\Modern UI Test" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd

;-----------------------------
;Installer Functions

Function .onInit
  
  Banner::show "Calculating important stuff..."

	Banner::getWindow
	Pop $1

  again:
	IntOp $0 $0 + 1
	Sleep 10
	StrCmp $0 100 0 again

  GetDlgItem $2 $1 1030
  SendMessage $2 ${WM_SETTEXT} 0 "STR:Calculating more important stuff..."

  again2:
	IntOp $0 $0 + 1
	Sleep 10
	StrCmp $0 200 0 again2

  Banner::destroy

  !insertmacro MUI_LANGDLL_DISPLAY
  # the plugins dir is automatically deleted when the installer exits
  InitPluginsDir
  File /oname=$PLUGINSDIR\splash.bmp "${NSISDIR}\Contrib\Graphics\Header\logo.bmp"
  #optional
  #File /oname=$PLUGINSDIR\splash.wav "C:\myprog\sound.wav"
  advsplash::show 1000 600 400 -1 $PLUGINSDIR\splash
  

  
FunctionEnd

;--------------------------------

Section "Sekce2" Sec2

  SetOutPath "$INSTDIR"
  
  ;ADD YOUR OWN FILES HERE...
  
  ;Store installation folder
  WriteRegStr HKCU "Software\Modern UI Test" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd

;---------------------------

Section "Sekce3" Sec3

  SetOutPath "$INSTDIR"
  
  ;ADD YOUR OWN FILES HERE...
  
  ;Store installation folder
  WriteRegStr HKCU "Software\Modern UI Test" "" $INSTDIR
  
  ;Create uninstaller
  WriteUninstaller "$INSTDIR\Uninstall.exe"

SectionEnd

;--------------------------------



;--------------------------------
;Descriptions

  ;Language strings
  ;LangString DESC_SecDummy ${LANG_ENGLISH} "A test section."
  ;LangString DESC_Sec2 ${LANG_ENGLISH} "Sekce 2, testuji."
  ;LangString DESC_Sec3 ${LANG_ENGLISH} "Sekce 3, testuji."

  ;Assign language strings to sections
  !insertmacro MUI_FUNCTION_DESCRIPTION_BEGIN
    !insertmacro MUI_DESCRIPTION_TEXT ${SecDummy} "A test section." 	;$(DESC_SecDummy)
    !insertmacro MUI_DESCRIPTION_TEXT ${Sec2} "Sekce 2, testuji."	;$(DESC_Sec2)
    !insertmacro MUI_DESCRIPTION_TEXT ${Sec3} "Sekce 3, testuji."	;$(DESC_Sec3)
  !insertmacro MUI_FUNCTION_DESCRIPTION_END
 
;--------------------------------



;--------------------------------
;Uninstaller Section

Section "Uninstall"

  ;ADD YOUR OWN FILES HERE...

  Delete "$INSTDIR\Uninstall.exe"

  RMDir "$INSTDIR"

  DeleteRegKey /ifempty HKCU "Software\Modern UI Test"

SectionEnd
;--------------------------------



;--------------------------------
;Uninstaller Functions

Function un.onInit

  !insertmacro MUI_UNGETLANGUAGE
  
FunctionEnd
;--------------------------------