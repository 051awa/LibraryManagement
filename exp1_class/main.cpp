#include "Book.h"
#include <iostream>
#include <cstdlib>
#include <string>

// 实验一：类的声明在 Book.h，类的定义在 Book.cpp，对象的生成与使用在 main.cpp
// 体现了多文件组织代码的方式
int main()
{
#ifdef _WIN32
    std::system("chcp 65001 > nul");   // 控制台切换到UTF-8，防止中文乱码
#endif
    std::cout << "========== 实验一  类与对象：图书类 ==========\n\n";

    // 1. 使用默认构造函数创建对象
    Book book1;
    std::cout << "[1] 默认构造函数创建的对象：\n";
    book1.display();

    // 2. 使用重载构造函数创建对象（合法数据）
    Book book2("C++面向对象程序设计", "978-7-302-56871-1", "清华大学出版社",
               59.8, 420, true);
    std::cout << "[2] 重载构造函数创建的对象（合法数据）：\n";
    book2.display();
    std::cout << "[2] 该书" << (book2.isThick() ? "是" : "不是") << "厚书(>500页)\n\n";

    // 3. 构造函数的合法性验证（ISBN不合法、价格为负）
    Book book3("数据结构", "abc-def", "机械工业出版社", -5, 350, true);
    std::cout << "[3] 非法数据构造的对象（ISBN与价格被修正为默认值）：\n";
    book3.display();

    // 4. 修改操作与验证
    std::cout << "[4] 修改测试：\n";
    if (book3.setIsbn("9787111115206"))
        std::cout << "    ISBN 修改成功\n";
    else
        std::cout << "    ISBN 修改失败（不合法）\n";

    if (book3.setPrice(45.0))
        std::cout << "    价格修改成功\n";

    if (book3.setPages(0))                       // 页数非法，修改被拒绝
        std::cout << "    页数修改成功\n";
    else
        std::cout << "    页数修改失败（页数必须为正数，修改被拒绝）\n";
    book3.display();

    // 5. 拷贝构造函数
    Book book4(book2);                           // 拷贝构造
    std::cout << "[5] 拷贝构造函数创建的对象 book4：\n";
    book4.display();

    // 6. 修改在馆状态
    book4.setAvailable(false);
    std::cout << "[6] book4 借出后在馆状态："
              << (book4.isAvailable() ? "可借" : "不可借") << "\n";

    return 0;
}
