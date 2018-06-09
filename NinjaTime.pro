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
    ResourceManager.cpp \
    NinjaSkills/Skill.cpp \
    NinjaSkills/SkillEffect.cpp \
    Items/Item.cpp \
    Fight/Fight.cpp \
    PlayerAttributes/Character.cpp \
    PlayerAttributes/ItemBag.cpp \
    PlayerAttributes/MoneyBag.cpp \
    PlayerAttributes/Player.cpp \
    Game.cpp \
    Scenes/Arena.cpp \
    Scenes/Boutique.cpp \
    Scenes/SkillAcademy.cpp \
    Scenes/Weaponry.cpp \
    Scenes/Scene.cpp \
    Scenes/Intro.cpp \
    Scenes/City.cpp \
    GameScreen.cpp \
    Items/Weapon.cpp \
    Items/Gear.cpp \
    Items/Supportive.cpp \
    Scenes/BattleField.cpp \
    Fight/FightController.cpp \
    Fight/FightNetworkController.cpp \
    Fight/FightLocalController.cpp \
    Fight/FightAction.cpp \
    Fight/Ninja.cpp \
    Fight/BotController.cpp \
    Fight/AwardManager.cpp

HEADERS += \
    ResourceManager.h \
    CustomExceptions.h \
    NinjaSkills/Skill.h \
    NinjaSkills/SkillCharacteristics.h \
    NinjaSkills/SkillEffect.h \
    Items/Item.h \
    Items/Money.h \
    Fight/Fight.h \
    PlayerAttributes/Character.h \
    PlayerAttributes/ItemBag.h \
    PlayerAttributes/MoneyBag.h \
    PlayerAttributes/NinjaCharacteristics.h \
    PlayerAttributes/Player.h \
    Game.h \
    Scenes/Arena.h \
    Scenes/Boutique.h \
    Scenes/SkillAcademy.h \
    Scenes/Weaponry.h \
    Scenes/Scene.h \
    Scenes/Intro.h \
    Scenes/City.h \
    GameScreen.h \
    Items/Weapon.h \
    Items/Gear.h \
    Items/Supportive.h \
    Scenes/BattleField.h \
    Fight/FightController.h \
    Fight/FightNetworkController.h \
    Fight/FightLocalController.h \
    Fight/FightAction.h \
    Fight/Ninja.h \
    Fight/BotController.h \
    Fight/AwardManager.h \
    Fight/Award.h

FORMS +=

RESOURCES += \
    resources.qrc
