#include "Library.h"
#include <iostream>

Library::Library(const std::string& name)
    : m_name(name), m_count(0)
{
    // 组合类构造函数的执行过程：
    // (1) 先自动调用内嵌对象 m_books 中每个 Book 的构造函数（按声明次序）
    // (2) 再执行本类构造函数的函数体
    std::cout << "  [构造] 图书馆 \"" << m_name << "\" 建立，内嵌 "
              << MAX_BOOKS << " 个图书对象成员先被构造\n";
}

bool Library::addBook(const Book& book)
{
    if (m_count >= MAX_BOOKS)
    {
        std::cout << "  书库已满，添加失败\n";
        return false;
    }
    m_books[m_count++] = book;    // Book 的赋值操作（拷贝）
    std::cout << "  [入库] 《" << book.getName() << "》 添加成功\n";
    return true;
}

bool Library::removeBook(const std::string& name)
{
    int pos = findBook(name);
    if (pos == -1)
    {
        std::cout << "  未找到《" << name << "》，删除失败\n";
        return false;
    }
    // 用后面的元素依次前移覆盖，保持数组紧凑
    for (int i = pos; i < m_count - 1; ++i)
        m_books[i] = m_books[i + 1];
    --m_count;
    std::cout << "  [删除] 《" << name << "》 已从书库中删除\n";
    return true;
}

int Library::findBook(const std::string& name) const
{
    for (int i = 0; i < m_count; ++i)
        if (m_books[i].getName() == name)
            return i;
    return -1;
}

void Library::showAll() const
{
    std::cout << "\n  ===== " << m_name << " 图书清单(" << m_count << "种) =====\n";
    for (int i = 0; i < m_count; ++i)
        m_books[i].display();
    std::cout << "  ================================\n\n";
}
