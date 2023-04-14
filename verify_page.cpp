#include "verify_page.h"
#include "signup_page.h"
#include "ui_verify_page.h"
#include "QMessageBox"
#include "QIntValidator"
#include "globals.h"

int verify_code;

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

verify_page::verify_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::verify_page)
{
    ui->setupUi(this);
    ui->verify_line ->setValidator(new QIntValidator());   // ورودی لاین وریفای فقط اینتیجر باشه
    if(tm==0)                                              // تم روشن
    {
        ui->centralwidget->setStyleSheet("background-color: rgb(255, 255, 255);");
    }
    if(tm==1)                                              // تم دارک
    {
        ui->centralwidget->setStyleSheet("background-color: rgb(120, 120, 120);");
    }
    if(lng==0)                                             // زبان انگلیسی
    {
        ui->verify_line->setPlaceholderText("Verify Code");
        ui->verify_btn->setText("Verify");
        ui->back_btn->setText("Back");
    }
    if(lng==1)                                             // زبان فارسی
    {
        ui->verify_line->setPlaceholderText("کد تایید");
        ui->verify_btn->setText("تایید");
        ui->back_btn->setText("عقب");
    }

}

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

verify_page::~verify_page()
{
    delete ui;
}

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void verify_page::on_back_btn_clicked()       // بازگشت به صفحه قبلی و بستن صفحه فعلی
{
    signup_page *sign = new signup_page ;
    sign ->show();
    verify_page::close();
}

void verify_page::on_verify_btn_clicked()     // بررسی وریفای کد و اتمام فاز 1
{
    if(ui->verify_line->text() == QString::number(verify_code))
    {
        (lng == 1) ? QMessageBox::information(this ," " ,"پایان فاز 1 پروژه" , "باشه") : QMessageBox::information(this ,"" ,"End of phase 1 of the project" , "OK");
    verify_page::close();}
    else
    {
        (lng==1) ? QMessageBox::warning(this ," " ,"کد تایید نادرست است" , "باشه") : QMessageBox::warning(this ,"" ,"verify code is incorrect" , "OK");
        on_new_code_btn_clicked();
    }
}

void verify_page::on_new_code_btn_clicked()  // تولید وریفای کد جدید
{
    srand(time(0));                                                                   // تولید عدد رندوم با تابع زمان
    verify_code = rand()%9000+1000;                                                   // مقدار دهی متغیر وریفای کد در بازه 4 رقمی
    (lng == 1) ? QMessageBox::information(this , "کد تایید" , QString::number(verify_code)) : QMessageBox::information(this , "Verify Code" , QString::number(verify_code));    // نمایش وریفای کد در مسج باکس
}
