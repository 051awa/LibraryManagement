#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "Book.h"

// 实验二：学生类（依赖关系的源）
// 依赖关系：Student 的成员函数 borrowBook/returnBook 的参数是 Book 的引用
// 借书成功时学生与图书两个对象的状态都会改变，因此必须传地址（引用）
class Student
{
private:
    std::string m_id;          // 学号
    std::string m_name;        // 姓名
    std::string m_dept;        // 院系
    int         m_maxBorrow;   // 最大可借数量
    int         m_borrowed;    // 当前已借数量

public:
    Student(const std::string& id = "0000", const std::string& name = "无名",
            const std::string& dept = "未知院系", int maxBorrow = 5)
        : m_id(id), m_name(name), m_dept(dept),
          m_maxBorrow(maxBorrow), m_borrowed(0) {}

    // 获取
    std::string getId()   const { return m_id; }
    std::string getName() const { return m_name; }
    int getMaxBorrow() const { return m_maxBorrow; }
    int getBorrowed()  const { return m_borrowed; }
    bool canBorrow()   const { return m_borrowed < m_maxBorrow; }

    void display() const
    {
        std::cout << "  学生 " << m_id << " " << m_name << " (" << m_dept << ")  "
                  << "已借:" << m_borrowed << "/" << m_maxBorrow << "\n";
    }

    // ---------- 依赖关系的体现 ----------
    // 借书：参数是 Book 对象的引用 —— 值传递无法改变图书状态，必须地址传递
    bool borrowBook(Book& book)
    {
        if (!canBorrow())
        {
            std::cout << "  [借书失败] " << m_name
                      << " 已达到最大借书数量 " << m_maxBorrow << " 本\n";
            return false;
        }
        if (!book.borrowOne())
        {
            std::cout << "  [借书失败] 《" << book.getName() << "》 已无可借副本\n";
            return false;
        }
        ++m_borrowed;               // 学生状态改变
        std::cout << "  [借书成功] " << m_name << " 借了《"
                  << book.getName() << "》(剩余可借:" << book.getAvailable() << ")\n";
        return true;                // 图书状态也改变（引用传递的作用）
    }

    // 还书：同样是依赖关系
    bool returnBook(Book& book)
    {
        if (m_borrowed <= 0)
        {
            std::cout << "  [还书失败] " << m_name << " 没有借阅中的图书\n";
            return false;
        }
        book.returnOne();           // 图书状态改变
        --m_borrowed;               // 学生状态改变
        std::cout << "  [还书成功] " << m_name << " 归还了《"
                  << book.getName() << "》(剩余可借:" << book.getAvailable() << ")\n";
        return true;
    }
};

#endif // STUDENT_H
