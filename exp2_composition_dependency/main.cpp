#include "Book.h"
#include "Student.h"
#include "Library.h"
#include <iostream>
#include <cstdlib>

// 实验二：组合关系（Library has a Book[]） + 依赖关系（Student use a Book&）
int main()
{
/*#ifdef _WIN32
    std::system("chcp 65001 > nul");   // 控制台切换到UTF-8，防止中文乱码
#endif*/
    std::cout << "========== 实验二  组合关系与依赖关系 ==========\n\n";

    // ---------- 一、组合关系的演示 ----------
    std::cout << "--- 1. 组合关系：图书馆类包含图书对象数组 ---\n";
    Library lib("西南科技大学图书馆");

    Book b1("C++面向对象程序设计", "9787302568711", 3);
    Book b2("数据结构(C++语言版)", "9787111115206", 2);
    Book b3("高等数学(第七版)",   "9787040396613", 1);

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);
    lib.showAll();

    lib.removeBook("高等数学(第七版)");
    lib.showAll();

    int pos = lib.findBook("数据结构(C++语言版)");
    if (pos != -1)
        std::cout << "  查询到《数据结构(C++语言版)》在第 " << pos << " 号位置\n\n";

    // ---------- 二、依赖关系的演示 ----------
    std::cout << "--- 2. 依赖关系：学生类的借书/还书函数使用图书对象 ---\n";
    Student stu("20240101", "张三", "计算机学院", 3);
    stu.display();

    // 学生借图书馆里的书：传引用，双方状态同时改变
    Book& target = lib.getBook(0);            // 《C++面向对象程序设计》
    stu.borrowBook(target);                   // 借1本
    stu.borrowBook(target);                   // 再借1本
    stu.borrowBook(target);                   // 借第3本（只剩1本可借，成功后可借为0）
    stu.borrowBook(target);                   // 无副本可借 —— 失败
    stu.display();
    lib.showAll();                            // 图书的可借数量已被改变

    stu.returnBook(target);                   // 还书
    stu.display();
    lib.showAll();

    return 0;
}
