#ifndef STRBLOB_CPP
#define STRBLOB_CPP
#include<memory>
#include<vector>
#include<initializer_list>
#include<string>
#include<stdexcept>
class StrBlob{
public:
    /* --------------------------------------- */
    /* StrBlob的size类型 */
    using size_type = std::vector<std::string>::size_type;
    /* --------------------------------------- */
    /* StrBlob的默认构造函数 */
    StrBlob();
    /* --------------------------------------- */
    /* StrBlob的列表构造函数 */
    StrBlob(std::initializer_list<std::string> il);
    /* --------------------------------------- */
    /* 返回StrBlob的size */
    size_type size() const { return data->size(); }
    /* --------------------------------------- */
    /* 若StrBlob为空则返回真 */
    bool empty() const { return data->empty(); }
    /* --------------------------------------- */
    /* 向StrBlob尾部添加一个元素 */
    void push_back(const std::string& t) { data->push_back(t); }
    /* --------------------------------------- */
    /* 弹出StrBlob尾部的元素 */
    void pop_back();
    /* --------------------------------------- */
    /* 返回StrBlob头部元素的引用 */
    std::string& front();
    /* --------------------------------------- */
    /* 返回StrBlob头部元素的引用（const）*/
    const std::string& front() const;
    /* --------------------------------------- */
    /* 返回StrBlob尾部元素的引用 */
    std::string& back();
    /* --------------------------------------- */
    /* 返回StrBlob尾部元素的引用（const） */
    const std::string& back() const;
private:
    /* --------------------------------------- */
    /* StrBlob的存储方式 */
    std::shared_ptr<std::vector<std::string>> data;
    /* --------------------------------------- */
    /* 异常处理 */
    void check(size_type i, const std::string& msg) const;
};

void StrBlob::check(size_type i, const std::string& msg) const{
    if(i >= data->size() )
        throw std::out_of_range(msg);
}

std::string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::back() const{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){}

StrBlob::StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}


#endif