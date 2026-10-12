#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cctype>

// ---------- 构造函数 ----------
Book::Book()
    : m_name("未命名"), m_isbn("0000000000000"), m_publisher("未知出版社"),
      m_price(0.0), m_pages(0), m_available(false)
{
    // 默认构造函数：将数据成员初始化为一组合理的值
}

Book::Book(const std::string& name, const std::string& isbn,
           const std::string& publisher,
           double price, int pages, bool available)
    : m_name(name), m_publisher(publisher),
      m_price(price), m_pages(pages), m_available(available)
{
    // ISBN 不合法时使用默认值，保证对象始终处于合法状态
    if (isValidIsbn(isbn))
        m_isbn = isbn;
    else
        m_isbn = "0000000000000";
    if (price < 0)  m_price = 0.0;   // 数据成员合法性验证
    if (pages <= 0) m_pages = 0;
}

Book::Book(const Book& other)
    : m_name(other.m_name), m_isbn(other.m_isbn), m_publisher(other.m_publisher),
      m_price(other.m_price), m_pages(other.m_pages), m_available(other.m_available)
{
    // 拷贝构造函数：同类对象之间初始化时被自动调用
}

// ---------- 修改操作（含验证） ----------
bool Book::setName(const std::string& name)
{
    if (name.empty())
        return false;
    m_name = name;
    return true;
}

bool Book::setIsbn(const std::string& isbn)
{
    if (!isValidIsbn(isbn))
        return false;                 // 验证不通过，拒绝修改
    m_isbn = isbn;
    return true;
}

bool Book::setPrice(double price)
{
    if (price < 0)
        return false;
    m_price = price;
    return true;
}

bool Book::setPages(int pages)
{
    if (pages <= 0)
        return false;
    m_pages = pages;
    return true;
}

void Book::setAvailable(bool available)
{
    m_available = available;
}

// ---------- 输出 ----------
void Book::display() const
{
    std::cout << "--------------------------------------\n";
    std::cout << "书名    : " << m_name << "\n";
    std::cout << "ISBN   : " << m_isbn << "\n";
    std::cout << "出版社  : " << m_publisher << "\n";
    std::cout << "价格    : " << std::fixed << std::setprecision(2)
              << m_price << " 元\n";
    std::cout << "页数    : " << m_pages << " 页\n";
    std::cout << "在馆状态: " << (m_available ? "可借" : "不可借") << "\n";
    std::cout << "--------------------------------------\n";
}

// ---------- 其他操作 ----------
// ISBN 合法性：去掉'-'后必须是10位或13位数字
bool Book::isValidIsbn(const std::string& isbn)
{
    int digits = 0;
    for (char c : isbn)
    {
        if (c == '-')
            continue;
        if (!std::isdigit(static_cast<unsigned char>(c)))
            return false;             // 出现非数字字符：不合法
        ++digits;
    }
    return digits == 10 || digits == 13;
}

bool Book::isThick() const
{
    return m_pages > 500;
}
