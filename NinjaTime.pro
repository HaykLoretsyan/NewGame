#-------------------------------------------------
#
# Project created by QtCreator 2018-06-01T22:08:49
#
#-------------------------------------------------

QT       += core gui
qtHaveModule(opengl): QT += opengl
QT += sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NinjaTime
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Fight.cpp \
    Mainwindow.cpp \
    SceneManager.cpp \
    PlayerAttributes/Character.cpp \
    PlayerAttributes/Player.cpp \
    NinjaSkills/Skill.cpp \
    NinjaSkills/SkillEffect.cpp \
    Buildings/Boutique.cpp \
    Buildings/SkillAcademy.cpp \
    Buildings/Weaponry.cpp \
    Buildings/Arena.cpp \
    ResourceManager.cpp


HEADERS += \
    Fight.h \
    Mainwindow.h \
    SceneManager.h \
    PlayerAttributes/NinjaCharacteristics.h \
    PlayerAttributes/Character.h \
    PlayerAttributes/Player.h \
    NinjaSkills/Skill.h \
    NinjaSkills/SkillCharacteristics.h \
    NinjaSkills/SkillEffect.h \
    Buildings/Boutique.h \
    Buildings/SkillAcademy.h \
    Buildings/Weaponry.h \
    Buildings/Arena.h \
    ResourceManager.h \
    CustomExceptions.h

FORMS +=
