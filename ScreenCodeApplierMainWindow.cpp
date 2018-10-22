#include "ScreenCodeApplierMainWindow.h"
#include "ui_ScreenCodeApplierMainWindow.h"

ScreenCodeApplierMainWindow::ScreenCodeApplierMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScreenCodeApplierMainWindow)
{
    ui->setupUi(this);
    mytimer = new QTimer();
    mytimer->setInterval(30);
    connect(mytimer, SIGNAL(timeout()), this, SLOT(updateProgress()));
    mytimer->start();
}

ScreenCodeApplierMainWindow::~ScreenCodeApplierMainWindow()
{
    mytimer->stop();
    delete ui;
}

void ScreenCodeApplierMainWindow::updateProgress()
{
    QScreen *screen = QApplication::primaryScreen();
    QPixmap map = screen->grabWindow(0);
    QGraphicsScene *scene = ui->graphicsView->scene();
    if(scene) delete scene;
    scene = new QGraphicsScene(0, 0, screen->geometry().width(), screen->geometry().height());
    scene->addPixmap(map.copy(1, 24, screen->geometry().width(), screen->geometry().height() - 24));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}
