#ifndef SIGNUP_PAGE_H
#define SIGNUP_PAGE_H

#include <QMainWindow>
#include <QSet>
#include <xlsxdocument.h>
using namespace QXlsx;



namespace Ui {
class signup_page;
}

class signup_page : public QMainWindow
{
    Q_OBJECT

public:
    QSet<int> generatedNumbers;
    int captcha_code;

    explicit signup_page(QWidget *parent = nullptr);
    ~signup_page();

    bool check_tekrar(QString username,QString filepath);
    int check_match(QString username,QString password, QString filepath);
    bool user_shart(QString username);
    bool pass_shart(QString password);

    int generateRandomNumber();



private slots:
    void on_captcha_btn_clicked();

    void on_tab_btn1_clicked();

    void on_tab_btn2_clicked();

    void on_show_pass_btn1_clicked();

    void on_hide_pass_btn1_clicked();

    void on_show_pass_btn2_clicked();

    void on_hide_pass_btn2_clicked();

    void on_back_btn_clicked();

    void on_signup_btn_clicked();

   // void on_captcha_line_editingFinished();

    void on_login_btn_clicked();

private:

    Ui::signup_page *ui;
};

#endif // SIGNUP_PAGE_H
