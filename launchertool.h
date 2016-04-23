#ifndef LAUNCHERTOOL_H
#define LAUNCHERTOOL_H

#include <QMainWindow>

namespace Ui {
class LauncherTool;
}

class LauncherTool : public QMainWindow
{
    Q_OBJECT

public:
    explicit LauncherTool(QWidget *parent = 0);
    ~LauncherTool();

private slots:
    void on_DirBrowseButton_clicked();

    void on_IconBrowseButton_clicked();

    void on_CreateButton_clicked();

private:
    Ui::LauncherTool *ui;
};

#endif // LAUNCHERTOOL_H
