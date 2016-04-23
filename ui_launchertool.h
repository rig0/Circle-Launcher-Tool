/********************************************************************************
** Form generated from reading UI file 'launchertool.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHERTOOL_H
#define UI_LAUNCHERTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LauncherTool
{
public:
    QWidget *centralWidget;
    QGroupBox *Name_groupBox;
    QLineEdit *NameInputBox;
    QLabel *label;
    QGroupBox *Dir_groupBox_2;
    QLineEdit *DirInputBox;
    QToolButton *DirBrowseButton;
    QGroupBox *icon_groupBox;
    QLineEdit *IconInputBox;
    QToolButton *IconBrowseButton;
    QPushButton *CreateButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LauncherTool)
    {
        if (LauncherTool->objectName().isEmpty())
            LauncherTool->setObjectName(QStringLiteral("LauncherTool"));
        LauncherTool->resize(355, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LauncherTool->sizePolicy().hasHeightForWidth());
        LauncherTool->setSizePolicy(sizePolicy);
        LauncherTool->setMinimumSize(QSize(355, 250));
        LauncherTool->setMaximumSize(QSize(355, 250));
        centralWidget = new QWidget(LauncherTool);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Name_groupBox = new QGroupBox(centralWidget);
        Name_groupBox->setObjectName(QStringLiteral("Name_groupBox"));
        Name_groupBox->setGeometry(QRect(9, 9, 338, 59));
        NameInputBox = new QLineEdit(Name_groupBox);
        NameInputBox->setObjectName(QStringLiteral("NameInputBox"));
        NameInputBox->setGeometry(QRect(10, 20, 141, 20));
        label = new QLabel(Name_groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 20, 171, 16));
        Dir_groupBox_2 = new QGroupBox(centralWidget);
        Dir_groupBox_2->setObjectName(QStringLiteral("Dir_groupBox_2"));
        Dir_groupBox_2->setGeometry(QRect(9, 74, 338, 58));
        DirInputBox = new QLineEdit(Dir_groupBox_2);
        DirInputBox->setObjectName(QStringLiteral("DirInputBox"));
        DirInputBox->setGeometry(QRect(10, 20, 281, 20));
        DirBrowseButton = new QToolButton(Dir_groupBox_2);
        DirBrowseButton->setObjectName(QStringLiteral("DirBrowseButton"));
        DirBrowseButton->setGeometry(QRect(300, 20, 25, 19));
        icon_groupBox = new QGroupBox(centralWidget);
        icon_groupBox->setObjectName(QStringLiteral("icon_groupBox"));
        icon_groupBox->setGeometry(QRect(9, 138, 338, 59));
        IconInputBox = new QLineEdit(icon_groupBox);
        IconInputBox->setObjectName(QStringLiteral("IconInputBox"));
        IconInputBox->setGeometry(QRect(10, 20, 281, 20));
        IconBrowseButton = new QToolButton(icon_groupBox);
        IconBrowseButton->setObjectName(QStringLiteral("IconBrowseButton"));
        IconBrowseButton->setGeometry(QRect(300, 20, 25, 19));
        CreateButton = new QPushButton(centralWidget);
        CreateButton->setObjectName(QStringLiteral("CreateButton"));
        CreateButton->setGeometry(QRect(140, 207, 75, 23));
        sizePolicy.setHeightForWidth(CreateButton->sizePolicy().hasHeightForWidth());
        CreateButton->setSizePolicy(sizePolicy);
        LauncherTool->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LauncherTool);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LauncherTool->setStatusBar(statusBar);

        retranslateUi(LauncherTool);

        QMetaObject::connectSlotsByName(LauncherTool);
    } // setupUi

    void retranslateUi(QMainWindow *LauncherTool)
    {
        LauncherTool->setWindowTitle(QApplication::translate("LauncherTool", "LauncherTool", 0));
        Name_groupBox->setTitle(QApplication::translate("LauncherTool", "Shortcut Name", 0));
        label->setText(QApplication::translate("LauncherTool", "*Something short with no spaces*", 0));
        Dir_groupBox_2->setTitle(QApplication::translate("LauncherTool", "Program Location", 0));
        DirBrowseButton->setText(QApplication::translate("LauncherTool", "...", 0));
        icon_groupBox->setTitle(QApplication::translate("LauncherTool", "Icon", 0));
        IconBrowseButton->setText(QApplication::translate("LauncherTool", "...", 0));
        CreateButton->setText(QApplication::translate("LauncherTool", "Create", 0));
    } // retranslateUi

};

namespace Ui {
    class LauncherTool: public Ui_LauncherTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHERTOOL_H
