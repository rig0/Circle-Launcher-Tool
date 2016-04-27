#include "launchertool.h"
#include "ui_launchertool.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

using namespace std;

string UsrDir = getenv("USERPROFILE");
string CLDir_s = UsrDir + "/Documents/Rainmeter/Skins/Circle Launcher/";
const char* CLDir_cc = CLDir_s.c_str();
void AddApp(const char* appName, const char* appDir);
void AddIni(const char* appName);

LauncherTool::LauncherTool(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LauncherTool)
{
    ui->setupUi(this);
}

LauncherTool::~LauncherTool()
{
    delete ui;
}

void LauncherTool::on_DirBrowseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                tr("Executable (*.exe)"));

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                return;
            }
            QTextStream in(&file);
            ui->DirInputBox->setText(fileName);
            file.close();
        }
}

void LauncherTool::on_IconBrowseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                tr("PNG Image File (*.png)"));

        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                return;
            }
            QTextStream in(&file);
            ui->IconInputBox->setText(fileName);
            file.close();
        }
}

void LauncherTool::on_CreateButton_clicked()
{
    SetCurrentDirectoryA(CLDir_cc);

    QString AppName_qs = ui->NameInputBox->text();
    string AppName_s = AppName_qs.toStdString();
    const char* AppName_cc = AppName_s.c_str();
	
    QString AppDir_qs = ui->DirInputBox->text();
    string AppDir_s = AppDir_qs.toStdString();
    const char* AppDir_cc = AppDir_s.c_str();

    QString AppIcon_qs = ui->IconInputBox->text();
    string AppIcon_s = AppIcon_qs.toStdString();
    const char* AppIcon_cc = AppIcon_s.c_str();
	
	//Check if "NameInputBox" is empty
	if (AppName_s == "") {
		QMessageBox msgBox;
		msgBox.setText("Need to enter a name");
		msgBox.exec();
		return;
	}
	
	//Check if Shortcut Name(NameInputBox)is in Variables.inc
    string VarFile_s = "@Resources/Variables.inc";
    const char* VarFile_cc = VarFile_s.c_str();

	string word;
    string tempVar;
	ifstream infile;
	infile.open(VarFile_cc);
	while (getline(infile, word))
	{
        tempVar = word + "|";
        if (tempVar.find(AppName_cc) != string::npos) {
			QMessageBox msgBox;
			msgBox.setText("That name is already used");
			msgBox.exec();
			return;
		}
	}

    AddApp(AppName_cc ,AppDir_cc);
	
    CreateDirectoryA(AppName_cc,NULL);

    AddIni(AppName_cc);

    string NewIcon_s = CLDir_s + AppName_s + "/" + AppName_s + ".png";
    const char* NewIcon_cc = NewIcon_s.c_str();
    CopyFileA(AppIcon_cc, NewIcon_cc, TRUE);

    QMessageBox msgBox;
      msgBox.setText("All Done!");
      msgBox.exec();
}
void AddApp(const char* appName, const char* appDir)
{
    string VarFile_s = "@Resources/Variables.inc";
    const char* VarFile_cc = VarFile_s.c_str();
    ofstream varinc;
    varinc.open(VarFile_cc, ios::app);
    varinc << appName << "=[\"" << appDir << "\"]" << endl;
    varinc.close();
}

void AddIni(const char* appName)
{
    string IniFile_s = CLDir_s + appName + "/" + appName + ".ini";
    const char* IniFile_cc = IniFile_s.c_str();
    ofstream IniFile;
    IniFile.open(IniFile_cc);
    IniFile << "[Rainmeter]" << endl;
    IniFile << "Update=1000" << endl;
    IniFile << "@include=#@#Variables.inc" << endl;
    IniFile << endl;
    IniFile << "[Image]" << endl;
    IniFile << "Meter=Button" << endl;
    IniFile << "ButtonImage=" << appName << endl;
    IniFile << "X=0" << endl;
    IniFile << "Y=0" << endl;
    IniFile << "LeftMouseUpAction=#" << appName << "#" << endl;
    IniFile.close();
}
