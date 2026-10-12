#ifndef BOOK_H
#define BOOK_H
#include <string>

// 实验一：图书类的设计
// 数据抽象：图书名称、ISBN、出版社、价格、页数、在馆状态
// 行为抽象：初始化、修改、获取、输出、合法性验证、其他功能
class Book
{
private:                       // 私有数据成员 —— 体现封装
    std::string m_name;        // 图书名称
    std::string m_isbn;        // 图书ISBN号
    std::string m_publisher;   // 出版社
    double      m_price;       // 价格
    int         m_pages;       // 页数
    bool        m_available;   // 在馆状态（true 可借，false 不可借）

public:
    // ---------- 构造函数 ----------
    Book();                                          // 默认构造函数
    Book(const std::string& name, const std::string& isbn,
         const std::string& publisher,
         double price, int pages, bool available);   // 重载构造函数
    Book(const Book& other);                         // 拷贝构造函数（三法则演示）

    // ---------- 基本操作 ----------
    bool setName(const std::string& name);           // 修改（带简单验证）
    bool setIsbn(const std::string& isbn);           // 修改（需通过ISBN验证）
    bool setPrice(double price);                     // 价格必须非负
    bool setPages(int pages);                        // 页数必须为正
    void setAvailable(bool available);               // 修改在馆状态

    std::string getName()      const { return m_name; }      // 获取
    std::string getIsbn()      const { return m_isbn; }
    std::string getPublisher() const { return m_publisher; }
    double      getPrice()     const { return m_price; }
    int         getPages()     const { return m_pages; }
    bool        isAvailable()  const { return m_available; }

    void display() const;                            // 输出图书信息

    // ---------- 其他操作 ----------
    static bool isValidIsbn(const std::string& isbn); // 验证ISBN合法性（13位数字或13位含'-'）
    bool isThick() const;                             // 判断是否为厚书（>500页）
};

#endif // BOOK_H
