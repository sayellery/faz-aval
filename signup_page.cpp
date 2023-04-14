#include "signup_page.h"
#include "ui_signup_page.h"
#include "start_page.h"
#include "verify_page.h"
#include "QMessageBox"
#include "QIntValidator"
#include "ctime"
#include "globals.h"

using namespace QXlsx;

int captcha_code;          // متغیر برای کد کپچا

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

signup_page::signup_page(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::signup_page)

{
    ui->setupUi(this);
    ui->captcha_line->setValidator(new QIntValidator());   // ورودی لاین کپچا فقط اینتیجر باشه
    ui->tabWidget->setCurrentIndex(0);                     // پیش فرض تب ثبت نام نمایش داده شود
    ui->show_pass_btn1->hide();                            // مخفی کردن دومین دکمه پسوورد در تب ثبت نام
    ui->show_pass_btn2->hide();                            // مخفی کردن دومین دکمه پسوورد در تب ورود
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
        ui->user_line1->setPlaceholderText("Username");
        ui->user_line2->setPlaceholderText("Username");
        ui->user_line1->setToolTip("Username must contain only letters,numbers and underscore, and be between 4 to 20 characters long.");
        ui->user_line2->setToolTip("Username must contain only letters,numbers and underscore, and be between 4 to 20 characters long.");
        ui->pass_line1->setPlaceholderText("Password");
        ui->pass_line2->setPlaceholderText("Password");
        ui->pass_line1->setToolTip("Password must contain only numbers and (! @ # $ * _ ), and be between 4 to 8 characters long.");
        ui->pass_line2->setToolTip("password must contain only numbers and (! @ # $ * _ ), and be between 4 to 8 characters long.");
        ui->captcha_line->setPlaceholderText("Captcha Code");
        ui->signup_btn->setText("Sign up");
        ui->login_btn->setText("Log in");
        ui->tab_btn1->setText("have an account?");
        ui->tab_btn2->setText("dont have an account?");
        ui->tabWidget->setTabText(0 , "Sign up");
        ui->tabWidget->setTabText(1 , "Log in");
        ui->back_btn->setText("Back");
    }
    if(lng==1)                                             // زبان فارسی
    {
        ui->user_line1->setPlaceholderText("نام کاربری");
        ui->user_line2->setPlaceholderText("نام کاربری");
        ui->user_line1->setToolTip("باید شامل حروف ، اعداد ، یا خط تیره باشد و بین 4 تا 20 کاراکتر باشد");
        ui->user_line2->setToolTip("باید شامل حروف ، اعداد ، یا خط تیره باشد و بین 4 تا 20 کاراکتر باشد");
        ui->pass_line1->setPlaceholderText("رمز عبور");
        ui->pass_line2->setPlaceholderText("رمز عبور");
        ui->pass_line1->setToolTip("رمز عبور باید شامل اعداد یا (! @ # $ * _ ) باشد و بین 4 تا 8 کاراکتر باشد");
        ui->pass_line2->setToolTip("رمز عبور باید شامل اعداد یا (! @ # $ * _ ) باشد و بین 4 تا 8 کاراکتر باشد");
        ui->captcha_line->setPlaceholderText("کد کپچا");
        ui->signup_btn->setText("ثبت نام");
        ui->login_btn->setText("ورود");
        ui->tab_btn1->setText("حساب کاربری دارید؟ (ثبت نام)");
        ui->tab_btn2->setText("(ورود) حساب کاربری ندارید؟");
        ui->tabWidget->setTabText(0 , "ثبت نام");
        ui->tabWidget->setTabText(1 , "ورود");
        ui->back_btn->setText("عقب");
    }
}



// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

signup_page::~signup_page()
{
    delete ui;
}

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void signup_page::on_captcha_btn_clicked()     //تولید کپچا
{
    srand(time(0));                                                                   // تولید عدد رندوم با تابع زمان
    captcha_code = rand()%9000+1000;                                                  // مقدار دهی متغیر کپچا کد در بازه 4 رقمی
    ui->captcha_txt->setText(QString::number(captcha_code));                          // نمایش کد کپچا
}

void signup_page::on_tab_btn1_clicked()        // نمایش تب ورود
{
    ui->tabWidget->setCurrentIndex(1);
}

void signup_page::on_tab_btn2_clicked()        // نمایش تب ثبت نام
{
    ui->tabWidget->setCurrentIndex(0);
}

void signup_page::on_show_pass_btn1_clicked()  // تنظیم پسورد به "نرمال" و نمایش دکمه "هاید" در تب ثبت نام
{
    ui->pass_line1->setEchoMode(QLineEdit::Normal);
    ui->show_pass_btn1->hide();
    ui->hide_pass_btn1->show();
}

void signup_page::on_hide_pass_btn1_clicked()  // تنظیم پسورد به "مخفی" و نمایش دکمه "شو" در تب ثبت نام
{
        ui->pass_line1->setEchoMode(QLineEdit::Password);
        ui->hide_pass_btn1 ->hide();
        ui->show_pass_btn1->show();
}

void signup_page::on_show_pass_btn2_clicked()  // تنظیم پسورد به "نرمال" و نمایش دکمه "هاید" در تب ورود
{
        ui->pass_line2->setEchoMode(QLineEdit::Normal);
        ui->show_pass_btn2->hide();
        ui->hide_pass_btn2->show();
}

void signup_page::on_hide_pass_btn2_clicked()  // تنظیم پسورد به "مخفی" و نمایش دکمه "شو" در تب ورود
{
        ui->pass_line2->setEchoMode(QLineEdit::Password);
        ui->hide_pass_btn2 ->hide();
        ui->show_pass_btn2->show();
}

void signup_page::on_back_btn_clicked()        // بازگشت به صفحه قبلی و بستن صفحه فعلی
{   start_page *start = new start_page;
    start->show() ;
    signup_page::close();
}

bool signup_page::user_shart(QString username) // الگوی مناسب برای یوزرنیم
{
    QRegExp username_ex("^[a-zA-Z0-9_]{4,20}$");
    if (username_ex.exactMatch(username))
        return 1;
    else
        return 0;
}

bool signup_page::pass_shart(QString password) // الگوی مناسب برای پسورد
{
    QRegExp password_ex("^[0-9!@#$*_]{4,8}$"); // الگوی قابل قبول برای پسورد
    if (password_ex.exactMatch(password))

    return 1;
    else
        return 0;
}

bool signup_page::check_tekrar(QString username, QString filepath)                   // بررسی یوزرنیم تکراری
{
    // Open Excel file
    QXlsx::Document xlsx(filepath);

   int row,column;
     column=1;
     for(row=2;1;row++)
       {

         Cell* cell_xl = xlsx.cellAt(row, column);

         if ( cell_xl != NULL )
              {
                  QVariant existingUsername = cell_xl->readValue();

                  if(existingUsername==username)
                    {

                      return 1;
                    }
          }
         else
             return 0;
         }

}

int signup_page::check_match(QString username,QString password, QString filepath)   // بررسی تطابق یوزرنیم و پسورد
{
    // Open Excel file
    QXlsx::Document xlsx(filepath);

   int row;

     for(row=2;1;row++)
       {

         Cell* cell_us = xlsx.cellAt(row, 1);//خواندن یوزر
         Cell* cell_ps = xlsx.cellAt(row, 2);// خواندن رمز

         if ( cell_us != NULL )
              {
                  QVariant existingUsername = cell_us->readValue();
                  QVariant existingpass = cell_ps->readValue();

                  if(existingUsername==username)
                    {
                    if(existingpass==password)
                      return 1;
                    else
                        return 2;// error password
                    }
          }
         else

             return 0;//error username
         }

}

void signup_page::on_signup_btn_clicked()                                           // ثبت نام
{
    QString filePath ="D://user_data.xlsx";

        QXlsx::Document xlsx(filePath); // ساخت یک شیء برای نوشتن در فایل اکسل

       QString captcha_val = ui->captcha_line->text();
       if (! ui->user_line1->text().isEmpty() && ! ui->pass_line1->text().isEmpty())    // بررسی خالی نبودن فیلد ها
       {
           if (captcha_code == captcha_val.toInt())                                     // بررسی درستی کپچا
            {
                QString username = ui->user_line1->text();
                QString password = ui->pass_line1->text();
                if(user_shart(username)==0)                                          // بررسی شروط یوزرنیم
                   {( lng == 1) ? QMessageBox::warning(this,"نام کاربری", "باید شامل حروف ، اعداد ، یا خط تیره باشد و بین 4 تا 20 کاراکتر باشد")
                                : QMessageBox::warning(this,"Username", " it must contain only letters,numbers and underscore, and be between 4 to 20 characters long.");
                    on_captcha_btn_clicked();
                   }
                else if(pass_shart(password)==0)                                     // بررسی شروط پسورد
                   {( lng == 1) ? QMessageBox::warning(this,"رمز عبور", "باید شامل اعداد یا (! @ # $ * _ ) باشد و بین 4 تا 8 کاراکتر باشد")
                                : QMessageBox::warning(this,"password", " it must contain only numbers and (! @ # $ * _ ), and be between 4 to 8 characters long.");
                    on_captcha_btn_clicked();
                   }
                else if(user_shart(username)==1 && pass_shart(password)==1)          // شرایط مطلوب پسورد و یوزرنیم
           {
                QXlsx::CellRange range = xlsx.dimension();
                int lastRow = range.lastRow();

                if (xlsx.dimension().lastRow()<0)
                  {
                     xlsx.write(1, 1, "username");
                     xlsx.write(1, 2, "password");

                     xlsx.write(2, 1, username);
                     xlsx.write(2, 2, password);
                     xlsx.saveAs(filePath);
                     (lng==0) ? QMessageBox::warning(this, "confirmation","information successfully saved") : QMessageBox::warning(this, "تایید","اطلاعات با موفقیت ثبت شد") ;
                     ui->user_line1->clear();
                     ui->pass_line1->clear();
                     ui->captcha_line->clear();
                     ui->tabWidget->setCurrentIndex(1);

                   }
                else {
                     int chk= check_tekrar(username,filePath);
                     if (chk==0)
                        {
                         xlsx.write(lastRow+1, 1, username);
                         xlsx.write(lastRow+1, 2, password);
                         xlsx.saveAs(filePath);
                         QMessageBox::warning(this, "تایید","اطلاعات با موفقیت ثبت شد");
                         ui->user_line1->clear();
                         ui->pass_line1->clear();
                         ui->captcha_line->clear();
                         ui->tabWidget->setCurrentIndex(1);

                     }
                else
                     {
                      (lng==1) ? QMessageBox::critical(this, "خطا", "نام کاربری تکراری است!") : QMessageBox::critical(this, "Error", "This username already exists!");
                         on_captcha_btn_clicked();
                     }
                  }
           }
            }
            else                                                                     // پیغام نادرستی کپچا
           {
               (lng==1) ? QMessageBox::warning(this, "خطا", "کد کپچا نادرست است!") : QMessageBox::warning(this, "Error", "Captcha Code is incorrect!");
                on_captcha_btn_clicked();
           }
       }
            else                                                                     // پیغام پر کردن فیلد ها
                {
                 (lng==1) ? QMessageBox::warning(this, "خطا", "لطفا اطلاعات خود را وارد نمایید!") : QMessageBox::warning(this, "Error", "Please Enter your information!");
            on_captcha_btn_clicked();
                }

 }

void signup_page::on_login_btn_clicked()                                            // ورود
{
    QString username = ui->user_line2->text();
    QString password = ui->pass_line2->text();
    QString filePath ="D://user_data.xlsx";
    int index;
    index =check_match( username,password, filePath);
    if (index ==1)                      // حالت مطلوب
       {
        verify_page *sign_vp = new verify_page ;
        sign_vp ->show();
        signup_page::close();


    }
    else if (index ==0)                 // خطا در نام کاربری
    {
        (lng==1) ? QMessageBox::critical(this, " خطا", "این نام کاربری موجود نمی باشد") : QMessageBox::critical(this, "Error", "This username doesn't exist!");
    }
    else if (index ==2)                 // خطا در رمز عبور
    {
        (lng==1) ? QMessageBox::critical(this, "خطا", "این رمز عبور نادرست است") : QMessageBox::critical(this, "Error", "This password is wrong!");
    }

}
