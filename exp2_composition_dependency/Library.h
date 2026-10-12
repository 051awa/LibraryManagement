#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include "Book.h"

// 实验二：图书馆类（组合关系的整体类）
// 组合关系：图书馆 has a / contains a 若干图书
// 代码实现：Book 对象数组作为 Library 类的成员变量
const int MAX_BOOKS = 100;

class Library
{
private:
    std::string m_name;        // 图书馆名称（基本类型成员）
    Book  m_books[MAX_BOOKS];  // 图书对象数组（内嵌对象成员 —— 组合关系）
    int   m_count;             // 当前图书种数

public:
    // 组合类构造函数：不仅要初始化本类基本类型成员，
    // 其内嵌的 Book 对象成员也会先被自动构造（调用 Book 的默认构造函数）
    Library(const std::string& name = "图书馆");

    // 添加一种图书
    bool addBook(const Book& book);
    // 按书名删除一种图书
    bool removeBook(const std::string& name);
    // 按书名查找图书（找到返回下标，找不到返回 -1）
    int  findBook(const std::string& name) const;
    // 显示所有图书
    void showAll() const;

    int getCount() const { return m_count; }
    Book& getBook(int index) { return m_books[index]; }
};

#endif // LIBRARY_H
