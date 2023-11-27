set (SRC_NAME "Source Files")
set (INC_NAME "Include Files")
set (UIS_NAME "Form Files")
set (RES_NAME "Resource Files")

set (QML_NAME "QML")

set (QT_GEN_NAME "Generated Files")
set (QT_GUI_NAME "${QT_GEN_NAME}\\\\ui")
set (QT_MOC_NAME "${QT_GEN_NAME}\\\\moc")
set (QT_QRC_NAME "${QT_GEN_NAME}\\\\qrc")

source_group (${RES_NAME} ".*\\.([Qq][Rr][Cc]|[Rr][Cc]2|[Rr][Cc]|[Gg][Ll][Ss][Ll])$")
source_group (${INC_NAME} ".*\\.([Hh]|[Hh][Pp][Pp])$")
source_group (${UIS_NAME} ".*\\.[Uu][Ii]$")
source_group (${SRC_NAME} ".*\\.([Cc]|[Cc][Cc]|[Cc][Pp][Pp]|[Cc][Xx][Xx])$")
source_group (${QT_GUI_NAME} "ui_.*\\.[Hh]$")
source_group (${QT_MOC_NAME} "(.*_automoc|mocs?_.*)\\.[Cc][Pp][Pp]$")
source_group (${QT_QRC_NAME} "qrc_.*\\.[Cc][Pp][Pp]$")
#source_group (${QML_NAME} ".*\\.([QML])")