#ifndef VERIFY_PAGE_H
#define VERIFY_PAGE_H

#include <QMainWindow>

namespace Ui {
class verify_page;
}

class verify_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit verify_page(QWidget *parent = nullptr);

    ~verify_page();


private slots:
    void on_back_btn_clicked();


    void on_verify_btn_clicked();


    void on_new_code_btn_clicked();

private:
    Ui::verify_page *ui;
    int verify_code;
};

#endif // VERIFY_PAGE_H
