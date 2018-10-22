#ifndef SCREENCODEAPPLIERMAINWINDOW_H
#define SCREENCODEAPPLIERMAINWINDOW_H

#include <QMainWindow>
#include <QScreen>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>

namespace Ui {
class ScreenCodeApplierMainWindow;
}

class ScreenCodeApplierMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ScreenCodeApplierMainWindow(QWidget *parent = 0);
    ~ScreenCodeApplierMainWindow();

private:
    Ui::ScreenCodeApplierMainWindow *ui;
    QTimer *mytimer;

private slots:
    void updateProgress();

};

#endif // SCREENCODEAPPLIERMAINWINDOW_H
