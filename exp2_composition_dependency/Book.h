#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

// 实验二：图书类（部分类 / 被依赖类）
class Book
{
private:
    std::string m_name;        // 书名
    std::string m_isbn;        // ISBN
    int         m_count;       // 馆藏数量
    int         m_available;   // 当前可借数量

public:
    Book() : m_name("未命名"), m_isbn("0000000000000"), m_count(0), m_available(0) {}
    Book(const std::string& name, const std::string& isbn, int count)
        : m_name(name), m_isbn(isbn), m_count(count), m_available(count) {}

    // 获取
    std::string getName()    const { return m_name; }
    std::string getIsbn()    const { return m_isbn; }
    int getCount()    const { return m_count; }
    int getAvailable() const { return m_available; }

    // 修改
    void setName(const std::string& name) { m_name = name; }
    void addCount(int n) { m_count += n; m_available += n; }   // 增加馆藏

    // 借出一本：可借数量减1（被学生借书时调用）
    bool borrowOne()
    {
        if (m_available <= 0) return false;
        --m_available;
        return true;
    }
    // 归还一本：可借数量加1
    void returnOne()
    {
        if (m_available < m_count) ++m_available;
    }

    void display() const
    {
        std::cout << "  [" << m_isbn << "] 《" << m_name << "》  "
                  << "馆藏:" << m_count << "  可借:" << m_available << "\n";
    }
};

#endif // BOOK_H
