#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <QIcon>
#include <QPixmap>
#include <QPainter>
#include <QColor>
#include <QMessageBox>
#include <QDateTime>
#include <QMenu>
#include <QAction>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , notificationCount(0)
{
    ui->setupUi(this);
    connect(ui->notifyButton, &QPushButton::clicked, this, &MainWindow::onNotifyClicked);

    QScreen *screen = QApplication::primaryScreen();
    QRect sg = screen->availableGeometry();
    move(sg.center().x() - width() / 2, sg.center().y() - height() / 2);

    setupTrayIcon();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    QApplication::quit();
}

void MainWindow::setupTrayIcon()
{
    QPixmap iconPixmap(32, 32);
    iconPixmap.fill(Qt::transparent);
    QPainter painter(&iconPixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColor("#0078d4"));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(2, 2, 28, 28);
    painter.end();

    QIcon appIcon(iconPixmap);
    setWindowIcon(appIcon);

    if (!QSystemTrayIcon::isSystemTrayAvailable())
        return;

    trayIcon = new QSystemTrayIcon(appIcon, this);
    trayIcon->setToolTip("UniDummyapp");

    QMenu *trayMenu = new QMenu(this);
    connect(trayMenu->addAction("Show"), &QAction::triggered, this, &QWidget::show);
    connect(trayMenu->addAction("Quit"), &QAction::triggered, qApp, &QApplication::quit);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::onTrayIconActivated);

    trayIcon->setContextMenu(trayMenu);
    trayIcon->show();
}

void MainWindow::onNotifyClicked()
{

    QString title = "UniDummyapp";
    QString message = QString("Notification #%1 — %2")
                      .arg(notificationCount)
                      .arg(QDateTime::currentDateTime().toString("hh:mm:ss"));

    if (trayIcon && QSystemTrayIcon::isSystemTrayAvailable() && QSystemTrayIcon::supportsMessages())
        trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 4000);
    else
        QMessageBox::information(this, title, message);
}

void MainWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick) {
        show();
        raise();
        activateWindow();
    }
}