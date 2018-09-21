#include "qt_main_window.h"
#include "ui_qt_main_window.h"
#include <QAction>
#include <QMenu>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

qtMainWindow::qtMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qtMainWindow),
    textEditor_(new QTextEdit(this))
{
    ui->setupUi(this);

    initWnd();
}

qtMainWindow::~qtMainWindow()
{
    delete ui;
}

void qtMainWindow::initWnd()
{
    int width = 1200;
    int height = 850;
    resize(width, height);;

    QIcon icon = static_cast<QIcon>("://SIMPLE-TEXT-EDITOR");
    setWindowIcon(icon);

    createActions();
    createStatusBar();

    setCentralWidget(textEditor_);
}

void qtMainWindow::createActions()
{
    QIcon icon = static_cast<QIcon>("://FILE-OPEN");
    QString text(tr("&Open file..."));
    QAction *openFileAct = new QAction(icon, text, this);
    openFileAct->setShortcuts(QKeySequence::Open);
    QString statusTip(tr("Open an existing file."));
    openFileAct->setStatusTip(statusTip);
    connect(openFileAct, &QAction::triggered, this, &qtMainWindow::openFile);

    icon = static_cast<QIcon>("://FILE-SAVE");
    text = tr("&Save file...");
    QAction *saveFileAct= new QAction(icon, text, this);
    saveFileAct->setShortcuts(QKeySequence::Save);
    statusTip = tr("Save a new file.");
    saveFileAct->setStatusTip(statusTip);
    connect(saveFileAct, &QAction::triggered, this, &qtMainWindow::saveFile);

    QString title(tr("&File"));
    QMenu *fileMenu = menuBar()->addMenu(title);
    fileMenu->addAction(openFileAct);
    fileMenu->addAction(saveFileAct);

    QToolBar *toolBar = addToolBar(title);
    toolBar->addAction(openFileAct);
    toolBar->addAction(saveFileAct);
}

void qtMainWindow::createStatusBar()
{
    QString text(tr("Ready"));
    statusBar()->showMessage(text);
}

void qtMainWindow::openFile()
{
    QString caption(tr("Open File"));
    QString dir("/");
    QString filter(tr("Text Files(*.txt)"));
    QString filePath = QFileDialog::getOpenFileName(this, caption, dir, filter);

    if (filePath.isEmpty())
    {
        QString title(tr("File Path"));
        QString text(tr("You did not select a file."));
        QMessageBox::warning(this, title, text);
        return;
    }

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString title(tr("Open File"));
        QString text(tr("Can not open file:\n%1").arg(filePath));
        QMessageBox::warning(this, title, text);

        file.close();
        return;
    }

    QTextStream textStream(&file);
    textEditor_->setText(textStream.readAll());

    file.close();
}

void qtMainWindow::saveFile()
{
    QString caption(tr("Open File"));
    QString dir("/");
    QString filter(tr("Text Files(*.txt)"));
    QString filePath = QFileDialog::getSaveFileName(this, caption, dir, filter);

    if (filePath.isEmpty())
    {
        QString title(tr("File Path"));
        QString text(tr("You did not select a file."));
        QMessageBox::warning(this, title, text);
        return;
    }

    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QString title(tr("Open File"));
        QString text(tr("Can not open file:\n%1").arg(filePath));
        QMessageBox::warning(this, title, text);

        file.close();
        return;
    }

    QTextStream textStream(&file);
    textStream << textEditor_->toPlainText();

    file.close();
}
