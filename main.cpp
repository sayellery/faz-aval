#include "start_page.h"
#include <QCoreApplication>
#include <QApplication>

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool lng;        // متغیر گلوبال برای زبان برنامه
bool tm;         // متغیر گلوبال برای تم برنامه

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   start_page start;
    start.show();
    return a.exec();
}
/*
            if(user_shart(username)==0)                                          // بررسی شروط یوزرنیم
               {( lng == 1) ? QMessageBox::warning(this,"نام کاربری", "باید شامل حروف ، اعداد ، یا خط تیره باشد و بین 4 تا 20 کاراکتر باشد")
                            : QMessageBox::warning(this,"Username", " it must contain only letters,numbers and underscore, and be between 4 to 20 characters long.");
               }
            else if(pass_shart(password)==0)                                     // بررسی شروط پسورد
               {( lng == 1) ? QMessageBox::warning(this,"رمز عبور", "باید شامل اعداد یا (! @ # $ * _ ) باشد و بین 4 تا 8 کاراکتر باشد")
                            : QMessageBox::warning(this,"password", " it must contain only numbers and (! @ # $ * _ ), and be between 4 to 8 characters long.");
               }
            else if(user_shart(username)==1 && pass_shart(password)==1)          // شرایط مطلوب

 */
