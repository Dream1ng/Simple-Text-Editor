#ifndef QT_MAIN_WINDOW_H
#define QT_MAIN_WINDOW_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class qtMainWindow;
}

class qtMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit qtMainWindow(QWidget *parent = 0);
    ~qtMainWindow();

private:
    Ui::qtMainWindow *ui;

private:
    void initWnd();
    void createActions();
    void createStatusBar();

private slots:
    void openFile();
    void saveFile();

private:
    QTextEdit *textEditor_;
};

#endif // QT_MAIN_WINDOW_H
